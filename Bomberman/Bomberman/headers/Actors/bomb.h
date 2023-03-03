#pragma once
#include "game-object.h"
#include "IAnimatable.h"
namespace Actors {

	class Bomb : public GameObject , public Animations::IAnimatable{


	public:
		Bomb() = delete;
		virtual ~Bomb() override;
		Bomb(const Bomb&) = default;
		Bomb& operator=(const Bomb&) = delete;

		Bomb(const Vector2f in_pos);
	public:
		void Update() override;
		void OnBombExplosion();
	};
}