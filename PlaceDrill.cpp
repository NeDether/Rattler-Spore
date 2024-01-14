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
	App::ConsolePrintF("Landed...");
	FactoryManagerA.CreateBuilding(position, 0);
	
	return false;
}
