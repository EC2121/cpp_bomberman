#include "circle-collider.h"
#include "physics-mgr.h"
#include "game-object.h"
#include <math.h>
#include "box-collider.h"
namespace Physics {
	CircleCollider::CircleCollider(Actors::GameObject& in_owner)
		: Collider(in_owner)
	{
		id = PhysicsMgr::collider_id++;
		radius = owner.GetWidth() / 2.f;
		position = owner.GetPosition();
		type = STATIC;
	}

	CircleCollider::CircleCollider(Actors::GameObject& in_owner, const ColliderType in_type)
		: CircleCollider(in_owner)
	{
		type = in_type;
	}

	CircleCollider::CircleCollider(Actors::GameObject& in_owner, const Vector2f in_offset, const ColliderType in_type)
		: CircleCollider(in_owner, in_type)
	{
		offset = in_offset;
	}

	bool CircleCollider::CheckForCollisions(const Collider& in_other, CollisionInfo& in_info) const
	{
		return in_other.CheckForCollisions(*this , in_info);
	}

	bool CircleCollider::CheckForCollisions(const BoxCollider& in_other, CollisionInfo& in_info) const
	{
		return in_other.CheckForCollisions(*this, in_info);
	}

	bool CircleCollider::CheckForCollisions(const CircleCollider& in_other, CollisionInfo& in_info) const
	{
		if (powf((in_other.position.x + in_other.radius) - (this->position.x + this->radius), 2.f) +
			powf((in_other.position.y + in_other.radius) - (this->position.y + this->radius), 2.f) <= powf(this->radius + in_other.radius, 2.f))
		{
			return true;
		}
		return false;
	}

	void CircleCollider::Update()
	{
		Collider::Update();
	}
}

