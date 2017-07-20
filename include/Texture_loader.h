#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"

class Texture_deleter;

class Texture_loader
{
	private:
		static Texture_loader* m_instance;
		std::map<std::string, std::unique_ptr<SDL_Texture, Texture_deleter>> m_textures;
		SDL_Renderer* m_renderer;
	public:
		static Texture_loader* init_instance(SDL_Renderer* t_renderer);
		static Texture_loader* get_instance();
		static SDL_Texture* get_texture(const std::string& t_texture_path);
		static void   free_textures();
		~Texture_loader();	
	private:
		Texture_loader(SDL_Renderer* t_renderer);
		Texture_loader(const Texture_loader& t_other) = delete;
		Texture_loader(Texture_loader&& t_other) = delete;
		Texture_loader& operator=(const Texture_loader&) = delete;
		Texture_loader& operator=(Texture_loader&&) = delete;
		// Errors
		[[noreturn, gnu::cold]] static void e_image_missing();
};
