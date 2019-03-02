#ifndef SDLMENU_H
#define SDLMENU_H

//According to SDL docs
using SDL_GLContext = void*;
struct SDL_Window;
union SDL_Event;

namespace SDLMenu
{
	void InitializeContext(SDL_GLContext glContext, struct SDL_Window* window);
	void ShutdownContext();
	bool PollEvent(union SDL_Event* event);
	void NewFrame(struct SDL_Window* window);
}

#endif
