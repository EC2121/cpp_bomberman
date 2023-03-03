#include "player.h"
#include <iostream>
#include "bm-time.h"
#include "SDL.h"
#include "box-collider.h"
#include "resources.h"
#include "player-FSM-include.h"
#include "circle-collider.h"
#include "bomb.h"
#define PLAYER_SPEED 150.f;
#define BOMB_COOLDOWN_IN_MS 1000.f
namespace Actors {
	Player::~Player()
	{
	}
	Player::Player(std::string const& in_path)
		: GameObject(in_path)

	{
		Init();
	}

	Player::Player(std::string const& in_path, const int in_width, const int in_height, const Vector2f in_pos)
		: GameObject(in_path, in_width, in_height, in_pos)
	{
		Init();
	}



	void Player::Attack()
	{
		current_time_of_attack = SDL_GetTicks();
		int pos_x = (position.x + (width / 2)) / 48;
		int pos_y = (position.y + (height / 2)) / 48;
		Actors::Bomb* bomb = new Bomb(Vector2f(pos_x * 48, pos_y * 48));
	}

	bool Player::CheckForMovementInputs()
	{
		velocity = Vector2f::zero;
		auto* keys = SDL_GetKeyboardState(nullptr);
		if (keys[SDL_SCANCODE_D])
		{
			velocity.x = 1;
		}
		else if (keys[SDL_SCANCODE_A])
		{
			velocity.x = -1;
		}
		if (keys[SDL_SCANCODE_W])
		{
			velocity.y = -1;
		}
		else if (keys[SDL_SCANCODE_S])
		{
			velocity.y = 1;
		}
		return velocity.Magnitude() > 0;
	}

	bool Player::CheckForAttackInput() const
	{
		if (SDL_GetTicks() - current_time_of_attack < bomb_cooldown) return false;
		auto* keys = SDL_GetKeyboardState(nullptr);
		if(keys[SDL_SCANCODE_SPACE]) return true;
		return false;
	}

	void Player::Init()
	{
		tag = GOT_PLAYER;
		AttachCollider(std::make_shared<Physics::BoxCollider>(*this, Physics::KINEMATIC));
		speed = PLAYER_SPEED;
		std::shared_ptr<Animations::Animation> walk_anim =
			std::make_shared<Animations::Animation>(*this, Resources::Paths::GetPath("zombie_walk"), 4, 1, 100);
		std::shared_ptr<Animations::Animation> idle_anim =
			std::make_shared<Animations::Animation>(*this, Resources::Paths::GetPath("zombie"), 1, 1, 100);
		std::shared_ptr<Animations::Animation> attack_anim =
			std::make_shared<Animations::Animation>(*this, Resources::Paths::GetPath("zombie_attack"), 1, 1, 100,true,std::bind(&Player::OnAttackAnimEnd,this));
		InsertAnimation("walk", walk_anim); 
		InsertAnimation("idle", idle_anim);
		InsertAnimation("attack", attack_anim);
		ChangeCurrentAnimation("idle");
		bomb_cooldown = BOMB_COOLDOWN_IN_MS;
		current_time_of_attack = 0;
		InsertState(FSM::IDLE, std::make_shared<FSM::PlayerIdleState>());
		InsertState(FSM::WALK, std::make_shared<FSM::PlayerWalkState>());
		InsertState(FSM::ATTACK, std::make_shared<FSM::PlayerAttackState>());
		ChangeCurrentState(*this, FSM::IDLE);
		//states_map[FSM::IDLE] = std::make_shared<FSM::PlayerIdleState>();
		//states_map[FSM::WALK] = std::make_shared<FSM::PlayerWalkState>();
		//states_map[FSM::ATTACK] = std::make_shared<FSM::PlayerAttackState>();
		//curr_state = states_map[FSM::IDLE];


	}


	
	void Player::OnAttackAnimEnd()
	{
		ChangeCurrentState(*this,FSM::IDLE);
		
	}

	void Player::OnCollide(Physics::CollisionInfo in_info)
	{
		velocity = Vector2f::zero;
		position += (in_info.delta / in_info.delta.Magnitude());
	}

	void Player::Update()
	{
		position += velocity * speed * Core::Time::GetDeltatime();
		Animations::IAnimatable::Update();
		GameObject::Update();
		FSM::IStateMachinable::Update(*this);

	}
}

