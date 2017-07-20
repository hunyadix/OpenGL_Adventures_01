#pragma once

#include "SDL2/SDL.h"

class Drawable_sprite
{
	public:
		float                m_x;
		float                m_y;
		SDL_Rect             m_sprite_rect;
		SDL_Texture*         m_texture = nullptr;
	public:
		Drawable_sprite(int t_x, int t_y, int t_w, int t_h, SDL_Texture* m_texture);
		const float& get_sprite_pos_x() const;
		void set_sprite_pos_x(const float& t_x);
		const float& get_sprite_pos_y() const;
		void set_sprite_pos_y(const float& t_y);
		const int& get_sprite_width()  const;
		const int& get_sprite_height() const;
		virtual void draw(SDL_Renderer* t_renderer);
		virtual void draw(SDL_Renderer* t_renderer, SDL_Rect* t_frame);
};