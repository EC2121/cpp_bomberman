#include "physics-mgr.h"
#include "box-collider.h"
#include "game-object.h"
#include "collider.h"
#include "bm-math.h"
namespace Physics {

	std::vector<std::weak_ptr<Collider>> PhysicsMgr::colliders_in_scene;
	std::unique_ptr<PhysicsMgr> PhysicsMgr::instance(nullptr);
	int PhysicsMgr::collider_id = 0;
	PhysicsMgr::~PhysicsMgr()
	{
	}

	PhysicsMgr::PhysicsMgr()
	{
	}

	void PhysicsMgr::Update()
	{
		CollisionInfo info;
		for (size_t i = 0; i < colliders_in_scene.size(); i++)
		{
			if (colliders_in_scene[i].expired()) continue;
			if (colliders_in_scene[i].lock()->type == STATIC) continue;
			for (size_t j = 0; j < colliders_in_scene.size(); j++)
			{
				if (colliders_in_scene[j].expired()) continue;
				if (colliders_in_scene[i].lock() == colliders_in_scene[j].lock() || colliders_in_scene[j].lock()->type != STATIC) continue;
				if (colliders_in_scene[i].lock()->CheckForCollisions(*colliders_in_scene[j].lock(), info))
				{
					colliders_in_scene[i].lock()->owner.OnCollide(info);
				}
			}

		}
	}

	bool PhysicsMgr::BoxOverlap(const Vector2f in_at_pos, const int in_width, const int in_height)
	{
		Actors::GameObject temp_go = Actors::GameObject();
		BoxCollider temp = BoxCollider(temp_go, STATIC);
		temp.position = in_at_pos;
		temp.width = in_width;
		temp.heigth = in_height;
		CollisionInfo info;

		return false;


	}

	bool PhysicsMgr::BoxOverlap(const Vector2f in_at_pos, const int in_width, const int in_height, std::vector<Actors::GameObject*>& in_collided_with, const Actors::GameObjectTag in_filter)
	{
		Actors::GameObject* temp_go = new Actors::GameObject();
		std::shared_ptr<BoxCollider> temp_box_collide = std::make_shared<BoxCollider>(*temp_go, STATIC);
		temp_box_collide->position = in_at_pos;
		temp_box_collide->width = in_width;
		temp_box_collide->heigth = in_height;
		std::cout << "x: " << temp_box_collide->position.x << " y: " << temp_box_collide->position.y << std::endl;
		CollisionInfo info;

		for (std::weak_ptr<Collider>& collider : colliders_in_scene)
		{
			if (temp_box_collide == collider.lock()) continue;
			if (collider.lock()->owner.tag != in_filter) continue;
			if (temp_box_collide->CheckForCollisions(*collider.lock(), info))
			{
				in_collided_with.push_back(&collider.lock()->owner);
			}
		}
		temp_go->Destroy();
		return in_collided_with.size() > 0;
	}

	bool PhysicsMgr::CrossBoxOverlap(const Vector2f in_at_pos, const int in_width, const int in_height, std::vector<Actors::GameObject*>& in_collided_with, const Actors::GameObjectTag in_filter)
	{
		std::shared_ptr<Actors::GameObject> temp_go = std::make_shared<Actors::GameObject>();
		std::vector<std::shared_ptr<Collider>> temp_arr;
		temp_arr.push_back(std::make_shared<BoxCollider>(*temp_go,
			Vector2f(in_at_pos.x, in_at_pos.y + 48), in_width, in_height, STATIC));

		temp_arr.push_back(std::make_shared<BoxCollider>(*temp_go,
			Vector2f(in_at_pos.x, in_at_pos.y - 48), in_width, in_height, STATIC));

		temp_arr.push_back(std::make_shared<BoxCollider>(*temp_go,
			Vector2f(in_at_pos.x + 48, in_at_pos.y), in_width, in_height, STATIC));

		temp_arr.push_back(std::make_shared<BoxCollider>(*temp_go,
			Vector2f(in_at_pos.x - 48, in_at_pos.y), in_width, in_height, STATIC));

		CollisionInfo info;
		for (std::shared_ptr<Collider>& collider : temp_arr)
		{
			for (std::weak_ptr<Collider>& collider_in_scene : colliders_in_scene)
			{
				if (collider == collider_in_scene.lock()) continue;
				if (collider_in_scene.lock()->owner.tag != in_filter) continue;
				if (collider->CheckForCollisions(*collider_in_scene.lock(), info))
				{
					in_collided_with.push_back(&collider_in_scene.lock()->owner);
				}
			}
		}

		temp_go->Destroy();
		temp_go.reset();
		return in_collided_with.size() > 0;
	}

	void PhysicsMgr::SubscribeToPhysicsMgr(std::shared_ptr<Collider> in_collider)
	{
		colliders_in_scene.push_back(std::shared_ptr<Collider>(in_collider));
	}



	PhysicsMgr& PhysicsMgr::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = std::unique_ptr<PhysicsMgr>(new PhysicsMgr());
		}
		return *instance;

	}
}

