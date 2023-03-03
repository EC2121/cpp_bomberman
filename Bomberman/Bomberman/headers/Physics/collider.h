#pragma once
#include <memory>
#include "bm-math.h"
#include "game-object.h"
#include "collision-info.h"
namespace Physics {
	enum ColliderType
	{
		STATIC,
		KINEMATIC
	};
	class BoxCollider;
	class CircleCollider;
	class Collider {
	public:

		~Collider();
		Collider(const Collider&) = default;
		Collider& operator =(const Collider&) = default;
		Collider(Actors::GameObject& in_owner)
			: owner(in_owner)
			, position(Vector2f::zero)
			, width(0)
			, heigth(0)
			, offset(Vector2f())
			, type(STATIC)
			, id(0)
		{};
	protected:

	public:
		virtual void Destroy(int id);
		virtual bool CheckForCollisions(const Collider& in_other, struct CollisionInfo& in_info) const = 0;
		virtual bool CheckForCollisions(const BoxCollider& in_other, struct CollisionInfo& in_info)const  = 0;
		virtual bool CheckForCollisions(const CircleCollider& in_other, struct CollisionInfo& in_info)const = 0;
		virtual void Update();
		int GetId() const { return id; }
	protected:
		int id;
	public:
		Actors::GameObject& owner;
		ColliderType type;
		Vector2f position;
		int width;
		int heigth;
		Vector2f offset;

	};
}