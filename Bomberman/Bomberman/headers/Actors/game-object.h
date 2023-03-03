#pragma once
#include "SDL.h"
#include <memory>
#include <string>
#include "bm-math.h"
#include "animation.h"
#include "state.h"
#include <map>
#include "collision-info.h"
namespace Physics {
	class Collider;
	enum ColliderType;
}

namespace Actors {

	enum GameObjectErrorType
	{
		GOET_NONE,
		GOET_FAILED_TO_READ_IMAGE,
		GOET_FAILED_TO_CREATE_TEXTURE,
		GOET_MAX
	};
	enum GameObjectTag
	{
		GOT_DEFAULT,
		GOT_PLAYER,
		GOT_DESTROYABLE,
		GOT_STATIC
	};

	class GameObject {
	public:
		GameObject();
		GameObject(std::string const& in_path);
		GameObject(std::string const& in_path, const int in_width, const int in_height, const Vector2f in_pos);
		virtual ~GameObject() = default;
	public:
		void AttachCollider(std::shared_ptr<Physics::Collider> in_collider);
		const std::shared_ptr<Physics::Collider>& GetCollider() const { return own_collider; }
		Vector2i GetSize() const { return Vector2i(width, height); }
		int GetWidth() const { return width; }
		int GetHeight() const { return height; }
		int GetId() const { return id; }
		Vector2f GetPosition() const { return position; }
		void ResetVelocity() { velocity = Vector2f::zero; };
		void ChangeSprite(const std::shared_ptr<SDL_Texture*> in_new_texture, const int in_x, const int in_y, const int in_width, const int in_height);
		virtual void OnCollide(Physics::CollisionInfo in_info) {};
		virtual void Draw();
		virtual void Update();
		void Destroy();

	public:
		GameObjectTag tag;
	protected:
		int id;
		int width;
		int height;


		std::shared_ptr<SDL_Rect> dstrect;
		std::shared_ptr<SDL_Rect> srcrect;
		std::shared_ptr<SDL_Texture*> texture;
		std::shared_ptr<Physics::Collider> own_collider;
		GameObjectErrorType error_type = GOET_NONE;
		Vector2f position;
		Vector2f velocity;



	};



}


