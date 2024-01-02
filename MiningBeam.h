#pragma once
#include "stdafx.h"
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore\BasicIncludes.h>
#include <Spore/CommonIDs.h>
#include <Spore/Simulator/cSpaceToolData.h>
#include <Spore/Simulator/cDefaultBeamTool.h>
#include <Spore/Swarm/IEffectsWorld.h>
#include <Spore/Swarm/IEffectsManager.h>
#include <Spore/Swarm/EffectDirectory.h>
#include <Spore/Swarm/cEffectsManager.h>
#include <Spore/Swarm/cVisualEffect.h>
#include <Spore/Swarm/IVisualEffect.h>
#include <Spore/Simulator/StarID.h>
#include <Spore/Simulator/SubSystem/StarManager.h>
#include <Spore/Simulator/cPlanetRecord.h>
#include "AchievementSystem.h"


#define MiningBeamPtr intrusive_ptr<MiningBeam>

class MiningBeam 
	:public Simulator::cDefaultBeamTool
{
public:
	
	MiningBeam(int silly);
	~MiningBeam();


	bool OnHit(Simulator::cSpaceToolData* pTool, const Vector3& position, Simulator::SpaceToolHit hitType, int) override;
	void getPool(uint32_t seed, int k);
	virtual bool OnSelect(Simulator::cSpaceToolData* pTool) override;
private:

	int power;
};
