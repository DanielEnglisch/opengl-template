#include "GlApp.h"
#include "GlUtils.h"

using namespace glu;

class MySketch : public GlApp {
public:
	unsigned int vao;
	unsigned int program;
	VertexBuffer* vb{ nullptr };
	IndexBuffer* ib{nullptr};

	MySketch(const unsigned int w, const unsigned int h, const std::string& t)
		: GlApp::GlApp{w,h,t}
	{
		/* Setup */

		float positions[]{
			-0.5f, -0.5f,
			0.5f, -0.5f,
			0.5f, 0.5f,
			-0.5f, 0.5f
		};

		unsigned int indices[]{
			0,1,2,
			2,3,0
		};

		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);

		
		vb = new VertexBuffer(positions, 4*2*sizeof(float));
		vb->Bind();

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0,2,GL_FLOAT, GL_FALSE, sizeof(float)*2, 0);

		ib = new IndexBuffer(indices,6);

		const std::string vertex_src{
			"attribute vec4 position;\n"
			"void main(){\n"
			"gl_Position = position;\n"
			"}"
		};

		const std::string fragment_src{
			"void main(){\n"
			"gl_FragColor = vec4(1.0,1.0,0.0,1.0);\n"
			"}"
		};

		program = CreateProgram(vertex_src, fragment_src);
		glUseProgram(program);


	}



	void draw() override {

		glClear(GL_COLOR_BUFFER_BIT);
		glUseProgram(program);
		glBindVertexArray(vao);
		ib->Bind();
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
		
	}

	

};

int main() {
	/* Creates a new opengl enabled window usinw width, height, title, rearaw function pointer */
	MySketch* app{ new MySketch {1080,720,"Titles"} };
	app->run();
}