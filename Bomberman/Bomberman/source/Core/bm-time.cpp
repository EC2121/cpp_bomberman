#include "bm-time.h"
#include "SDL.h"
#include <iostream>

namespace Core {
	float Time::deltatime;
	std::unique_ptr<Time> Time::instance;
	float Time::now;
	float Time::last;


	Time::Time()
	{
	}

	Time& Time::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = std::unique_ptr<Time>(new Time());
		}
		return *instance;
	}
	void Time::Update()
	{
		Time::now = SDL_GetTicks();
		Time::deltatime = (now - last) / 1000.f;
		Time::last = now;


	}

}
