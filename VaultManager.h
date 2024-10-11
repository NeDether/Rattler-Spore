#pragma once

#include <Spore\BasicIncludes.h>
#include "VaultPlanet.h"

#define VaultManagerPtr intrusive_ptr<VaultManager>
#define VaultManagerA (VaultManager::Get())[0]

///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new VaultManager(), VaultManager::NOUN_ID);
///

class VaultManager
	: public Simulator::cStrategy
{
public:
	static const uint32_t TYPE = id("RattlerSpore::VaultManager");
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


	bool GenerateVault(cStarRecordPtr StrRecord);

	static VaultManager* Get();


	static Simulator::Attribute ATTRIBUTES[];

	bool isVaultPlanet(uint32_t PlanetID);
	

private:

	static VaultManager* sInstance;
	bool cutsceneSeti;
	vector<uint32_t> vaultplanets;
	//
	// You can add members here
	//
};