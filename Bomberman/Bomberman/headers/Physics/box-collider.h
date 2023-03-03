#pragma once
#include "collider.h"


namespace Physics {
	class BoxCollider : public Collider {
	public:
		BoxCollider() = delete;
		BoxCollider(Actors::GameObject& in_owner);
		BoxCollider(Actors::GameObject& in_owner, const ColliderType in_type);
		BoxCollider(Actors::GameObject& in_owner, const Vector2f in_offset, const ColliderType in_type);
		BoxCollider(Actors::GameObject& in_owner, const Vector2f in_pos, const int in_width, const int in_height, const ColliderType in_type);
	
	public:
		virtual bool CheckForCollisions(const Collider& in_other, CollisionInfo& in_info) const override;
		virtual bool CheckForCollisions(const BoxCollider& in_other, CollisionInfo& in_info) const override;
		virtual bool CheckForCollisions(const CircleCollider& in_other, CollisionInfo& in_info) const override;
		void Update() override;



	};

}

