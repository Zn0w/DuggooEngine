#pragma once

#include <vector>

#include "../entity/entity.h"

namespace dg { namespace graphics {

	enum Shape
	{
		// This will be edited
		
		Pixel,
		Line,
		
		Rectangle,
		Triangle,
		Ellipse,

		Cube,
		Pyramid,
		Parallelepiped
	};
	
	class Renderer
	{
	
		// Implementation-specific functions
		void(*prepare) ();
		void(*draw) (entity::Entity, Shape);

		virtual void renderScene(std::vector<entity::Entity*>*) = 0;

	};

} }