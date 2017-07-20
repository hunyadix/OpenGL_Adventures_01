#include "../include/Shooter_game.h"

Shooter_game::Shooter_game()
{
	static bool game_initialized = false;
	if(game_initialized) e_trying_to_init_multiple_instances();
	init_window();
	m_renderer = SDL_CreateRenderer(m_window, -1, 0);
	m_keystate = SDL_GetKeyboardState(nullptr);
	m_texture_loader.reset(Texture_loader::init_instance(m_renderer));
	init_player();
	game_loop();
	game_initialized = true;
}

Shooter_game::~Shooter_game()
{
	SDL_DestroyWindow(m_window);
	m_window = nullptr; // Why?
	// Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
	// SDL_FreeSurface(image);
	SDL_DestroyTexture(m_texture);
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
}

void Shooter_game::init_window()
{
	if(SDL_Init(SDL_INIT_VIDEO) < 0) e_sdl_init();
	m_window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_OPENGL);
	if(m_window == nullptr) e_window_context();
	m_screen_surface = SDL_GetWindowSurface(m_window);
	SDL_GL_CreateContext(m_window);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3); 
	glewExperimental = GL_TRUE; // Check wth this does
	if(glewInit() != GLEW_OK) e_glew_init();
	// auto sprite = SDL_DisplayFormat(gPNGSurface);
	// while(glfwGetKey(m_window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0);
}

void Shooter_game::init_player()
{
	m_texture = Texture_loader::get_texture("res/reimu_sprite.png");
	m_player = std::make_unique<Player>(10, 20, 32, 50, m_texture);
}

void Shooter_game::game_loop()
{
	using namespace std::chrono;
	SDL_Event e;
	bool quit = false;
	// time_point<steady_clock> loop_start_time;
	duration<float, milliseconds::period> target_refresh_rate(1000.0f / TARGET_FPS);
	steady_clock::time_point loop_start_time = steady_clock::now();
	static_assert(treat_as_floating_point<decltype(target_refresh_rate)::rep>::value, "Time should be treated as a floating point value");
	while(!quit)
	{
		loop_start_time = steady_clock::now();
		// SDL_BlitSurface( gPNGSurface, nullptr, m_screen_surface, nullptr );
		while(SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if(e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		SDL_PumpEvents();
		if(m_keystate[SDL_SCANCODE_ESCAPE])
		{
			quit = true;
		}
		handle_keyboard_events();
		render();
		// Draw stuffs
		SDL_RenderPresent(m_renderer);
		SDL_RenderClear(m_renderer);
		// SDL_BlitSurface(gPNGSurface, nullptr, m_screen_surface, &rcSprite);
		// Swap buffers
		// glfwSwapBuffers(m_window);
		// glfwPollEvents();
		// SDL_UpdateWindowSurface(m_window);
		duration<float, milliseconds::period> loop_execution_time = (steady_clock::now() - loop_start_time);
		std::this_thread::sleep_for(duration_cast<milliseconds>(target_refresh_rate - loop_execution_time));
	}	
}

void Shooter_game::render()
{
	SDL_Rect player_image_frame {0, 0, 32, 50};
	m_player -> draw(m_renderer, &player_image_frame);
}

void Shooter_game::handle_keyboard_events()
{
	m_player -> handle_keyboard_events(this);
}

void Shooter_game::start()
{
	static Shooter_game game;
}

// TODO: move this to a separate implementation file if this file gets crammed (is this even a word?)
[[noreturn, gnu::cold]] void Shooter_game::e_trying_to_init_multiple_instances() { throw std::runtime_error(__PRETTY_FUNCTION__); }
[[noreturn, gnu::cold]] void Shooter_game::e_sdl_init()                          { throw std::runtime_error(__PRETTY_FUNCTION__); }
[[noreturn, gnu::cold]] void Shooter_game::e_window_context()                    { throw std::runtime_error(__PRETTY_FUNCTION__); }
[[noreturn, gnu::cold]] void Shooter_game::e_glew_init()                         { throw std::runtime_error(__PRETTY_FUNCTION__); }