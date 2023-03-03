#pragma once
#include "game-object.h"
namespace Actors {
	class DestroyableWall : public GameObject {

	public:
		DestroyableWall() = delete;
		DestroyableWall(const int in_width, const int in_height, const Vector2f in_pos);
		virtual ~DestroyableWall() override = default;
		DestroyableWall(const DestroyableWall&) = default;
		DestroyableWall& operator=(const DestroyableWall&) = delete;


	public:
		void Update() override;
	};
}