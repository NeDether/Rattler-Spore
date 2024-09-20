#pragma once

#include <Spore\BasicIncludes.h>

#define SolarSystemResourcesPtr intrusive_ptr<SolarSystemResources>

///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new SolarSystemResources(), SolarSystemResources::NOUN_ID);
///

class SolarSystemResources
	: public Simulator::cStrategy
{
public:
	static const uint32_t TYPE = id("RattlerSpore::SolarSystemResources");
	static const uint32_t NOUN_ID = TYPE;

	int AddRef() override;
	int Release() override;
	void Initialize() override;
	void Dispose() override;
	const char* GetName() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool Read(Simulator::ISerializerStream* stream) override;
	void Update(int deltaTime, int deltaGameTime) override;

	//
	// im too lazy rn to fill this out so just pretebd this is full of functions and variables
	//foodh foodc enrg pop emp crime

	static Simulator::Attribute ATTRIBUTES[];

private:
	//
	// You can add members here
	//
};