#include "stdafx.h"
#include "SolSysResourcesCheat.h"
#include "SolarSystemResources.h"

SolSysResourcesCheat::SolSysResourcesCheat()
{
}


SolSysResourcesCheat::~SolSysResourcesCheat()
{
}


void SolSysResourcesCheat::ParseLine(const ArgScript::Line& line)
{
	

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
