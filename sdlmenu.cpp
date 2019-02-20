#include "sdlmenu.h"

#include "imgui/imgui.h"
#include "imgui/examples/imgui_impl_sdl.h"
#include "imgui/examples/imgui_impl_opengl2.h"

void SDLMenu::InitializeContext(SDL_GLContext glContext, SDL_Window* window)
{
	ImGui_ImplSDL2_InitForOpenGL(window, glContext);
	ImGui_ImplOpenGL2_Init();
}

void SDLMenu::PollEvent(SDL_Event* event)
{
	ImGui_ImplSDL2_ProcessEvent(event);
}

void SDLMenu::NewFrame(struct SDL_Window* window)
{
	// Start the Dear ImGui frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame(window);
	ImGui::NewFrame();
}
