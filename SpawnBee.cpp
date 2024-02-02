#include "stdafx.h"
#include "SpawnBee.h"
#include "SkondEmpire.h"
using namespace Simulator;
SpawnBee::SpawnBee()
{
}


SpawnBee::~SpawnBee()
{
}


void SpawnBee::ParseLine(const ArgScript::Line& line)
{	
	//Tech Level 32 = Skond Planet
	//Tech Level 31 = Ra'Tal Planet
	//Tech Level 30 = Pirate Planet
	auto StarRecord = GetActiveStarRecord();
	
	//GetActiveStarRecord()->mTechLevel = TechLevel::Empire legit screws it up;
	auto SelectedSpecies = SpeciesManager.GetSpeciesProfile({ 0x23E33E31, TypeIDs::crt, GroupIDs::CreatureModels });
	StarRecord->mpSpeciesProfile = SelectedSpecies;
	StarRecord->mCitizenSpeciesKey = ResourceKey({ 0x23E33E31, TypeIDs::crt, GroupIDs::CreatureModels });
	StarRecord->mEmpireID = SkondEmpireA.Skond->GetEmpireID();
	//GetActivePlanetRecord()->mTechLevel = TechLevel::Empire;
	GetActivePlanetRecord()->mNumDefenderUFOs = 25;
	
	StarRecord->mTechLevel = (TechLevel::Tribe);
	GetActivePlanetRecord()->mTechLevel = (TechLevel)32;
	//GetActivePlanetRecord()->mTechLevel = (TechLevel::Civilization);
	GetActivePlanetRecord()->mSpiceGen = ResourceKey({ id("spice6"),0,0 });
	GetActivePlanetRecord()->mPlanetRing = 5;
	//GetActivePlanetRecord()->field_10C = 1; //followers?
	
	auto hive = simulator_new<cPlace();
	hive->SetModel(GetPlayerUFO()->GetModel(), GetPlayerUFO()->GetModelWorld());
	hive->SetPosition(GetPlayerUFO()->GetPosition());
	hive->SetOrientation(PlanetModel.GetOrientation(hive->GetPosition(), Vector3(0, 0, 1)));
	hive->SetHealthPoints(50);
	hive->SetIsOnView(true);
	hive->load
	auto honey = simulator_new<cPlanetaryArtifact>();
	honey->SetPosition(GetPlayerUFO()->GetPosition());
	honey->SetOrientation(PlanetModel.GetOrientation(hive->GetPosition(), Vector3(0, 0, 1)));
	honey->LoadFromItem(SpaceInventoryItemType::TradingObject, { id("spice6"), 0, 0 }, 1, true);
	//cGameDataUFOPtr wasp = simulator_new<cGameDataUFO>();
	//cVehiclePtr vehicle = simulator_new<cVehicle>();
	//vehicle->Load(kVehicleLand, kVehicleMilitary, { 0x19A3A9AC, TypeIDs::vcl, GroupIDs::VehicleModels });

	///wasp->SetModel(GetPlayerUFO()->GetModel(), GetPlayerUFO()->GetModelWorld());
	//wasp->SetPosition(GetPlayerUFO()->GetPosition());
	//wasp->SetHealthPoints(50);
	//wasp->mMaxHealthPoints = 50;
	


	
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
}

const char* SpawnBee::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat does something.";
	}
	else {
		return "SpawnBee: Elaborate description of what this cheat does.";
	}
}
