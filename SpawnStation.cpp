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
	App::ConsolePrintF("sensible and readable debug text indicating this is working :):)");
	auto StarRecord = GetActiveStarRecord();
	PlanetID stationID(StarRecord->GetID(), StarRecord->mPlanets.size());
	cPlanetPtr newPlanPointer = nullptr;
	cPlanetRecordPtr newPlanRec = nullptr;
	newPlanRec.get()->Create(stationID, newPlanRec);
	auto orbulon = cEllipticalOrbit::cEllipticalOrbit();
	StarManager.GenerateEllipticalOrbit(StarRecord,orbulon,50,200,GetActivePlanetRecord());
	newPlanRec.get()->mOrbit = orbulon;
	
	newPlanRec.get()->mType = PlanetType::GasGiant;
	newPlanRec.get()->mName = u"Space Station";
	//auto newterrain = newPlanRec.get()->GenerateTerrainKey();
	//newPlanRec.get()->SetGeneratedTerrainKey(newterrain);
	
	
	
	StarManager.RecordToPlanet(newPlanRec.get(), newPlanPointer);
	newPlanPointer.get()->SetRepresentationMode(PlanetRepresentationMode::VisiblePlanetAndHitSphere);
	newPlanPointer.get()->SetModelKey({ id("ep1_ci_spice_pumpstation"), TypeIDs::prop, GroupIDs::CivicObjects });
	
	newPlanPointer.get()->SetIsOnView(true);
	

	newPlanPointer.get()->SetIsSelected(true);
	StarRecord->mPlanets.push_back(newPlanRec);
	StarRecord->mPlanetCount += 1;
	StarRecord->GetPlanetRecords();
	//cPlanetRecord debugGetter = *StarRecord->GetPlanetRecord(StarRecord->mPlanets.size());
	//debugGetter.mTechLevel
	App::ConsolePrintF("planets: %d ", StarRecord->mPlanets.size());
	newPlanPointer.get()->mEffectScript = 0x3c3d344f;
	
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
