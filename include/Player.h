#pragma once

#include "SDL2/SDL.h"
#include "Shooter_game.h"

class Shooter_game;

class Player
{
	private:
		const Shooter_game*  m_game = nullptr;
		float                m_x;
		float                m_y;
		float                m_speed = 10;
		SDL_Rect             m_sprite_rect;
		SDL_Texture*         m_texture = nullptr;
	public:
		Player(const Shooter_game* t_game, int t_x, int t_y, int t_w, int t_h, SDL_Surface* t_surface);
		~Player();
		void handle_keyboard_events();
		void draw();
};