#pragma once
#include <string>
#include "SDL.h"
#include <memory>
#include <functional>
namespace Actors {
	class GameObject;
}

namespace Animations {

	enum AnimErrorType {
		AET_FAILED_TO_READ_IMAGE
	};
	typedef std::function<void()> OnAnimationEnd;
	class Animation {

	public:
		Animation() = delete;
		~Animation() = default;
		Animation(Actors::GameObject& in_owner, std::string const& in_path, const int in_number_of_frames_per_row,
			const int in_number_of_frames_per_column, const float in_frame_rate_in_ms);
		Animation(Actors::GameObject& in_owner, std::string const& in_path, const int in_number_of_frames_per_row,
			const int in_number_of_frames_per_column, const float in_frame_rate_in_ms,const bool in_should_invoke_event , OnAnimationEnd in_func);
	public:
		void Play() { is_playing = true; time_of_start = SDL_GetTicks(); };
		void Stop() { is_playing = false; };
		void Update();
		void Reset();

	public:
		bool should_invoke_event_on_last_frame;
	private:
		OnAnimationEnd on_animation_end;
		AnimErrorType error_type = AET_FAILED_TO_READ_IMAGE;
		std::shared_ptr<SDL_Texture*> anim_texture;
		Actors::GameObject& owner;
		bool is_playing;
		int width;
		int height;
		int number_of_frames_per_row;
		int number_of_frames_per_column;
		float frame_rate_in_ms;
		bool last_frame;
		Uint32 time_of_start;
		Uint32 ticks;
		Uint32 time;
	};
}