#pragma once

#include <Spore\BasicIncludes.h>

#define PlaceDrillPtr intrusive_ptr<PlaceDrill>

class PlaceDrill 
	:public Simulator::cToolStrategy
{
public:
	static const uint32_t TYPE = id("PlaceDrill");
	
	PlaceDrill();
	~PlaceDrill();

	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
};
