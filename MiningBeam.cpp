#include "stdafx.h"
#include "MiningBeam.h"

MiningBeam::MiningBeam()
{
}


MiningBeam::~MiningBeam()
{
}

bool MiningBeam:: OnHit(Simulator::cSpaceToolData* pTool, const Vector3& position, Simulator::SpaceToolHit hitType, int) {
	App::ConsolePrintF("Mining!");
	SpaceTrading.ObtainTradingObject({ id("spice_mat_copper"), TypeIDs::prop, 0x034D97FA }, 1);
	return false;
}


bool MiningBeam::OnSelect(Simulator::cSpaceToolData* pTool)
{
	App::ConsolePrintF("Selected!");
	//SpaceTrading.ObtainTradingObject({ id("spice_mat_copper"), TypeIDs::prop, 0x034D97FA }, 1);
	return false;
}

