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

	debug_info.init(window.windowHandle);

	running = true;
	onInit();

	printf("OpenGL version: %s\n", glGetString(GL_VERSION));
	printf("GPU vendor: %s\n", glGetString(GL_VENDOR));
	printf("GPU model: %s\n", glGetString(GL_RENDERER));

	float vertices[3 * 3] = {
		-0.5f, -0.5f, 0.0f,
		 0.5f, -0.5f, -1.0f,
		 0.0f,  0.5f, 0.0f
	};

	unsigned int indices [3]= {
		0, 1, 2
	};

	unsigned int va_id;

	glGenVertexArrays(1, &va_id);
	glBindVertexArray(va_id);

	graphics::VertexBuffer vb(vertices, sizeof(vertices));
	
	dg::graphics::BufferLayout layout = {
		{ dg::graphics::ShaderDataType::FLOAT3, "a_Position" }
	};

	//vb.setLayout();

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

	graphics::IndexBuffer ib(indices, 3);

	graphics::Shader shader("res/shaders/test_2.shader");

	float last_frame_time = 0.0f;
	while (running && !window.isClosed())
	{	
		onUpdate(clock.getDeltaTime());

		// update other systems (e.g. physics system) (maybe not here)
		//renderer.render();
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		shader.bind();
		glBindVertexArray(va_id);
		glDrawElements(GL_TRIANGLES, 3, GL_UNSIGNED_INT, nullptr);

		// engine-specific input handling (e.g. press F3 to enter engine debug mode)
		if (input.isKeyTyped(DG_KEY_F3))
		{
			if (debug_info.debug_mode)
				debug_info.debug_mode = false;
			else
				debug_info.debug_mode = true;
		}

		debug_info.render();

		window.refresh();
	}

	debug_info.destroy();

	window.destroy();

	onDestroy();

	stop();
}

void Application::stop()
{
	// stop other systems (maybe not here)
}

} }