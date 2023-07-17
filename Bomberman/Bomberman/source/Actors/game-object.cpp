#include "game-object.h"
#include "physics-mgr.h"
#include "SDL_Image.h"
#include "game.h"
#include <stdlib.h>
#include "box-collider.h"
#include <iostream>
namespace Actors {
	GameObject::GameObject()
		: tag(GOT_DEFAULT)
		, id(Core::Game::gameobject_id++)
		, width(0)
		, height(0)
		, own_collider(nullptr)
		, position(Vector2f())
	{

	}

	GameObject::GameObject(std::string const& in_path)
		: GameObject()
	{
		Core::Game::SubscribeObjectToScene(this);
		SDL_Surface* surface = IMG_Load(in_path.c_str());
		if (surface == nullptr)
		{
			error_type = GOET_FAILED_TO_READ_IMAGE;
			std::cout << error_type << "Failed to create read image";
			return;
		}
		width = surface->w;
		height = surface->h;
		texture = std::make_shared<SDL_Texture*>(SDL_CreateTextureFromSurface(Core::Game::GetInstance().screen->GetRenderer(), surface));
		if (texture == nullptr)
		{
			error_type = GOET_FAILED_TO_CREATE_TEXTURE;
			std::cout << error_type << "Failed to create texture for GameObject";
			return;
		}
		dstrect = std::make_shared<SDL_Rect>();
		srcrect = std::make_shared<SDL_Rect>();
		srcrect->w = width;
		srcrect->h = height;
		srcrect->x = 0;
		srcrect->x = 0;
		dstrect->w = width;
		dstrect->h = height;
		dstrect->x = 0;
		dstrect->y = 0;
		velocity = Vector2f::zero;
	}

	GameObject::GameObject(std::string const& in_path, const int in_width, const int in_height, Vector2f in_pos)
		: GameObject(in_path)
	{
		position = in_pos;
		width = in_width;
		height = in_height;
		dstrect->w = width;
		dstrect->h = height;
	}

	void GameObject::AttachCollider(std::shared_ptr<Physics::Collider> in_collider)
	{
		own_collider = in_collider;
		Physics::PhysicsMgr::SubscribeToPhysicsMgr(in_collider);
	}

	void GameObject::ChangeSprite(const std::shared_ptr<SDL_Texture*> in_new_texture, const int in_x, const int in_y, const int in_width, const int in_height)
	{
		srcrect->x = in_x;
		srcrect->y = in_y;
		srcrect->w = in_width;
		srcrect->h = in_height;
		texture = in_new_texture;
	}
	void GameObject::Draw()
	{
		SDL_RenderCopy(Core::Game::GetInstance().screen->GetRenderer(), *texture, srcrect.get(), dstrect.get());
	}
	void GameObject::Update()
	{
		dstrect->x = position.x;
		dstrect->y = position.y;

		if (own_collider.get())
		{
			own_collider->Update();
		}
	}
	void GameObject::Destroy()
	{
		if (own_collider)
		{
			own_collider->Destroy(own_collider->GetId());
		}
		if (texture)
		{
			SDL_DestroyTexture(*texture);
		}
		Core::Game::MoveObjectToGarbageCollector(this->id);
	}
}


