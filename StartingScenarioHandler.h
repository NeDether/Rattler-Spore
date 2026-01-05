#pragma once

#include <Spore\BasicIncludes.h>

#define StartingScenarioHandlerPtr intrusive_ptr<StartingScenarioHandler>

class StartingScenarioHandler 
	: public Object
	, public DefaultRefCounted
	, public App::IUpdatable
{
public:
	static const uint32_t TYPE = id("StartingScenarioHandler");
	
	StartingScenarioHandler();
	~StartingScenarioHandler();


	int AddRef() override;
	int Release() override;
	void Update() override;
	void* Cast(uint32_t type) const override;
};
