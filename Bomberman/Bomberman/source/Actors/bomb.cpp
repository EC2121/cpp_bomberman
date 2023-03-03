#include "bomb.h"
#include "game.h"
#include "resources.h"
#include "physics-mgr.h"
#include "collider.h"
#include <iostream>

namespace Actors {
	Bomb::~Bomb()
	{
	}
	Bomb::Bomb(const Vector2f in_pos)
		: GameObject(Resources::Paths::GetPath("bomb_explosion"), 100, 100, in_pos)
	{
		InsertAnimation("bomb", std::make_shared<Animations::Animation>(*this, Resources::Paths::GetPath("bomb_explosion"), 23, 1, 50, true,std::bind(&Bomb::OnBombExplosion,this)));
		ChangeCurrentAnimation("bomb");
		AttachCollider(std::make_shared<Physics::BoxCollider>(*this, Physics::KINEMATIC));
		//Offset to be centered on the tile
		position.x -= 25;
		position.y -= 25;
	}


	void Bomb::Update()
	{
		GameObject::Update();
		IAnimatable::Update();
	}

	void Bomb::OnBombExplosion()
	{
		std::vector<GameObject*> collided_with;

		Physics::PhysicsMgr::CrossBoxOverlap(Vector2f(position.x + 25, position.y + 25),
			48, 48, collided_with, GOT_DESTROYABLE);
		
		for (GameObject*& game_object : collided_with)
		{
			game_object->Destroy();
		}

		Destroy();
	}

}
