#pragma once

#include "event.h"

namespace Duggoo { namespace event {

	class KeyEvent : public Event
	{
	
	private:
		char key;

	public:
		KeyEvent(EventType t, char k) : Event(t), key(k) {}

		char getKey() { return key; }

	};

} }