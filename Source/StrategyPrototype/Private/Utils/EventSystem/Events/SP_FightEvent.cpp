#include "Utils/EventSystem/Events/SP_FightEvent.h"

SP_FightEvent::SP_FightEvent()
 : SP_Event(SP_EventType::FightOccured) {}

SP_FightEvent::~SP_FightEvent()
{
}
