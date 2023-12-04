#include "stdafx.h"
#include "RecipeIcon.h"


RecipeIcon::RecipeIcon(UTFWin::IWindow* window, Recipe juh)
{
	mapItemWindow = window;
	mapRecipe = juh;
	mapError = u"";

	string16 products;
	products.assign_convert(to_string(mapRecipe.productAmount));
	products = u" x" + products;
	mapItemWindow->FindWindowByID(id("count"))->SetCaption(products.c_str());

}

RecipeIcon::~RecipeIcon()
{
}

// For internal use, do not modify.
int RecipeIcon::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int RecipeIcon::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void* RecipeIcon::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(IWinProc);
	CLASS_CAST(RecipeIcon);
	return nullptr;
}

// This method returns a combinations of values in UTFWin::EventFlags.
// The combination determines what types of events (messages) this window procedure receives.
// By default, it receives mouse/keyboard input and advanced messages.
int RecipeIcon::GetEventFlags() const
{
	return kEventFlagBasicInput | kEventFlagAdvanced;
}

// The method that receives the message. The first thing you should do is probably
// checking what kind of message was sent...
bool RecipeIcon::HandleUIMessage(IWindow* window, const Message& message)
{
	
	// Return true if the message was handled, and therefore no other window procedure should receive it.
	return false;
}
