#pragma once

#include <string>
#include <vector>
#include <algorithm>
#include <exception>
#include <stdexcept>
#include <chrono>
#include <thread>

// OpenGL
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <GL/glu.h> 

class Shooter_game
{
	private:
		// Constants
		const int         WINDOW_WIDTH  = 800;
		const int         WINDOW_HEIGHT = 600;
		const std::string WINDOW_TITLE  = "Shooter game v0.00a";
		// States
		GLFWwindow* m_window;
	public:
		static void start();
	private:
		// Main utility
		Shooter_game();
		// Errors
		[[noreturn, gnu::cold]] static void e_trying_to_init_multiple_instances(); 
		[[noreturn, gnu::cold]] static void e_glfw_init();
		[[noreturn, gnu::cold]] static void e_window_context();
		[[noreturn, gnu::cold]] static void e_glew_init();
		// Logic
		void init_window();	
};