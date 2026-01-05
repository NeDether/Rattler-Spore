#include "stdafx.h"
#include "Craft.h"
#include "FabricatorSystem.h"
Craft::Craft()
{
}


Craft::~Craft()
{
}

// For internal use, do not modify.
int Craft::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int Craft::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void* Craft::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(IWinProc);
	CLASS_CAST(Craft);
	return nullptr;
}

// This method returns a combinations of values in UTFWin::EventFlags.
// The combination determines what types of events (messages) this window procedure receives.
// By default, it receives mouse/keyboard input and advanced messages.
int Craft::GetEventFlags() const
{
	return kEventFlagBasicInput | kEventFlagAdvanced;
}

// The method that receives the message. The first thing you should do is probably
// checking what kind of message was sent...
bool Craft::HandleUIMessage(IWindow* window, const Message& message)
{
	if (message.eventType == MessageType::kMsgButtonClick)
	{
		if (FabricatorSystemA.Fabricate(FabricatorSystemA.Selected)){
			FabricatorSystemA.SelectRecipe(FabricatorSystemA.Selected);
			return true;
		}
		
		return true;
		
	}
	// Return true if the message was handled, and therefore no other window procedure should receive it.
	return false;
	
	// Return true if the message was handled, and therefore no other window procedure should receive it.
	
}

//