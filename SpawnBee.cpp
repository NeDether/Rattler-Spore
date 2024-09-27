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
	GetActivePlanetRecord()->mTechLevel = TechLevel::Empire;
	GetActivePlanetRecord()->mNumDefenderUFOs = 25;
	SkondEmpireA.Skond->mIDColorID = (int)IdentityColors::Pink;
	//SkondEmpireA.Skond->UpdateAndGetColor();
	
	//StarRecord->mTechLevel = (TechLevel::City);
	//cPlanetRecord::FillPlanetDataForTechLevel(GetActivePlanetRecord(), TechLevel::Empire);
	//GetActivePlanetRecord()->mTechLevel = (TechLevel)32;
	//GetActivePlanetRecord()->mTechLevel = (TechLevel::City);
	GetActivePlanetRecord()->mSpiceGen = ResourceKey({ id("spice6"),0,0 });
	GetActivePlanetRecord()->mPlanetRing = 5;
	//GetActivePlanetRecord()->field_10C = 1; //followers?
	
	//ResourceKey({ 0x23B66448, TypeIDs::bld, GroupIDs::BuildingModels }); Node Model
	//ResourceKey({ 0x23B66453, TypeIDs::ufo, GroupIDs::UFOModels }); Swarmer Model
	//auto hive = simulator_new<cToolObject>();
	//hive->SetModelKey(ResourceKey({ 0x23B66448, TypeIDs::bld, GroupIDs::BuildingModels }));
	//hive->SetPosition(GetPlayerUFO()->GetPosition());
	//hive->SetOrientation(PlanetModel.GetOrientation(hive->GetPosition(), Vector3(0, 0, 1)));
	//hive->SetHealthPoints(50);
	//hive->mMaxHealthPoints = 50;
	//hive->SetIsOnView(true);
	//auto mario = Simulator::GetData<cToolObject>();
	//for (auto skibidi : mario) {
	//	App::ConsolePrintF("my fucking limit");
		// vehicle is a cVehicle*
	//}
//	auto honey = simulator_new<cPlanetaryArtifact>();
	//honey->SetPosition(GetPlayerUFO()->GetPosition());
	//honey->SetOrientation(PlanetModel.GetOrientation(hive->GetPosition(), Vector3(0, 0, 1)));
//	honey->LoadFromItem(SpaceInventoryItemType::TradingObject, { id("spice6"), 0, 0 }, 1, true);
	//auto wasp = simulator_new<cGameDataUFO>();
	//cVehiclePtr vehicle = simulator_new<cVehicle>();
	//vehicle->Load(kVehicleLand, kVehicleMilitary, { 0x19A3A9AC, TypeIDs::vcl, GroupIDs::VehicleModels });
	//wasp->SetModelKey(ResourceKey({ 0x23B66453, TypeIDs::ufo, GroupIDs::UFOModels }));
	//wasp->SetPosition(GetPlayerUFO()->GetPosition());
	//wasp->SetHealthPoints(50);
	//wasp->mMaxHealthPoints = 50;
	//wasp->mUFOType = 0;
	//wasp->mDesiredModelKey((ResourceKey({ 0x23B66453, TypeIDs::ufo, GroupIDs::UFOModels })));
	//wasp->SetIsOnView(true);
	//wasp->mNextPosition(Vector3{577,114,808});
	//wasp->mNextOrientation(Vector4{0.23,0.198,0.82,0.47});
	//wasp->mZoomAltitude=1000.0;
	//wasp->field_6B4=1;
	//wasp->field_6B8=1;
	
	//wasp->field_78C=true;
	//wasp->mpNPCMediumAirWeapon=ResourceKey({0x2eaac830,0,0});
	//wasp->mpNPCNearAirWeapon=ResourceKey({0x2eaad0a8,0,0});
//	wasp->field_7D8=548072760;



	
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
