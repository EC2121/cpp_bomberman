#pragma once
#include "collider.h"
namespace Physics {
	class CircleCollider : public Collider {
	public:
		CircleCollider() = delete;
		CircleCollider(Actors::GameObject& in_owner);
		CircleCollider(Actors::GameObject& in_owner, const ColliderType in_type);
		CircleCollider(Actors::GameObject& in_owner, const Vector2f in_offset, const ColliderType in_type);

	public:
		virtual bool CheckForCollisions(const Collider& in_other, CollisionInfo& in_info) const override;
		virtual bool CheckForCollisions(const BoxCollider& in_other, CollisionInfo& in_info) const override;
		virtual bool CheckForCollisions(const CircleCollider& in_other, CollisionInfo& in_info) const override;
		void Update() override;
	public:
		float radius;
	};
}