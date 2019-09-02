#include "gl_simple_2d_renderer.h"

namespace dg { namespace graphics {

	void SimpleRenderer2D::submit(Renderable2D* renderable)
	{
		renderQueue.push_back(renderable);
	}

	void SimpleRenderer2D::flush()
	{
		while (!renderQueue.empty())
		{
			Renderable2D* renderable = renderQueue.front();
			renderable->getVAO()->bind();
			renderable->getIBO()->bind();
			
			glDrawElements(GL_TRIANGLES, renderable->getIBO()->getCount(), GL_UNSIGNED_SHORT, nullptr);
			
			renderable->getIBO()->unbind();
			renderable->getVAO()->unbind();
		}
	}

} }