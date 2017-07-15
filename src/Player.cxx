#include "../include/Player.h"

Player::Player(const Shooter_game* t_game, int t_x, int t_y, int t_w, int t_h, SDL_Surface* t_surface):
	m_game(t_game),
	m_sprite_rect {t_x, t_y, t_w, t_h},
	m_texture(SDL_CreateTextureFromSurface(m_game -> get_renderer(), t_surface)) {}

Player::~Player()
{
	SDL_DestroyTexture(m_texture);
}

void Player::handle_keyboard_events()
{
	int SPRITE_SIZE = 32;
	const Uint8* keystate = m_game -> get_key_state(); 
	const int window_width = m_game -> get_window_width();
	const int window_height = m_game -> get_window_height();
	if(keystate[SDL_SCANCODE_LEFT])
	{
		m_sprite_rect.x -= m_speed;
	}
	if(keystate[SDL_SCANCODE_RIGHT])
	{
		m_sprite_rect.x += m_speed;
	}
	if(keystate[SDL_SCANCODE_UP])
	{
		m_sprite_rect.y -= m_speed;
	}
	if(keystate[SDL_SCANCODE_DOWN])
	{
		m_sprite_rect.y += m_speed;
	}
	/* collide with edges of screen */
	if(m_sprite_rect.x < 0)
	{
		m_sprite_rect.x = 0;
	}
	else
	{
		if(m_sprite_rect.x > window_width - SPRITE_SIZE)
		{
			m_sprite_rect.x = window_width - SPRITE_SIZE;
		}
	}
	if(m_sprite_rect.y < 0)
	{
		m_sprite_rect.y = 0;
	}
	else
	{
		if(m_sprite_rect.y > window_height - SPRITE_SIZE)
		{
			m_sprite_rect.y = window_height - SPRITE_SIZE;
		}
	}
}

void Player::draw()
{
	SDL_Rect frame {0, 0, 32, 50};
	SDL_RenderCopy(m_game -> get_renderer(), m_texture, &frame, &m_sprite_rect);
}