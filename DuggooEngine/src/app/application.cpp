#include "application.h"


namespace dg { namespace app {

Application::Application(graphics::WindowProperties properties, RenderType render_type)
{
	switch (render_type)
	{
	case OPENGL_2D :
		// renderer = new Renderer2D;
		break;

	case OPENGL_3D :
		// renderer = new Renderer3D;
		break;
	}

	window.properties = properties;
}

Application::~Application()
{
	
}

void Application::start()
{
	// init other systems (maybe not here)
	
	if (!window.init())
	{
		printf("GLFW failed\n");
		return;
	}

	input.setWindow(window.windowHandle);

	running = true;
	onInit();

	float vertices[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, -1.0f,
		 0.0f,  0.5f, 0.0f
	};

	unsigned int indices [3]= {
		0, 1, 2
	};

	/*graphics::VertexArray va;
	graphics::Buffer vb(vertices, 9, 3);
	va.addBuffer(&vb, 1);
	graphics::IndexBuffer ib(indicies, 3);

	ib.bind();*/

	printf("OpenGL version: %s\n", glGetString(GL_VERSION));
	printf("GPU vendor: %s\n", glGetString(GL_VENDOR));
	printf("GPU model: %s\n", glGetString(GL_RENDERER));

	unsigned int va_id, vb_id, ib_id;

	glGenVertexArrays(1, &va_id);
	glBindVertexArray(va_id);

	glGenBuffers(1, &vb_id);
	glBindBuffer(GL_ARRAY_BUFFER, vb_id);

	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

	glGenBuffers(1, &ib_id);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ib_id);

	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	//graphics::Shader shader("res/shaders/test.shader");

	float last_frame_time = 0.0f;
	while (running && !window.isClosed())
	{	
		onUpdate(clock.getDeltaTime());

		// update other systems (e.g. physics system) (maybe not here)
		//renderer.render();
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//shader.bind();
		glBindVertexArray(va_id);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

		window.refresh();
	}

	window.destroy();

	onDestroy();

	stop();
}

void Application::stop()
{
	// stop other systems (maybe not here)
}

} }