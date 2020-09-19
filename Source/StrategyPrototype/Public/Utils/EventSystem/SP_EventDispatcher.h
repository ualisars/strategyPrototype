#pragma once

#include "CoreMinimal.h"
#include "Utils/EventSystem/SP_EventListener.h"
#include "Utils/EventSystem/SP_Event.h"

class STRATEGYPROTOTYPE_API SP_EventDispatcher
{
	TArray<SP_EventListener*> mListeners;

public:
	void AddListener(SP_EventListener* Listener);

	void RemoveListener(SP_EventListener* Listener);

	void Dispatch(const SP_EventType& EventType, const SP_Event& Event);
};
