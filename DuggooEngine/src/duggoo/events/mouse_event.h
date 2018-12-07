#pragma once

#include "event.h"

namespace Duggoo { namespace event {
	
	class MouseEvent : public Event
	{
	
	private:
		int x, y;
		char button;

	public:
		MouseEvent(EventType t, int x_pos, int y_pos, char b) : Event(t), x(x_pos), y(y_pos), button(b) {}

		int getX() { return x; }
		int getY() { return y; }
		char getButton() { return button; }
	};

} }