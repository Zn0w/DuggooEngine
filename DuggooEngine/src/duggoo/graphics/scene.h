#pragma once

#include <vector>

//#include "renderer.h"
#include "../entity/entity.h"

namespace dg { namespace graphics {

	class Scene
	{
		std::vector<entity::Entity*> entities;

		//Renderer* renderer;

		void draw();
	};

} }