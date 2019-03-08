#pragma once

#include <vector>

#include "renderer.h"
#include "../entity/entity.h"

namespace dg { namespace graphics {

	struct Scene
	{
		std::vector<entity::Entity*> entities;
	};

} }