#pragma once

#include <Spore\BasicIncludes.h>
#include "DrillBuilding.h"
#include <Spore/Simulator/cSpatialObject.h>
#include <Spore/Simulator/cInteractableObject.h>
#include <Spore/Simulator/cGameData.h>
#define FactoryManagerPtr intrusive_ptr<FactoryManager>
#define FactoryManagerA (FactoryManager::Get())[0]


///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new FactoryManager(), FactoryManager::NOUN_ID);
///

class FactoryManager
	: public Simulator::cStrategy
{
public:
	static const uint32_t TYPE = id("RattlerSpore::FactoryManager");
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
	
	//
	// You can add more methods here
	//

	bool CreateBuilding(const Vector3& position, uint32_t buildingType);

	static Simulator::Attribute ATTRIBUTES[];
	static FactoryManager* Get();
	

private:
	//
	// You can add members here
	//
	
	bool LoadPlanet = false;
	static FactoryManager* sInstance;
	vector<DrillBuildingPtr> SavedBuildings;
};