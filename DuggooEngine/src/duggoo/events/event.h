#pragma once

#include <vector>

#include "../log/log.h"

namespace Duggoo { namespace event {

	enum EventType
	{
		WINDOW_RESIZE,
		WINDOW_CLOSE,
		WINDOW_FOCUS,
		WINDOW_LOST_FOCUS,

		KEY_PRESSED,
		KEY_RELEASED,

		MOUSE_MOVED,
		MOUSE_BUTTON_PRESSED,
		MOUSE_BUTTON_RELEASED,
		MOUSE_SCROLL_BUTTON
	};
	
	class Event
	{
	
	protected:
		EventType type;

	public:
		Event(EventType t) : type(t) {}
		~Event() { log(Duggoo::INFO, "Event processed"); }

		EventType getType() { return type; }

	};

	struct EventQueue
	{
		static std::vector<Event> event_queue;
	};

} }