#pragma once

#include "SDL2/SDL.h"

class Bullet
{
	Bullet();
	~Bullet();
	Bullet(Bullet& t_other)                = delete;
	Bullet& operator=(const Bullet& t_rhs) = delete;
};