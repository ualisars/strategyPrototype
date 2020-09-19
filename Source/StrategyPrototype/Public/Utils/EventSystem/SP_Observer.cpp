#include "SP_Observer.h"

void SP_Observer::SubscribeForEvent(const SP_EventType& EventType)
{
	if(!mEventTypes.Contains(EventType))
		mEventTypes.Add(EventType);
}

bool SP_Observer::IsSubscribedForEvent(const SP_EventType& EventType)
{
	return mEventTypes.Contains(EventType);
}

SP_Observer::SP_Observer()
{
}
