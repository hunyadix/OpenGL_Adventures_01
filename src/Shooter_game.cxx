#include "../include/Shooter_game.h"

Shooter_game::Shooter_game()
{
	init_window();
}

void Shooter_game::init_window()
{
	if(!glfwInit()) e_glfw_init();
	m_window = glfwCreateWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE.c_str(), nullptr, nullptr);
	if(m_window == nullptr) e_window_context();
	glfwMakeContextCurrent(m_window);
	glewExperimental=true; // Check wth this does
	if(glewInit() != GLEW_OK) e_glew_init();
	glfwSetInputMode(m_window, GLFW_STICKY_KEYS, GL_TRUE);
	do
	{
		// Draw stuffs
	    // Swap buffers
	    glfwSwapBuffers(m_window);
	    glfwPollEvents();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
	while(glfwGetKey(m_window, GLFW_KEY_ESCAPE ) != GLFW_PRESS && glfwWindowShouldClose(m_window) == 0);
}

void Shooter_game::start()
{
	// FIXME: make this properly thread safe (why?)
	static bool game_started = false;
	if(game_started) e_trying_to_init_multiple_instances();
	game_started = true;
	Shooter_game game;
}

// TODO: move this to a separate implementation file if this file gets crammed (is this even a word?)
[[noreturn, gnu::cold]] void Shooter_game::e_trying_to_init_multiple_instances()
{
	throw std::runtime_error(__PRETTY_FUNCTION__);
}

[[noreturn, gnu::cold]] void Shooter_game::e_glfw_init()
{
	throw std::runtime_error(__PRETTY_FUNCTION__);
}

[[noreturn, gnu::cold]] void Shooter_game::e_window_context()
{
    glfwTerminate();
	throw std::runtime_error(__PRETTY_FUNCTION__);
}

[[noreturn, gnu::cold]] void Shooter_game::e_glew_init()
{
    glfwTerminate();
	throw std::runtime_error(__PRETTY_FUNCTION__);
}