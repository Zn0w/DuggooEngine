#pragma once

#include "event.h"

namespace dg { namespace event {

	class MouseButtonEvent : public Event
	{
		
	public:
		int x, y;
		int button;

		MouseButtonEvent(EventType t, int xPos, int yPos, int b)
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
		int x, y;

		MouseMoveEvent(EventType t, int xPos, int yPos)
			: Event(t)
		{
			x = xPos;
			y = yPos;
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