#pragma once

#include "CoreMinimal.h"
#include "Utils/EventSystem/SP_Event.h"

class STRATEGYPROTOTYPE_API SP_EventListener
{
	TArray<SP_EventType> mEventTypes;

public:
	virtual ~SP_EventListener();

	virtual void OnEvent(const SP_Event& Event) = 0;

	void SubscribeForEvent(const SP_EventType& EventType);

	bool IsSubscribedForEvent(const SP_EventType& EventType);
};
