#pragma once

#include "event.h"

namespace dg { namespace event {

	class KeyEvent : public Event
	{
		
	public:
		char key;

		KeyEvent(EventType t, char k)
			: Event(t)
		{
			key = k;
		}
	
	};

} }