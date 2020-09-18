#pragma once

#include "CoreMinimal.h"
#include "Utils/EventSystem/SP_Event.h"

class STRATEGYPROTOTYPE_API SP_Observer
{
	TArray<SP_EventType> mEventTypes;
public:
	virtual void Update(const SP_Event& Event) = 0;

	void SubscribeForEvent(const SP_EventType& EventType);

	bool IsSubscribedForEvent(const SP_EventType& EventType);
};
