#pragma once

#include "event.h"

namespace dg { namespace event {

	class MouseEvent : public Event
	{
		
	public:
		int x, y, offsetX, offsetY;
		char button;

		MouseEvent(EventType t, int xPos, int yPos, char b)		// for MOUSE_PRESS and MOUSE_RELEASE
			: Event(t)
		{
			x = xPos;
			y = yPos;
			button = b;
		}

		MouseEvent(EventType t, int xPos, int yPos, int offX, int offY)		// for MOUSE_MOVE
			: Event(t)
		{
			x = xPos;
			y = yPos;
			offsetX = offX;
			offsetY = offY;
		}

		MouseEvent(EventType t, int xPos, int yPos)		// for MOUSE_SCROLL
			: Event(t)
		{
			x = xPos;
			y = yPos;
		}

	};

} }