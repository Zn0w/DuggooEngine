#pragma once

#include "event.h"

namespace Duggoo { namespace event {
	
	class WindowEvent : public Event
	{
		
	private:
		int new_width, new_height;

	public:
		WindowEvent(EventType t) : Event(t) {}
		WindowEvent(EventType t, int nw, int nh) : Event(t), new_width(nw), new_height(nh) {}

		int getNewWidth() { return new_width; }
		int getNewHeight() { return new_height; }

	};

} }