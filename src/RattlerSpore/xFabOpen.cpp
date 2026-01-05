#include "stdafx.h"
#include "xFabOpen.h"
#include "FabricatorSystem.h"

xFabOpen::xFabOpen()
{
}


xFabOpen::~xFabOpen()
{
}

// For internal use, do not modify.
int xFabOpen::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int xFabOpen::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void* xFabOpen::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(IWinProc);
	CLASS_CAST(xFabOpen);
	return nullptr;
}

// This method returns a combinations of values in UTFWin::EventFlags.
// The combination determines what types of events (messages) this window procedure receives.
// By default, it receives mouse/keyboard input and advanced messages.
int xFabOpen::GetEventFlags() const
{
	return kEventFlagBasicInput | kEventFlagAdvanced;
}

// The method that receives the message. The first thing you should do is probably
// checking what kind of message was sent...
bool xFabOpen::HandleUIMessage(IWindow* window, const Message& message)
{

	return FabricatorSystemA.OpenFab(true);
	// Return true if the message was handled, and therefore no other window procedure should receive it.
}

void xFabOpen::hell() {

	FabricatorSystemA.OpenFab(true);
}
