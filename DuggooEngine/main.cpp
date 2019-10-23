// This file is made for testing purposes

#include <stdlib.h>
#include <stdio.h>

#include "src/app/application.h"
#include "src/input/keycodes.h"
#include "src/input/mouse_button_codes.h"
#include "src/graphics/render/renderer.h"


class TestApplication : public dg::app::Application
{
private:
	dg::graphics::OrthographicCamera camera;
	glm::vec3 camera_position;
	float camera_rotation = 0.0f;
	const float camera_move_speed = 0.01f;
	const float camera_rotation_speed = 0.01f;
	dg::graphics::VertexArray* va;			// Triangle va
	dg::graphics::VertexArray* square_va;	// Square va
	dg::graphics::Shader* shader;
	dg::graphics::Shader* blue_shader;

public:
	TestApplication()
		: Application(dg::graphics::WindowProperties(1280, 720, true, false, "Test Application"), dg::app::OPENGL_2D), camera(-1.6f, 1.6f, -0.9f, 0.9f),
		  camera_position(0.0f, 0.0f, 0.0f)
	{}

	void onInit()
	{
		// Colorful triangle

		float vertices[3 * 7] = {
			-0.5f, -0.5f,  0.0f, 1.0f, 0.0f, 1.0f, 1.0f,
			0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f, 1.0f,
			0.0f,  0.5f,  0.0f, 1.0f, 1.0f, 0.0f, 1.0f
		};

		unsigned int indices[3] = { 0, 1, 2 };


		va = new dg::graphics::VertexArray();

		dg::graphics::VertexBuffer* vb = new dg::graphics::VertexBuffer(vertices, sizeof(vertices));

		{
			dg::graphics::BufferLayout layout = {
				{ dg::graphics::ShaderDataType::FLOAT3, "position" },
			{ dg::graphics::ShaderDataType::FLOAT4, "a_Color" }
			};

			vb->setLayout(layout);
		}

		va->addVertexBuffer(vb);

		dg::graphics::IndexBuffer* ib = new dg::graphics::IndexBuffer(indices, 3);
		va->setIndexBuffer(ib);

		shader = new dg::graphics::Shader("res/shaders/test_2.shader");

		// Blue square

		float square_vertices[3 * 4] = {
			-0.75f, -0.75f, 0.0f,
			0.75f, -0.75f, 0.0f,
			0.75f,  0.75f, 0.0f,
			-0.75f,  0.75f, 0.0f
		};
		unsigned int square_indices[6] = { 0, 1, 2, 2, 3, 0 };


		square_va = new dg::graphics::VertexArray;

		dg::graphics::VertexBuffer* square_vb = new dg::graphics::VertexBuffer(square_vertices, sizeof(square_vertices));

		{
			dg::graphics::BufferLayout layout = {
				{ dg::graphics::ShaderDataType::FLOAT3, "position" }
			};

			square_vb->setLayout(layout);
		}

		square_va->addVertexBuffer(square_vb);

		dg::graphics::IndexBuffer* square_ib = new dg::graphics::IndexBuffer(square_indices, 6);
		square_va->setIndexBuffer(square_ib);

		blue_shader = new dg::graphics::Shader("res/shaders/blue_square.shader");
	}

	void onUpdate(float delta_time)
	{	
		// update other systems (e.g. physics system) (maybe not here)
		

		if (input.isKeyPressed(DG_KEY_A))		// left
			camera_position.x -= camera_move_speed;
		else if (input.isKeyPressed(DG_KEY_D))	// right
			camera_position.x += camera_move_speed;

		if (input.isKeyPressed(DG_KEY_W))		// up
			camera_position.y += camera_move_speed;
		else if (input.isKeyPressed(DG_KEY_S))	// down
			camera_position.y -= camera_move_speed;

		if (input.isKeyPressed(DG_KEY_RIGHT))
			camera_rotation -= camera_rotation_speed;
		else if (input.isKeyPressed(DG_KEY_LEFT))
			camera_rotation += camera_rotation_speed;


		dg::graphics::Clear({ 0.1f, 0.1f, 0.1f, 1.0f });

		camera.setPosition(camera_position);
		camera.setRotation(camera_rotation);

		dg::graphics::Renderer::BeginScene(camera);	// will take SceneSettings(camera, lights, environment) as an argument

		dg::graphics::Renderer::SubmitMesh(blue_shader, square_va);
		dg::graphics::Renderer::SubmitMesh(shader, va);

		dg::graphics::Renderer::EndScene();

		// will be called in the second thread
		//Renderer::flush();
	}

	void onDestroy()
	{
		// save game state, etc
	}
};

TestApplication myApp;

int main()
{
	// start up engine systems in the correct order (it will be put in a seperate engine file e.g. SystemsManager.h)

	myApp.start();

	//shut down the systems in reverse order (it will be put in a seperate engine file e.g. SystemsManager.h)

	return 0;
}