#pragma once
#include "game-object.h"
#include "bm-math.h"
namespace Actors {
	class Wall : public GameObject {

	public:
		Wall() = default;
		Wall(const int in_width, const int in_height, const Vector2f in_pos);
		virtual ~Wall() override = default;
		Wall(const Wall&) = default;
		Wall& operator=(const Wall&) = delete;

	public:
		void Update() override;

	};
}