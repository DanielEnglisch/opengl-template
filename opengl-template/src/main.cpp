#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
	std::cout << "Working" << std::endl;

	/* Initialize the library */
	if (!glfwInit()) {
		std::cout << "glfwInit failed!" << std::endl;
	}

	/* Create a windowed mode window and its OpenGL context */
	GLFWwindow* window = glfwCreateWindow(1080, 720, "OpenGl-Template", NULL, NULL);
	if (!window)
	{
		std::cout << "Window creation failed!" << std::endl;
		glfwTerminate();
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	/* Init GLEW */
	if (glewInit() != GLEW_OK) {
		std::cout << "glewInit failed!" << std::endl;
	}


	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT );

		glfwSwapBuffers(window);
		glfwPollEvents();


	}

	glfwTerminate();

	return 0;
}