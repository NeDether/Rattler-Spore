#pragma once

#include <Spore\BasicIncludes.h>
#include "FabricatorSystem.h"
#include "Craft.h"
#define RecipeIconPtr intrusive_ptr<RecipeIcon>

// To avoid repeating UTFWin:: all the time.
using namespace UTFWin;

class RecipeIcon 
	: public IWinProc
	, public DefaultRefCounted
{
public:
	static const uint32_t TYPE = id("RecipeIcon");
	
	RecipeIcon(UTFWin::IWindow* window, Recipe juh);
	~RecipeIcon();

	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
	
	int GetEventFlags() const override;
	// This is the function you have to implement, called when a window you added this winproc to received an event
	bool HandleUIMessage(IWindow* pWindow, const Message& message) override;

private:
	Recipe myRecipe;
	UTFWin::IWindow* mapItemWindow;
	string16 mapError;
	UTFWin::Tooltip* myTooltip;

};
