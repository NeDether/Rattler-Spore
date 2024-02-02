#pragma once

#include <Spore\BasicIncludes.h>

#define SkondEmpirePtr intrusive_ptr<SkondEmpire>
#define SkondEmpireA (SkondEmpire::Get())[0]
using namespace Simulator;
///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new SkondEmpire(), SkondEmpire::NOUN_ID);
///

class SkondEmpire
	: public Simulator::cStrategy
{
public:
	static const uint32_t TYPE = id("RattlerSpore::SkondEmpire");
	static const uint32_t NOUN_ID = TYPE;
	cEmpirePtr Skond;
	int AddRef() override;
	int Release() override;
	void Initialize() override;
	void Dispose() override;
	const char* GetName() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool Read(Simulator::ISerializerStream* stream) override;
	void Update(int deltaTime, int deltaGameTime) override;
	bool WriteToXML(Simulator::XmlSerializer* writexml) override;
	static SkondEmpire* Get();
	uint32_t GetEmpireID();
	cStarRecordPtr Homeworld;
	//
	// You can add more methods here
	//

	static Simulator::Attribute ATTRIBUTES[];

private:
	static SkondEmpire* sInstance;
	//
	// You can add members here
	//
};