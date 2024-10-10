#pragma once

#include <Spore\BasicIncludes.h>

#define VaultManagerPtr intrusive_ptr<VaultManager>
#define VaultManagerA intrusive_ptr<VaultManager>

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




	static VaultManager* Get();
	
	static Simulator::Attribute ATTRIBUTES[];

private:
	static VaultManager* sInstance;
	//
	// You can add members here
	//
};