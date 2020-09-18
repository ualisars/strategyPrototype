#include "Utils/EventSystem/SP_Event.h"

SP_Event::SP_Event(const SP_EventType& Type)
 : mType(Type) {}

SP_EventType SP_Event::GetType() const
{
	return mType;
}
