#include "stdafx.h"
#include "SolSysResourcesCheat.h"
#include "SolarSystemResources.h"
#include "VaultManager.h"
using namespace Simulator;
SolSysResourcesCheat::SolSysResourcesCheat()
{
}


SolSysResourcesCheat::~SolSysResourcesCheat()
{
}


void SolSysResourcesCheat::ParseLine(const ArgScript::Line& line)
{


	//CinematicManager.PlayCinematic("RSPORE_VaultDetector", 0, 0, 0, 0, 0);
	VaultManagerA.OpenVault(GetActivePlanetRecord());
	//CinematicManager.PlayCinematic("RSPORE_VAULTCUT", 0, 0, 0, 0, 0);
	//This will not work until the SolarSystemResources is re-added to DLLMAIN
	//SolarSystemResourcesA.OpenSysUI();
	//SolarSystemResourcesA.LogSystem();
	
	
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
}

const char* SolSysResourcesCheat::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat does something.";
	}
	else {
		return "SolSysResourcesCheat: Elaborate description of what this cheat does.";
	}
}
