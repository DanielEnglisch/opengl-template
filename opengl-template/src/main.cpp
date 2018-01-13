#include "GlApp.h"

class MySketch : public GlApp {
public:

	MySketch(const unsigned int w, const unsigned int h, const std::string& t)
		: GlApp::GlApp{w,h,t}
	{
		/* Setup */


	}



	void draw() override {


	
	}

	

};

int main() {
	/* Creates a new opengl enabled window usinw width, height, title, rearaw function pointer */
	MySketch* app{ new MySketch {1080,720,"Titles"} };
	app->run();
}