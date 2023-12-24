#include "stdafx.h"
#include "CategoryIcon.h"

CategoryIcon::CategoryIcon(UTFWin::IWindow* window, Category skibidi)
{
	mapItemWindow = window;
	myCat = skibidi;

	string16 products;
	products = u" ";
	mapItemWindow->FindWindowByID(id("zurgtasticZ"))->FindWindowByID(id("countZ"))->SetCaption(products.c_str());
}


CategoryIcon::~CategoryIcon()
{
}

// For internal use, do not modify.
int CategoryIcon::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int CategoryIcon::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void* CategoryIcon::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(IWinProc);
	CLASS_CAST(CategoryIcon);
	return nullptr;
}

// This method returns a combinations of values in UTFWin::EventFlags.
// The combination determines what types of events (messages) this window procedure receives.
// By default, it receives mouse/keyboard input and advanced messages.
int CategoryIcon::GetEventFlags() const
{
	return kEventFlagBasicInput | kEventFlagAdvanced;
}

// The method that receives the message. The first thing you should do is probably
// checking what kind of message was sent...
bool CategoryIcon::HandleUIMessage(IWindow* window, const Message& message)
{
	if (message.eventType == MessageType::kMsgButtonClick)
	{
		FabricatorSystemA.RenderRecipies(myCat.Cat);
		return true;
	}
	// Return true if the message was handled, and therefore no other window procedure should receive it.
	return false;
}
