#pragma once

namespace dg { namespace event {

	enum EventType
	{
		KEY_PRESS,
		KEY_RELEASE,
		KEY_TYPE,

		MOUSE_PRESS,
		MOUSE_RELEASE,
		MOUSE_POSITION,
		MOUSE_SCROLL,

		WINDOW_RESIZE,
		WINDOW_CLOSE,
		WINDOW_FOCUS,
		WINDOW_LOSTFOCUS,
		WINDOW_MOVE
	};

	class Event
	{

	public:
		bool processed;
		EventType type;

		Event(EventType t)
		{
			type = t;
		}

	};

} }