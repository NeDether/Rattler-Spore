#pragma once
#include "stdafx.h"
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore\BasicIncludes.h>
#include <Spore/CommonIDs.h>
#include <Spore/Simulator/cSpaceToolData.h>
#include <Spore/Simulator/StarID.h>
#include <Spore/Simulator/SubSystem/StarManager.h>
#include <Spore/Simulator/cPlanetRecord.h>



#define MiningScannerPtr intrusive_ptr<MiningScanner>

class MiningScanner
	:public Simulator::cToolStrategy
{
public:

	MiningScanner(int john);
	~MiningScanner();
	bool OnHit(Simulator::cSpaceToolData* pTool, const Vector3& position, Simulator::SpaceToolHit hitType, int);
	virtual bool Update(Simulator::cSpaceToolData* pTool, bool showErrors, const char16_t** = nullptr);
	virtual bool OnSelect(Simulator::cSpaceToolData* pTool);
private:

	int power;
};
