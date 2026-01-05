#include "stdafx.h"
#include "PlaceDrill.h"
#include "DrillBuilding.h"
#include <Spore/Simulator/cGameplayMarker.h>
#include <Spore/Simulator/cGameTerrainCursor.h>

using namespace Simulator;


PlaceDrill::PlaceDrill()
{
}


PlaceDrill::~PlaceDrill()
{
}

// For internal use, do not modify.
int PlaceDrill::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int PlaceDrill::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void* PlaceDrill::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(PlaceDrill);
	return nullptr;
}



bool PlaceDrill::OnHit(Simulator::cSpaceToolData* pTool, const Vector3& position, Simulator::SpaceToolHit hitType, int)
{
	
	
	return false;
}

bool PlaceDrill::OnSelect(cSpaceToolData* pTool)
{
	App::ConsolePrintF("sensible and readable debug text indicating this is working :):)");
	auto StarRecord = GetActiveStarRecord();
	PlanetID stationID(StarRecord->GetID(), StarRecord->mPlanets.size());
	cPlanetPtr newPlanPointer = nullptr;
	cPlanetRecordPtr newPlanRec = nullptr;
	newPlanRec.get()->Create(stationID, newPlanRec);
	auto orbulon = cEllipticalOrbit::cEllipticalOrbit();
	StarManager.GenerateEllipticalOrbit(StarRecord, orbulon, 50, 200, GetActivePlanetRecord());
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
	return false;
}