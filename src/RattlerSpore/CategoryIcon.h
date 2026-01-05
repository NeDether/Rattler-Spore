#pragma once

#include <Spore\BasicIncludes.h>
#include "FabricatorSystem.h"
#include "Craft.h"
#define CategoryIconPtr intrusive_ptr<CategoryIcon>

// To avoid repeating UTFWin:: all the time.
using namespace UTFWin;

class CategoryIcon 
	: public IWinProc
	, public DefaultRefCounted
{
public:
	static const uint32_t TYPE = id("CategoryIcon");
	
	CategoryIcon(UTFWin::IWindow* window, Category skibidi);
	~CategoryIcon();

	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
	
	int GetEventFlags() const override;
	// This is the function you have to implement, called when a window you added this winproc to received an event
	bool HandleUIMessage(IWindow* pWindow, const Message& message) override;

private:
	Category myCat;
	UTFWin::IWindow* mapItemWindow;
	string16 mapError;
	UTFWin::Tooltip* myTooltip;
};
