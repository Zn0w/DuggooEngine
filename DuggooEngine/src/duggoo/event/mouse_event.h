#pragma once

#include "event.h"

namespace dg { namespace event {

	class MouseButtonEvent : public Event
	{
		
	public:
		int x, y;
		char button;

		MouseButtonEvent(EventType t, int xPos, int yPos, char b)
			: Event(t)
		{
			x = xPos;
			y = yPos;
			button = b;
		}

	};

	class MouseMoveEvent : public Event
	{

	public:
		int x, y, offsetX, offsetY;

		MouseMoveEvent(EventType t, int xPos, int yPos, int offX, int offY)
			: Event(t)
		{
			x = xPos;
			y = yPos;
			offsetX = offX;
			offsetY = offY;
		}

	};

	class MouseScrollEvent : public Event
	{

	public:
		int x, y;

		MouseScrollEvent(EventType t, int xPos, int yPos)
			: Event(t)
		{
			x = xPos;
			y = yPos;
		}

	};

} }