#pragma once

#include "CoreMinimal.h"
#include "Utils/EventSystem/SP_Observer.h"
class STRATEGYPROTOTYPE_API SP_Subject
{
public:
	virtual void AddObserver(SP_Observer* Observer) = 0;

	virtual void RemoveObserver(SP_Observer* Observer) = 0;

	virtual void NotifyObservers() = 0;

};
