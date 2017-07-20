#include "../include/Drawable_sprite.h"

Drawable_sprite::Drawable_sprite(int t_x, int t_y, int t_w, int t_h, SDL_Texture* t_texture):
	m_x(t_x),
	m_y(t_y),
	m_sprite_rect {t_x, t_y, t_w, t_h},
	m_texture(t_texture) {}

const float& Drawable_sprite::get_sprite_pos_x() const { return m_x; };

void Drawable_sprite::set_sprite_pos_x(const float& t_x)
{
	m_x             = t_x;
	m_sprite_rect.x = t_x;
}

const float& Drawable_sprite::get_sprite_pos_y() const { return m_y; };

void Drawable_sprite::set_sprite_pos_y(const float& t_y)
{
	m_y             = t_y;
	m_sprite_rect.y = t_y;
}

const int& Drawable_sprite::get_sprite_width()  const { return m_sprite_rect.w; }
const int& Drawable_sprite::get_sprite_height() const { return m_sprite_rect.h; }

#include <iostream>

void Drawable_sprite::draw(SDL_Renderer* t_renderer)
{
	SDL_RenderCopy(t_renderer, m_texture, nullptr, &m_sprite_rect);
}

void Drawable_sprite::draw(SDL_Renderer* t_renderer, SDL_Rect* t_frame)
{
	// std::cout << m_x << " " << m_sprite_rect.x << std::endl;
	SDL_RenderCopy(t_renderer, m_texture, t_frame, &m_sprite_rect);
}
