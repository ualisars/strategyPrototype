#include "Utils/EventSystem/SP_EventDispatcher.h"

void SP_EventDispatcher::AddListener(SP_EventListener* Listener)
{
	mListeners.Add(Listener);
}

void SP_EventDispatcher::RemoveListener(SP_EventListener* Listener)
{
	mListeners.RemoveSingle(Listener);
}

void SP_EventDispatcher::Dispatch(const SP_EventType & EventType, const SP_Event & Event)
{
	UE_LOG(LogTemp, Warning, TEXT("Dispatch"));
	for (SP_EventListener* Listener : mListeners)
	{
		if (Listener->IsSubscribedForEvent(EventType))
		{
			Listener->OnEvent(Event);
		}
	}
}
