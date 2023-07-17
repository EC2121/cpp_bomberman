#include "game.h"
#include "physics-mgr.h"
#include "wall.h"
#include "game-object.h"
#include "player.h"	
#include "resources.h"
#include "bm-time.h"
#include "bm-math.h"
#include "bomb.h"
#include "destroyable-wall.h"
#include "garbage-collector.h"
#include <algorithm>
#include <iostream>
#define MAP_DIMESNIONS Vector2f(1200,720);

namespace Core {
	std::vector<std::shared_ptr<Actors::GameObject>> Game::actors_in_scene;
	std::unique_ptr<Game> Game::instance(nullptr);
	int Game::gameobject_id(0);
	Game::~Game()
	{
	}
	Game::Game()
		: event()
	{
	}

	Game& Game::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = std::make_unique<Game>(Game());
		}
		return *instance;
	}

	int Game::Init()
	{

		Vector2f size = MAP_DIMESNIONS;
		screen = std::make_shared<Graphics::Screen>(size.x, size.y);
		Actors::GameObject* player = new Actors::Player(Resources::Paths::GetPath("zombie_walk"), 32, 32, Vector2f(48, 48));
		MapInit();
		return 0;
	}

	void Game::Loop()
	{
		int running = 1;
		SDL_SetRenderDrawColor(this->screen->GetRenderer(), 0, 125, 0, 255);
		while (running)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT) {
					running = 0;
				}
			}
			SDL_PumpEvents();
			UpdateAll();
			DrawAll();
		}

	}

	void Game::MapInit()
	{
		Vector2f dimension = MAP_DIMESNIONS;
		int delta_x = dimension.x / 48;
		int delta_y = dimension.y / 48;
		for (size_t y = 0; y < delta_y; y++)
		{
			for (size_t x = 0; x < delta_x; x++)
			{
				if (y == 0 || x == 0 ||
					y == delta_y - 1 || x == delta_x - 1
					|| (y % 2 == 0 && x % 2 == 0))
				{
					Actors::Wall* wall = new Actors::Wall(48, 48, Vector2f(x * 48, y * 48));
				}
				else
				{
					int random = rand() % 101;
					if (random >= 90)
					{
						Actors::DestroyableWall* d_wall = new Actors::DestroyableWall(48, 48, Vector2f(x * 48, y * 48));
					}
				}
			}
		}
	}




	void Game::DrawAll()
	{
		SDL_RenderClear(screen.get()->GetRenderer());

		for (std::shared_ptr<Actors::GameObject>& actor : actors_in_scene)
		{
			if (actor.get())
			{
				actor->Draw();
			}
		}
		SDL_RenderPresent(screen->GetRenderer());
	}

	void Game::UpdateAll()
	{
		Time::GetInstance().Update();
		Physics::PhysicsMgr::GetInstance().Update();
		for (std::shared_ptr<Actors::GameObject>& actor : actors_in_scene)
		{
			if (actor.get())
			{
				actor->Update();
			}
		}

		Uint32 time = SDL_GetTicks();
		if (time % 1000 >= 990)
		{
			GC::GarbageCollector::ClearObjects();
		}

	}

	void Game::SubscribeObjectToScene(Actors::GameObject* in_obj)
	{
		actors_in_scene.push_back(std::shared_ptr<Actors::GameObject>(in_obj));
	}

	void Game::MoveObjectToGarbageCollector(const int id)
	{
		auto condition = [id](std::shared_ptr<Actors::GameObject> ref) {
			return ref->GetId() == id;
		};
		auto partition = std::stable_partition(actors_in_scene.begin(), actors_in_scene.end(),
			[&](const auto& x) { return !condition(x); });
		GC::GarbageCollector::objects_to_destroy.insert(GC::GarbageCollector::objects_to_destroy.end(), std::make_move_iterator(partition),
			std::make_move_iterator(actors_in_scene.end()));
		actors_in_scene.erase(partition, actors_in_scene.end());
	}








}