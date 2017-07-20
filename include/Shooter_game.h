#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <thread>
#include <iostream>
#include <memory>

// OpenGL
#define NO_SDL_GLEXT
#include <GL/glew.h>
// #include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <GL/glu.h> 

#include "SDL2/SDL.h"
#include "SDL/SDL_opengl.h"
#include "SDL2/SDL_image.h"

#include "Player.h"
#include "Texture_loader.h"

class Player;

class Shooter_game
{
	private:
		// Constants
		const int         WINDOW_WIDTH  = 800;
		const int         WINDOW_HEIGHT = 600;
		const float       TARGET_FPS    = 60.0f;
		const std::string WINDOW_TITLE  = "Shooter game v0.00a";
		// States
		SDL_Window*                     m_window         = nullptr;
		SDL_Surface*                    m_screen_surface = nullptr;
		SDL_Texture*                    m_texture        = nullptr;
		SDL_Renderer*                   m_renderer       = nullptr;
		const Uint8*                    m_keystate       = nullptr;
		std::unique_ptr<Texture_loader> m_texture_loader = nullptr;
		// Entities
		std::unique_ptr<Player>        m_player;
	public:
		// Start
		static void start();
		// Getters
		SDL_Renderer* get_renderer()      const { return m_renderer;    }
		const Uint8*  get_key_state()     const { return m_keystate;    }
		int           get_window_width()  const { return WINDOW_WIDTH;  }
		int           get_window_height() const { return WINDOW_HEIGHT; }
	private:
		// Main utility
		Shooter_game();
		~Shooter_game();
		Shooter_game(Shooter_game& t_other)                = delete;
		Shooter_game& operator=(const Shooter_game& t_rhs) = delete;
		// Errors
		[[noreturn, gnu::cold]] static void e_trying_to_init_multiple_instances(); 
		[[noreturn, gnu::cold]] static void e_sdl_init();
		[[noreturn, gnu::cold]] static void e_window_context();
		[[noreturn, gnu::cold]] static void e_glew_init();
		// Logic
		void init_window();	
		void init_player();	
		void game_loop();
		void handle_keyboard_events();
		void render();
};