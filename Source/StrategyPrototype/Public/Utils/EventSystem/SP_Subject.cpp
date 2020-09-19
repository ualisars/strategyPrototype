#include "SP_Subject.h"

void SP_Subject::AddObserver(SP_Observer* Observer)
{
	mObservers.Add(Observer);
}

void SP_Subject::RemoveObserver(SP_Observer* Observer)
{
	mObservers.RemoveSingle(Observer);
}

void SP_Subject::NotifyObservers(const SP_EventType& EventType, const SP_Event& Event)
{
	UE_LOG(LogTemp, Warning, TEXT("Notify Observers"));
	for (SP_Observer* Observer : mObservers)
	{
		if (Observer->IsSubscribedForEvent(EventType))
		{
			Observer->Update(Event);
		}
	}
}

SP_Subject::~SP_Subject()
{}
