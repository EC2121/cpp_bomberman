#include "destroyable-wall.h"
#include "box-collider.h"
#include "resources.h"
namespace Actors {
	DestroyableWall::DestroyableWall(const int in_width, const int in_height, const Vector2f in_pos)
		: GameObject(Resources::Paths::GetPath("wall_destroyable"),in_width,in_height,in_pos)
	{
		tag = GOT_DESTROYABLE;
		AttachCollider(std::make_shared<Physics::BoxCollider>(*this, Physics::STATIC));
	}
	void DestroyableWall::Update()
	{
		GameObject::Update();
	}


}

