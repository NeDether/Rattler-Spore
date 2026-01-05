#pragma once

#include <Spore\BasicIncludes.h>
#include "SolarSystemResourceEntry.h"


#define SolarSystemResourcesPtr intrusive_ptr<SolarSystemResources>
#define SolarSystemResourcesA (SolarSystemResources::Get())[0]

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
	bool WriteToXML(Simulator::XmlSerializer* writexml) override;
	bool Read(Simulator::ISerializerStream* stream) override;
	void Update(int deltaTime, int deltaGameTime) override;

	bool OpenSysUI();
	bool CloseSysUI();


	//
	// im too lazy rn to fill this out so just pretebd this is full of functions and variables
	//foodh foodc enrg pop emp crime

	bool LogSystem(const uint32_t StarID);
	bool LogSystem();

	static Simulator::Attribute ATTRIBUTES[];
	static SolarSystemResources* Get();

private:
	static SolarSystemResources* sInstance;
	uint32_t SystemIn;
	UTFWin::UILayout* sysLayout;
};
