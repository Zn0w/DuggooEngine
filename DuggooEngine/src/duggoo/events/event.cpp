#include "event.h"

namespace Duggoo { namespace event {

	Event::Event(EventType t)
		: type(t)
	{
		
	}

	Event::~Event()
	{	
		log(Duggoo::INFO, "Event processed");
	}

	EventType Event::getType()
	{
		return type;
	}

} }