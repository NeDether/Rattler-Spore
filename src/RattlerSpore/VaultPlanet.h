#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore/Simulator/cGameData.h>


#define VaultPlanetPtr intrusive_ptr<VaultPlanet>

///
/// In your dllmain Initialize method, add the factory like this:
/// ClassManager.AddFactory(new VaultPlanetFactory());
///
/// Then you will be able to create instances of this class by doing:
/// auto obj = simulator_new<VaultPlanet>();

class VaultPlanet
	: public Simulator::cGameData
{
public:
	static const uint32_t TYPE = id("RattlerSpore::VaultPlanet");
	static const uint32_t NOUN_ID = TYPE;

	VaultPlanet(uint32_t pID);
	VaultPlanet();
	~VaultPlanet();


	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
	uint32_t GetCastID() const override;
	uint32_t GetNounID() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool WriteToXML(Simulator::XmlSerializer* writexml) override;
	bool Read(Simulator::ISerializerStream* stream) override;
	

	void init(uint32_t pid);
	uint32_t GetPlanetID();

	static Simulator::Attribute ATTRIBUTES[];

private:

	uint32_t planetOn;
	bool looted;
	bool scanned;
	//
	// You can add members here
	//
};

class VaultPlanetFactory
	: public App::ISPClassFactory
{
public:
	size_t GetTypes(uint32_t* pDstTypes, size_t count) const override;
	Object* Create(uint32_t type, ICoreAllocator* pAllocator) override;
	const char* GetName(uint32_t type) const override;
};

