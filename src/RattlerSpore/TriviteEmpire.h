#pragma once

#include <Spore\BasicIncludes.h>

#define TriviteEmpirePtr intrusive_ptr<TriviteEmpire>
#define TriviteEmpireA (TriviteEmpire::Get())[0]
using namespace Simulator;
///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new TriviteEmpire(), TriviteEmpire::NOUN_ID);
///

class TriviteEmpire
	: public Simulator::cStrategy
{
public:
	static const uint32_t TYPE = id("RattlerSpore::TriviteEmpire");
	static const uint32_t NOUN_ID = TYPE;
	cEmpirePtr Trivite;
	int AddRef() override;
	int Release() override;
	void Initialize() override;
	void Dispose() override;
	const char* GetName() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool Read(Simulator::ISerializerStream* stream) override;
	void Update(int deltaTime, int deltaGameTime) override;
	bool WriteToXML(Simulator::XmlSerializer* writexml) override;
	static TriviteEmpire* Get();
	uint32_t GetEmpireID();
	cStarRecordPtr Homeworld;
	//
	// You can add more methods here
	//

	static Simulator::Attribute ATTRIBUTES[];

private:
	static TriviteEmpire* sInstance;
	//
	// You can add members here
	//
};