#pragma once
#include "game-object.h"
#include "bm-math.h"
#include "IAnimatable.h"
#include "IStateMachinable.h"
namespace Actors {

	class Player : public GameObject, public Animations::IAnimatable, public FSM::IStateMachinable {


	public:
		Player() = delete;
		virtual ~Player() override;
		Player(std::string const& in_path);
		Player(std::string const& in_path, const int in_width, const int in_height, const Vector2f in_pos);
		Player(const Player&) = default;
		Player& operator=(const Player&) = delete;

	public:
		void Attack();
		bool CheckForMovementInputs();
		bool CheckForAttackInput() const;
		void Init();
		void OnAttackAnimEnd();
		void OnCollide(Physics::CollisionInfo in_info) override;
		void Update() override;


	protected:
		float bomb_cooldown;
		Uint32 current_time_of_attack;
		float speed;
	};
}