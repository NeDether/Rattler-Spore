#include "stdafx.h"
#include "SpawnDrone.h"
using namespace Simulator;
SpawnDrone::SpawnDrone()
{
}


SpawnDrone::~SpawnDrone()
{
}


void SpawnDrone::ParseLine(const ArgScript::Line& line)
{
	
	cGameDataUFO* drone = CreateUFO(UfoType(11), StarManager.GetEmpire(0));
	drone->field_7E0 = u"Ra'Tal Eclipse Sentinel";
	//drone->mMaxHealthPoints = 14000;
	//drone->Heal(true);

	
}

const char* SpawnDrone::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat does something.";
	}
	else {
		return "SpawnDrone: Elaborate description of what this cheat does.";
	}
}
