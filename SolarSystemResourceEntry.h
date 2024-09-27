#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore/Simulator/cGameData.h>


#define SolarSystemResourceEntryPtr intrusive_ptr<SolarSystemResourceEntry>

///
/// In your dllmain Initialize method, add the factory like this:
/// ClassManager.AddFactory(new SolarSystemResourceEntryFactory());
///
/// Then you will be able to create instances of this class by doing:
/// auto obj = simulator_new<SolarSystemResourceEntry>();

class SolarSystemResourceEntry
	: public Simulator::cGameData
{
public:
	static const uint32_t TYPE = id("RattlerSpore::SolarSystemResourceEntry");
	static const uint32_t NOUN_ID = TYPE;

	SolarSystemResourceEntry(uint32_t StarID);
	SolarSystemResourceEntry();
	~SolarSystemResourceEntry();


	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
	uint32_t GetCastID() const override;
	uint32_t GetNounID() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool WriteToXML(Simulator::XmlSerializer* writexml) override;
	bool Read(Simulator::ISerializerStream* stream) override;

	//How it feels to set people on fire.

	void init(uint32_t StarID);
	int GetEnergy();
	bool SetEnergy(int value);
	int GetEnergyCap();
	bool SetEnergyCap(int value);
	float GetEnergyPercentage();
	static Simulator::Attribute ATTRIBUTES[];

private:

	uint32_t SystemID;
	int energy;
	int energycap;


	//Ok so what if there is a hidden stat that keeps track of how many times the player leaves their seat and goes to the bathroom.
};

class SolarSystemResourceEntryFactory
	: public App::ISPClassFactory
{
public:
	size_t GetTypes(uint32_t* pDstTypes, size_t count) const override;
	Object* Create(uint32_t type, ICoreAllocator* pAllocator) override;
	const char* GetName(uint32_t type) const override;
};

