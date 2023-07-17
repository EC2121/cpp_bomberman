#include "animation.h"
#include "game-object.h"
#include "SDL_image.h"
#include <iostream>
#include <utility>
#include "game.h"
namespace Animations {


	Animation::Animation(Actors::GameObject& in_owner, std::string const& in_path, const int in_number_of_frames_per_row, const int in_number_of_frames_per_column, const float in_frame_rate_in_ms)
		: should_invoke_event_on_last_frame(false)
		  , owner(in_owner)
		  , is_playing(false)
		  , width(0)
		  , height(0)
		  , number_of_frames_per_row(0)
		  , number_of_frames_per_column(0)
		  , frame_rate_in_ms(0)
		  , last_frame(false)
		  , time_of_start(0)
		  , ticks(0)
		  , time(0)
	{

		SDL_Surface* surface = IMG_Load(in_path.c_str());
		if (surface == nullptr)
		{
			error_type = AET_FAILED_TO_READ_IMAGE;
			std::cout << error_type << "Failed to create read image";
			return;
		}
		width = surface->w / in_number_of_frames_per_row;
		height = surface->h / in_number_of_frames_per_column;
		anim_texture = std::make_shared<SDL_Texture*>(SDL_CreateTextureFromSurface(Core::Game::GetInstance().screen->GetRenderer(), surface));
		is_playing = false;
		number_of_frames_per_row = in_number_of_frames_per_row;
		number_of_frames_per_column = in_number_of_frames_per_column;
		frame_rate_in_ms = in_frame_rate_in_ms;
		ticks = 0;
		time = 0;
		time_of_start = 0;
	}

	Animation::Animation(Actors::GameObject& in_owner, std::string const& in_path, const int in_number_of_frames_per_row, const int in_number_of_frames_per_column, const float in_frame_rate_in_ms, const bool in_should_invoke_event, OnAnimationEnd in_func)
		: Animation(in_owner, in_path, in_number_of_frames_per_row, in_number_of_frames_per_column, in_frame_rate_in_ms)

	{
		on_animation_end = std::move(in_func);
		should_invoke_event_on_last_frame = in_should_invoke_event;
	}

	void Animation::Update()
	{
		if (is_playing)
		{
			ticks = SDL_GetTicks() - time_of_start;
			time = ticks / frame_rate_in_ms;
			Uint32 x = (time % number_of_frames_per_row);
			if ((last_frame && x <= number_of_frames_per_row))
				last_frame = false;
			else
				last_frame = last_frame;
			owner.ChangeSprite(anim_texture, width * x, 0, width, height);

			if (should_invoke_event_on_last_frame &&
				(!last_frame && x == number_of_frames_per_row - 1) &&
				(SDL_GetTicks() - time_of_start) > frame_rate_in_ms)
			{
				on_animation_end();
				last_frame = true;
			}
		}
	}
	void Animation::Reset()
	{
		time_of_start = 0;
		ticks = 0;
		time = 0;
	}
}


