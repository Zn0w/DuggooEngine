#pragma once

namespace dg { namespace graphics {

	class Buffer
	{
	protected:
		unsigned int bufferId;
		unsigned componentCount;		// The number of elements in one component, e.g. 2.0f, 5.0f, -1.5f, 3.5f can be a 1 vec4, or two vec2s, so the component count specifies it
	public:
		Buffer(float* data, int count, unsigned int s_componentCount);

		virtual void bind() = 0;		// Select this buffer (a specific buffer will be selected to be used)
		virtual void unbind() = 0;		// Unselect the buffer

		unsigned int getComponentCount() { return componentCount; }
	};

} }