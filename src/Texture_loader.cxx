#include "../include/Texture_loader.h"

Texture_loader* Texture_loader::m_instance {nullptr};

class Texture_deleter
{
	public:
		void operator()(SDL_Texture* t_texture) { SDL_DestroyTexture(t_texture); }
};

// std::map<std::string, std::unique_ptr<SDL_Texture>> Texture_loader::textures;

Texture_loader::Texture_loader(SDL_Renderer* t_renderer): m_renderer(t_renderer) {};

Texture_loader::~Texture_loader()
{
	free_textures();
}

Texture_loader* Texture_loader::init_instance(SDL_Renderer* t_renderer)
{
	static Texture_loader* instance = new Texture_loader(t_renderer);
	m_instance = instance;
	return instance;
}

Texture_loader* Texture_loader::get_instance()
{
	return m_instance;
}

void Texture_loader::free_textures()
{
	get_instance() -> m_textures.clear(); // This should release the unique pointers that are the owners of the textures
}

SDL_Texture* Texture_loader::get_texture(const std::string& t_texture_path)
{
	auto pos = m_instance -> m_textures.find(t_texture_path);
	if(pos != m_instance -> m_textures.end()) return pos -> second.get();
	else
	{
		SDL_Surface* loadedSurface = IMG_Load(t_texture_path.c_str());
		if(loadedSurface == nullptr) e_image_missing();
		SDL_Texture* texture = SDL_CreateTextureFromSurface(m_instance -> m_renderer, loadedSurface);
		bool emplace_success = false;
		std::tie(pos, emplace_success) = m_instance -> m_textures.emplace(t_texture_path, texture);
		SDL_FreeSurface(loadedSurface);
		return pos -> second.get();
	}
}

[[noreturn, gnu::cold]] void Texture_loader::e_image_missing() { throw std::runtime_error(__PRETTY_FUNCTION__); }
