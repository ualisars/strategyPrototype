#pragma once

#include "CoreMinimal.h"
#include "Utils/EventSystem/SP_Observer.h"
class STRATEGYPROTOTYPE_API SP_Subject
{
public:
	virtual void RegisterObserver(const SP_Observer& Observer) = 0;

	virtual void RemoveObserver(const SP_Observer& Observer) = 0;

	virtual void NotifyObserver() = 0;

};
