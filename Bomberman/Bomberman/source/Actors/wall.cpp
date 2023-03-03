#include "wall.h"
#include "resources.h"
#include "box-collider.h"
#include "bm-math.h"
#include "game-object.h"
namespace Actors {
	Wall::Wall(const int in_width, const int in_height, const Vector2f in_pos)
		: GameObject(Resources::Paths::GetPath("wall"), in_width, in_height, in_pos)
	{
		tag = GOT_STATIC;
		AttachCollider(std::make_shared<Physics::BoxCollider>(*this, Physics::STATIC));
	}

	void Wall::Update()
	{
		GameObject::Update();
	}
}
