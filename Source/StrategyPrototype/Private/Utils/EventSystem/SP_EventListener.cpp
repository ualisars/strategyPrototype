#include "Utils/EventSystem/SP_EventListener.h"

SP_EventListener::~SP_EventListener()
{}

void SP_EventListener::SubscribeForEvent(const SP_EventType & EventType)
{
	if (!mEventTypes.Contains(EventType))
		mEventTypes.Add(EventType);
}

bool SP_EventListener::IsSubscribedForEvent(const SP_EventType & EventType)
{
	return mEventTypes.Contains(EventType);
}
