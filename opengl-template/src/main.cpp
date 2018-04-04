#include "GlApp.h"
#include "GlUtils.h"

using namespace glu;

class MySketch : public GlApp {
public:
	unsigned int vao;
	unsigned int program;
	VertexBuffer* vb{ nullptr };
	IndexBuffer* ib{nullptr};
	unsigned int bufferId;

	MySketch(const unsigned int w, const unsigned int h, const std::string& t)
		: GlApp::GlApp{w,h,t}
	{

		// 1.Generate Buffer
		glGenBuffers(1,&bufferId);

		// 2.Bind as array buffer
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);

		// 3.Define vertices
		float* data = new float[6]{
			-0.5f, -0.5f,
			0.0f,  0.5,
			0.5f, -0.5f
		};

		// 4.Set data of bound buffer
		glBufferData(GL_ARRAY_BUFFER, 6*sizeof(float), data, GL_STATIC_DRAW);

		// 5.Set layout of data
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float)*2, 0);


		// === Shaders ===
		// Vertex Shader Source

		const std::string vertex_shader =
			"#version 330 core\n"
			"layout(location=0) in vec4 pos;\n"

			"void main(){\n"
			"gl_Position = pos;\n"
			"}";

		// Fragment Shader Source

		const std::string fragment_shader =
			"#version 330 core\n"
			"layout(location=0) out vec4 color;\n"

			"void main(){\n"
			"color = vec4(1.0,0.0,0.0,1.0);\n"
			"}";

		// 6.Compile and enable shaders
		const unsigned int pid = glu::CreateProgram(vertex_shader, fragment_shader);
		glUseProgram(pid);

		

	}


	/*void draw() override {

		glClear(GL_COLOR_BUFFER_BIT);

		glBegin(GL_TRIANGLES);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glVertex2f(0.5f, -0.5f);
		glEnd();

	}*/



	void draw() override {

		glClear(GL_COLOR_BUFFER_BIT);

		/* Bind vertex buffer */
		glBindBuffer(GL_ARRAY_BUFFER, bufferId);
		/* Draw 3 vertices without skipping any */
		glDrawArrays(GL_TRIANGLES, 0, 3);
		
	}

	

};

int main() {
	/* Creates a new opengl enabled window usinw width, height, title, rearaw function pointer */
	MySketch* app{ new MySketch {1080,720,"Modern OpenGL Demo"} };
	app->run();
}