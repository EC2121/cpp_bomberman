#pragma once
#include <memory>
#include <vector>
#include "bm-math.h"
#include "box-collider.h"
namespace Physics {
	class PhysicsMgr {
	public:
		PhysicsMgr(const PhysicsMgr&) = default;
		PhysicsMgr& operator=(const PhysicsMgr&) = default;
		~PhysicsMgr();
	protected:
		PhysicsMgr();

	public:
		void Update();
		static bool BoxOverlap(const Vector2f in_at_pos, const int in_width, const int in_height);
		static bool BoxOverlap(const Vector2f in_at_pos,const int in_width, const int in_height,
			std::vector<Actors::GameObject*>& in_collided_with,const Actors::GameObjectTag in_filter);
		static bool CrossBoxOverlap(const Vector2f in_at_pos,const int in_width, const int in_height, std::vector<Actors::GameObject*>& in_collided_with, const Actors::GameObjectTag in_filter);
		static void SubscribeToPhysicsMgr(std::shared_ptr<Collider> in_collider);
		static PhysicsMgr& GetInstance();
		static std::vector<std::weak_ptr<Collider>> colliders_in_scene;
		static int collider_id;
	private:
		static std::unique_ptr<PhysicsMgr> instance;
	};
}