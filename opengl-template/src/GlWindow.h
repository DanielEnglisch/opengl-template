#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class GlWindow {
private:
	void(*redraw)() { nullptr };
public:
	GlWindow(const unsigned int width, const unsigned int height,const std::string& title, void(*redraw)())
		: redraw{redraw} {
		/* Initialize the library */
		if (!glfwInit()) {
			std::cerr << "glfwInit failed!" << std::endl;
		}

		/* Create a windowed mode window and its OpenGL context */
		GLFWwindow* window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
		if (!window)
		{
			std::cerr << "Window creation failed!" << std::endl;
			glfwTerminate();
		}

		/* Make the window's context current */
		glfwMakeContextCurrent(window);

		/* Init GLEW */
		if (glewInit() != GLEW_OK) {
			std::cerr << "glewInit failed!" << std::endl;
		}


		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window)) {
			
			this->redraw();

			glfwSwapBuffers(window);
			glfwPollEvents();

		}

		glfwTerminate();
	}
};

