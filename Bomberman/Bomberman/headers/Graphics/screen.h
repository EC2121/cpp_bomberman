#pragma once
#include <memory>

struct SDL_Window;
struct SDL_Renderer;

namespace Graphics {

	enum ScreenErrorType
	{
		SET_NONE,
		SET_SDL_INIT_ERROR,
		SET_SDL_WINDOW_INIT_ERROR,
		SET_SDL_RENDERER_INIT_ERROR,
		SET_MAX
	};
	class Screen {

	public:
		~Screen();
		Screen()
			: renderer(nullptr)
			, window(nullptr)
		{}
		Screen(const int in_width, const int in_height);
		Screen(const Screen&) = default;
		Screen& operator=(const Screen&) = default;
	
	public:

		SDL_Renderer* GetRenderer() const { return renderer; }
		SDL_Window* GetWindow() const { return window; }

	public:
		ScreenErrorType error_type = SET_NONE;
	private:
		SDL_Renderer* renderer;
		SDL_Window* window;
		static std::unique_ptr<Screen> instance;

	};
}

