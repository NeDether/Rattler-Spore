#pragma once
#include "stdafx.h"
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore\BasicIncludes.h>
#include <Spore/CommonIDs.h>
#include <Spore/Simulator/cSpaceToolData.h>




#define Fabricator intrusive_ptr<Fabricator>

class Fabricator
	:public Simulator::cToolStrategy
{
public:

	Fabricator();
	~Fabricator();
	bool OnHit(Simulator::cSpaceToolData* pTool, const Vector3& position, Simulator::SpaceToolHit hitType, int);
	virtual bool Update(Simulator::cSpaceToolData* pTool, bool showErrors, const char16_t** = nullptr);
	virtual bool OnSelect(Simulator::cSpaceToolData* pTool);

};
