#include "stdafx.h"
#include "ResourceIcon.h"


ResourceIcon::ResourceIcon(UTFWin::IWindow* window, uint32_t juh, uint32_t needed)
{
	mapItemWindow = window;
	myResource = juh;
	mapError = u"";

	string16 products;
	products.assign_convert(to_string(needed));
	
	if (PropManager.HasPropertyList(id("creativeTools"), id("rattlerConfig"))) {
		products = u" Free";
	
	}
	else if(needed == 0) {
		products = u" ";
	
	}
	else {
		products = u" x" + products;
	
	}
	
	mapItemWindow->FindWindowByID(id("zurgtastic"))->FindWindowByID(id("count"))->SetCaption(products.c_str());
	PropertyListPtr sillyPropList;
	PropManager.GetPropertyList(myResource, 0x034d97fa, sillyPropList);

	LocalizedString silly;
	LocalizedString verySilly;
	(App::Property::GetText(sillyPropList.get(), 0x3068D95D, silly));
	(App::Property::GetText(sillyPropList.get(), 0x04CAD19B, verySilly));
	myTooltip = UTFWin::CreateTooltip(silly.GetText(), verySilly.GetText());
	window->FindWindowByID(id("zurgtastic"))->AddWinProc(myTooltip);
	
}

ResourceIcon::~ResourceIcon()
{
}

// For internal use, do not modify.
int ResourceIcon::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int ResourceIcon::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void* ResourceIcon::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(IWinProc);
	CLASS_CAST(ResourceIcon);
	return nullptr;
}

// This method returns a combinations of values in UTFWin::EventFlags.
// The combination determines what types of events (messages) this window procedure receives.
// By default, it receives mouse/keyboard input and advanced messages.
int ResourceIcon::GetEventFlags() const
{
	return kEventFlagBasicInput | kEventFlagAdvanced;
}

// The method that receives the message. The first thing you should do is probably
// checking what kind of message was sent...
bool ResourceIcon::HandleUIMessage(IWindow* window, const Message& message)
{
	if (message.eventType == MessageType::kMsgButtonClick)
	{
		return true;
	}
	// Return true if the message was handled, and therefore no other window procedure should receive it.
	return false;
}
