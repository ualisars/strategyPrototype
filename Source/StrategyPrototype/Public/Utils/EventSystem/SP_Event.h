#pragma once

#include "CoreMinimal.h"

enum class SP_EventType : uint8
{
	FightOccured
};

class STRATEGYPROTOTYPE_API SP_Event
{
	SP_EventType mType;

protected:
	SP_Event(const SP_EventType& Type);

public:
	SP_EventType GetType() const;
};
