#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\Simulator\cPlaceObjectToolStrategy.h>
#include "Spore\Simulator\cSpatialObject.h"
#include "FactoryManager.h"

#define PlaceDrillPtr intrusive_ptr<PlaceDrill>

class PlaceDrill 
	:public Simulator::cPlaceObjectToolStrategy
{
public:
	static const uint32_t TYPE = id("PlaceDrill");
	
	PlaceDrill();
	~PlaceDrill();

	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;

	bool OnHit(Simulator::cSpaceToolData* pTool, const Vector3& position, Simulator::SpaceToolHit hitType, int) override;
};
