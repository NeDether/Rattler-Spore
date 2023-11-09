#pragma once
#include "stdafx.h"
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore\BasicIncludes.h>
#include <Spore/Simulator/cSpaceToolData.h>
#include <Spore/Simulator/cDefaultBeamTool.h>

#define MiningBeamPtr intrusive_ptr<MiningBeam>

class MiningBeam 
	:public Simulator::cDefaultBeamTool
{
public:
	
	MiningBeam();
	~MiningBeam();


	bool OnHit(Simulator::cSpaceToolData* pTool, const Vector3& position, Simulator::SpaceToolHit hitType, int) override;
	virtual bool OnSelect(Simulator::cSpaceToolData* pTool) override;

};
