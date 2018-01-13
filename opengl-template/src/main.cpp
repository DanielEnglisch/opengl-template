#include "GlWindow.h"

void redraw() {

	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
		glVertex2f(0.5,0);
		glVertex2f(- 0.5, 0);
		glVertex2f(0, 1);
	glEnd();
}

int main() {
	/* Creates a new opengl enabled window usinw width, height, title, rearaw function pointer */
	new GlWindow{ 1080,720,"Window1",&redraw };
}