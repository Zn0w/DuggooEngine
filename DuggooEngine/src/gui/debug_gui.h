#pragma once

#include "gui.h"


namespace dg { namespace gui {

	class DebugGui : public Gui
	{
	public:
		bool debug_mode;
	private:
		bool show_fps;

	public:
		void render()
		{
			// Start the Dear ImGui frame
			ImGui_ImplOpenGL3_NewFrame();
			ImGui_ImplGlfw_NewFrame();
			ImGui::NewFrame();

			if (debug_mode)
			{
				static int counter = 0;

				ImGui::Begin("Debug Information");

				ImGui::Checkbox("Show FPS", &show_fps);

				ImGui::Text("FPS: %.1f (%.3f ms/frame)", ImGui::GetIO().Framerate, 1000.0f / ImGui::GetIO().Framerate);

				ImGui::Text("OpenGL version: %s", glGetString(GL_VERSION));
				ImGui::Text("GPU vendor: %s", glGetString(GL_VENDOR));
				ImGui::Text("GPU model: %s", glGetString(GL_RENDERER));

				ImGui::End();
			}
			else if (show_fps)
			{
				ImGui::Begin("FPS:");
				ImGui::Text("%.1f", ImGui::GetIO().Framerate);
				ImGui::End();
			}

			ImGui::Render();
			ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
		}
	};

} }