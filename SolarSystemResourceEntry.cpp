#include "stdafx.h"
#include "SolarSystemResourceEntry.h"

/// AUTOGENERATED METHODS ///

size_t SolarSystemResourceEntryFactory::GetTypes(uint32_t* pDstTypes, size_t count) const {
	if (count >= 1) {
		pDstTypes[0] = SolarSystemResourceEntry::NOUN_ID;
		return 1;
	}
	return 0;
}
Object* SolarSystemResourceEntryFactory::Create(uint32_t type, ICoreAllocator* pAllocator) {
	return new SolarSystemResourceEntry();
}
const char* SolarSystemResourceEntryFactory::GetName(uint32_t type) const {
	return "SolarSystemResourceEntry";
}


SolarSystemResourceEntry::SolarSystemResourceEntry(uint32_t StarID)
{
	init(StarID);

}

SolarSystemResourceEntry::SolarSystemResourceEntry()
{
	init(0);
}

SolarSystemResourceEntry::~SolarSystemResourceEntry()
{
}

int SolarSystemResourceEntry::AddRef() {
	return DefaultRefCounted::AddRef();
}
int SolarSystemResourceEntry::Release() {
	return DefaultRefCounted::Release();
}

uint32_t SolarSystemResourceEntry::GetCastID() const {
	return TYPE;
}
uint32_t SolarSystemResourceEntry::GetNounID() const {
	return NOUN_ID;
}

void* SolarSystemResourceEntry::Cast(uint32_t type) const {
	CLASS_CAST(SolarSystemResourceEntry);
	PARENT_CAST(cGameData);
	return nullptr;
}

bool SolarSystemResourceEntry::Write(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Write(stream);
}
bool SolarSystemResourceEntry::WriteToXML(Simulator::XmlSerializer* writexml)
{
	return false;
}
bool SolarSystemResourceEntry::Read(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Read(stream);
}

void SolarSystemResourceEntry::init(uint32_t StarID)
{
	SystemID = StarID;
	energy = 0;
	energycap = 10;
}

int SolarSystemResourceEntry::GetEnergy()
{
	return energy;
}

bool SolarSystemResourceEntry::SetEnergy(int value)
{	//returns true if not crash
	energy = value;
	return true;
}

int SolarSystemResourceEntry::GetEnergyCap()
{
	return energycap;
}

bool SolarSystemResourceEntry::SetEnergyCap(int value)
{	//returns true if not crash
	energycap = value;
	return true;
}

float SolarSystemResourceEntry::GetEnergyPercentage()
{
	return energy/energycap;
}

/// END OF AUTOGENERATED METHODS ///
////////////////////////////////////

Simulator::Attribute SolarSystemResourceEntry::ATTRIBUTES[] = {
	// Add more attributes here
	// This one must always be at the end
	Simulator::Attribute()
};