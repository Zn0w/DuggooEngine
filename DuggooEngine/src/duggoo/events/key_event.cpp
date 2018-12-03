#include "key_event.h"

namespace Duggoo { namespace event {

	KeyEvent::KeyEvent(EventType t, char k)
		: Event(t), key(k)
	{
		
	}

} }