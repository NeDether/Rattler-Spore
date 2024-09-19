#include "stdafx.h"
#include "ReadPlanet.h"
using namespace Simulator;
ReadPlanet::ReadPlanet()
{
}


ReadPlanet::~ReadPlanet()
{
}


void ReadPlanet::ParseLine(const ArgScript::Line& line)
{
	auto StarRecord = GetActiveStarRecord();
	auto PlanetRecord = GetActivePlanetRecord();
	auto Planet = GetActivePlanet();
	PlanetRecord->mType = PlanetType::T3;
	PlanetRecord->mAtmosphereScore = 0.5;
	PlanetRecord->mTemperatureScore = 0.5;
	
	//Planet->mEffectScript = 0x3c3d344f;
	auto newterrain = PlanetRecord->GenerateTerrainKey();
	PlanetRecord->SetGeneratedTerrainKey(newterrain);
	App::ConsolePrintF("planets: %d ", StarRecord->mPlanets.size());
	App::ConsolePrintF("tech level: %d ", PlanetRecord->GetTechLevel());
	PlanetRecord->GetStarRecord();
	
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
}

const char* ReadPlanet::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat does something.";
	}
	else {
		return "ReadPlanet: Elaborate description of what this cheat does.";
	}
}
