#pragma once

#include <Spore\BasicIncludes.h>
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore/CommonIDs.h>
#include <Spore/Simulator/cSpaceToolData.h>
#include <Spore/Simulator/SimulatorEnums.h>
#include <Spore/Simulator/cSimulatorSpaceGame.h>
#include <Spore/Simulator/cPlayerInventory.h>
#include <Spore/ResourceKey.h>
#define CraftPtr intrusive_ptr<Craft>

// To avoid repeating UTFWin:: all the time.
using namespace UTFWin;

class Craft 
	: public IWinProc
	, public DefaultRefCounted
{
public:
	
	Craft();
	~Craft();

	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
	
	int GetEventFlags() const override;
	// This is the function you have to implement, called when a window you added this winproc to received an event
	bool HandleUIMessage(IWindow* pWindow, const Message& message) override;

	
};
