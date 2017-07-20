#pragma once

#include "SDL2/SDL.h"
#include "Shooter_game.h"
#include "Drawable_sprite.h"

class Shooter_game;

class Player: public Drawable_sprite
{
	public:
		enum Player_type
		{
			LUNAR_WITCH,
			EXORCIST,
			APPARATUS_FABRICATOR
		};
		float                m_speed = 10;
	public:
		Player(int t_x, int t_y, int t_w, int t_h, SDL_Texture* t_texture);
		virtual ~Player();
		void handle_keyboard_events(Shooter_game* t_game);
};