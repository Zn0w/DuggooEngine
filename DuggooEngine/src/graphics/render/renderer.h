#pragma once


namespace dg { namespace graphics {

	class Renderer
	{
	public:
		void render()
		{
			// update camera
	
			// update the scene elements
	
			// render the scene
	
			// swap buffers

			int width = dg::graphics::window.properties.width;
			int height = dg::graphics::window.properties.height;
			glViewport(0, 0, width, height);
			glClearColor(0.0f, 0.3f, 0.5f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT);
		}
	};

} }