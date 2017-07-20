#include "../include/Player.h"

Player::Player(int t_x, int t_y, int t_w, int t_h, SDL_Texture* t_texture):
	Drawable_sprite(t_x, t_y, t_w, t_h, t_texture) {}

Player::~Player() {}

void Player::handle_keyboard_events(Shooter_game* t_game)
{
	const float& pos_x = get_sprite_pos_x();
	const float& pos_y = get_sprite_pos_y();
	const Uint8* keystate   = t_game -> get_key_state(); 
	const int window_width  = t_game -> get_window_width();
	const int window_height = t_game -> get_window_height();
	if(keystate[SDL_SCANCODE_LEFT])  set_sprite_pos_x(pos_x - m_speed);
	if(keystate[SDL_SCANCODE_RIGHT]) set_sprite_pos_x(pos_x + m_speed);
	if(keystate[SDL_SCANCODE_UP])    set_sprite_pos_y(pos_y - m_speed);
	if(keystate[SDL_SCANCODE_DOWN])  set_sprite_pos_y(pos_y + m_speed);
	/* collide with edges of screen */
	if(pos_x != get_sprite_pos_x())
		std::cout << pos_x << " vs " << get_sprite_pos_x() << std::endl;
	if(pos_x < 0.0f)                                set_sprite_pos_x(0.0f);
	if(pos_x > window_width - get_sprite_width())   set_sprite_pos_x(window_width - get_sprite_width());
	if(pos_y < 0.0f)                                set_sprite_pos_y(0.0f);
	if(pos_y > window_height - get_sprite_height()) set_sprite_pos_y(window_height - get_sprite_height());
}
