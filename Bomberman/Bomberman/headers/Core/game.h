#pragma once
#include <memory>
#include "screen.h"
#include <vector>
#include <string>
#include "SDL.h"

namespace Actors {
	class GameObject;
}
namespace Physics {
	class PhysicsMgr;
}

namespace Core {
	class Game {

	public:
		~Game();
		Game(const Game&) = default;
		Game& operator=(const Game&) = default;
	protected:
		Game();
	public:
		static Game& GetInstance();
		int Init();
		void Loop();
		void MapInit();
		void TexturesInit();
		static void SubscribeObjectToScene(Actors::GameObject* in_obj);
		static void MoveObjectToGarbageCollector(const int id);
	private:
		void DrawAll();
		void UpdateAll();
	public:
		std::shared_ptr<Graphics::Screen> screen;
		static std::vector<std::shared_ptr<Actors::GameObject>> actors_in_scene;
		static int gameobject_id;
	private:
		static std::unique_ptr<Game> instance;
		SDL_Event event;
	};




}