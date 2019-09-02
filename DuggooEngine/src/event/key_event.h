#pragma once

#include "event.h"

namespace dg { namespace event {

	class KeyEvent : public Event
	{
		
	public:
		int key;

		KeyEvent(EventType t, int k)
			: Event(t)
		{
			key = k;
		}
	
	};

} }