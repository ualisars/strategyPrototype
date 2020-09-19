#pragma once

#include "CoreMinimal.h"
#include "Utils/EventSystem/SP_Observer.h"
#include "Utils/EventSystem/SP_Event.h"

class STRATEGYPROTOTYPE_API SP_Subject
{
	TArray<SP_Observer*> mObservers;

public:
	virtual void AddObserver(SP_Observer* Observer);

	virtual void RemoveObserver(SP_Observer* Observer);

	virtual void NotifyObservers(const SP_EventType& EventType, const SP_Event& Event);

	virtual ~SP_Subject();

	SP_Subject();
};
