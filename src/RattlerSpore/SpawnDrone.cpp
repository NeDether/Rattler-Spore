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
	
	cGameDataUFO* drone = CreateUFO(UfoType::SecurityDrone, nullptr );
	//drone->SetModelKey({ 0x2538FB35, TypeIDs::ufo, GroupIDs::UFOModels});
	drone->SetModelKey({ 0x25A8E66C, TypeIDs::ufo, GroupIDs::UFOModels });
	drone->SetTarget(GetPlayerUFO());
	drone->SetScale(5.0);
	drone->SetDesiredSpeed(0.2, 1);
	drone->mStandardSpeed =(0.3);
	drone->mMaxHealthPoints = 20000;
	drone->Heal(true);
	ToolManager.LoadTool(ResourceKey({ 0x1a8de7dd, 0, 0 }), drone->mpNPCFarAirWeapon);
	ToolManager.LoadTool(ResourceKey({ 0xfc22027a, 0, 0 }), drone->mpNPCMediumAirWeapon);

	ToolManager.LoadTool(ResourceKey({ 0x3a8ad016, 0, 0 }), drone->mpNPCNearAirWeapon);
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
