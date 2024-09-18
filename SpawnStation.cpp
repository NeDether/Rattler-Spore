#include "stdafx.h"
#include "SpawnStation.h"
using namespace Simulator;
SpawnStation::SpawnStation()
{
}


SpawnStation::~SpawnStation()
{
}


void SpawnStation::ParseLine(const ArgScript::Line& line)
{
	App::ConsolePrintF("''So THIS is Pibb Xtra... GHAHAHA!''");
	auto StarRecord = GetActiveStarRecord();
	PlanetID guh(StarRecord->GetID(), StarRecord->mPlanets.size());
	cPlanetPtr pibbxtra = nullptr;
	cPlanetRecordPtr okay = nullptr;
	cPlanetRecord::Create(guh, okay);
	auto orbulon = cEllipticalOrbit::cEllipticalOrbit();
	StarManager.GenerateEllipticalOrbit(StarRecord,orbulon,0.5,5.0,GetActivePlanetRecord());
	orbulon.Precalculate();
	okay.get()->mOrbit = orbulon;
	okay.get()->mName = (string16) "Space Station";
	auto rizz = okay.get()->GenerateTerrainKey();
	okay.get()->SetGeneratedTerrainKey(rizz);
	
	StarRecord->mPlanets.push_back(okay);
	
	StarManager.RecordToPlanet(okay.get(), pibbxtra);

	// This method is called when your cheat is invoked.
	// Put your cheat code here.
}

const char* SpawnStation::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat creates a new space station orbiting the planet you are hovering over.";
	}
	else {
		return "SpawnStation: Debug Rattlerspore command, creates a space station orbiting the planet you are near.";
	}
}
