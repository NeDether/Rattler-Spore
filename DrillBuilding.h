#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore/Simulator/cSpatialObject.h>
#include <Spore/Simulator/cInteractableObject.h>
#include <Spore/Simulator/cGameData.h>

#define DrillBuildingPtr intrusive_ptr<DrillBuilding>

///
/// In your dllmain Initialize method, add the factory like this:
/// ClassManager.AddFactory(new DrillBuildingFactory());
///
/// Then you will be able to create instances of this class by doing:
/// auto obj = simulator_new<DrillBuilding>();

class DrillBuilding
	: //public Simulator::cSpatialObject , i have the iq of a fish
	public Simulator::cGameData
{
public:
	static const uint32_t TYPE = id("RattlerSpore::DrillBuilding");
	static const uint32_t NOUN_ID = TYPE;

	DrillBuilding(Vector3 pos); //Intitialized
	DrillBuilding();
	~DrillBuilding();

	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
	uint32_t GetCastID() const override;
	uint32_t GetNounID() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool WriteToXML(Simulator::XmlSerializer* writexml) override;
	bool Read(Simulator::ISerializerStream* stream) override;



	void init(Vector3 pos, uint32_t PlanetID);
	bool render();
	uint32_t getPlanetID();
	Vector3 getPosition();
	//
	// You can add more methods here
	//

	static Simulator::Attribute ATTRIBUTES[];

private:

	uint32_t pid;
	Vector3 position;
	cGameDataPtr modelPtr;
	//
	// You can add members here
	//
};

class DrillBuildingFactory
	: public App::ISPClassFactory
{
public:


	size_t GetTypes(uint32_t* pDstTypes, size_t count) const override;
	Object* Create(uint32_t type, ICoreAllocator* pAllocator) override;
	const char* GetName(uint32_t type) const override;
};

