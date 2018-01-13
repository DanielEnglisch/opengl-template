#pragma once

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>

class GlApp {
public:
	GlApp(const unsigned int width, const unsigned int height,const std::string& title){

		/* Initialize the library */
		if (!glfwInit()) {
			std::cerr << "glfwInit failed!" << std::endl;
		}

		/* Create a windowed mode window and its OpenGL context */
		window = glfwCreateWindow(width, height, title.c_str(), NULL, NULL);
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

		
		
	}

	~GlApp() {
		delete window;
		glfwTerminate();
	}

	void run() {
		/* Loop until the user closes the window */
		while (!glfwWindowShouldClose(window)) {

			draw();
			glfwSwapBuffers(window);
			glfwPollEvents();

		}

		glfwTerminate();
	}
	virtual void draw() {};
	GLFWwindow* window{ 0 };

};

