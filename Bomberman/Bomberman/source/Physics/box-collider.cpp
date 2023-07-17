#include "physics-mgr.h"
#include "game-object.h"
#include "box-collider.h"
#include "circle-collider.h"
#include <math.h>
namespace Physics {
	BoxCollider::BoxCollider(Actors::GameObject& in_owner)
		: Collider(in_owner)

	{

		id = PhysicsMgr::collider_id++;
		width = owner.GetWidth();
		heigth = owner.GetHeight();
		position = owner.GetPosition();
		type = STATIC;

	}

	BoxCollider::BoxCollider(Actors::GameObject& in_owner, const ColliderType in_type)
		:BoxCollider(in_owner)
	{
		type = in_type;
	}

	BoxCollider::BoxCollider(Actors::GameObject& in_owner, const Vector2f in_offset, const ColliderType in_type)
		: BoxCollider(in_owner, in_type)
	{
		offset = in_offset;
	}

	BoxCollider::BoxCollider(Actors::GameObject& in_owner, const Vector2f in_pos, const int in_width, const int in_height, const ColliderType in_type)
		:BoxCollider(in_owner, in_type)
	{
		width = in_width;
		heigth = in_height;
		position = in_pos;
	}

	bool BoxCollider::CheckForCollisions(const Collider& in_other, CollisionInfo& in_info) const
	{
		return in_other.CheckForCollisions(*this, in_info);
	}

	bool BoxCollider::CheckForCollisions(const BoxCollider& in_other, CollisionInfo& in_info) const
	{

		if (
			position.x < in_other.position.x + in_other.width &&
			position.x + width > in_other.position.x &&
			position.y < in_other.position.y + in_other.heigth &&
			heigth + position.y > in_other.position.y
			)
		{
			in_info.delta = Vector2f(0, 0);
			float delta_x = (in_other.position.x + (in_other.width / 2)) - (this->position.x + (this->width / 2));
			float delta_y = (in_other.position.y + (in_other.heigth / 2)) - (this->position.y + (this->heigth / 2));
			if (abs(delta_x) > abs(delta_y))
			{
				in_info.delta.x = delta_x;
			}
			else if (abs(delta_x) < abs(delta_y))
			{
				in_info.delta.y = delta_y;
			}
			else
			{
				in_info.delta.x = delta_x;
				in_info.delta.y = delta_y;
			}
			return true;
		}
		return false;
	}

	bool BoxCollider::CheckForCollisions(const CircleCollider& in_other, CollisionInfo& in_info) const
	{
		return false;
	}

	void BoxCollider::Update()
	{
		Collider::Update();
	}



}


