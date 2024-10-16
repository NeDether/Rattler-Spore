#pragma once
#include "stdafx.h"
#include "VaultManager.h"


using namespace ArgScript;

//Detour Planet Icon display to have custom icons on vault planets.

static_detour(displayPlanetIconDetour, ResourceKey&(cPlanetRecord * record)) {
	ResourceKey& detoured(cPlanetRecord * record) {
		auto value = original_function(record);
		//REDO THIS LATER this crashes quite frequently.
		uint32_t copyID = record->GetID().internalValue;
		if (VaultManagerA.isVaultPlanet(copyID)) {
			ResourceKey iconplanet;
			iconplanet = ResourceKey(0xEE8B14C3, 0x2F7D0004, 0xAC3EBDB7);
			return iconplanet;
		
		}
		return value;

	}
};



//Detour System Generation to create Vault Planets
member_detour(GenerateVaultDetour, Simulator::cStarManager, void(cStarRecord* pStarRecord, StarRequestFilter* pFilter, bool useMaxPlanets)) {
	void detoured(cStarRecord * pStarRecord, StarRequestFilter * pFilter, bool useMaxPlanets) {
		original_function(this, pStarRecord, pFilter, useMaxPlanets);
		App::ConsolePrintF("The system has generated.");
		if (VaultManagerA.GenerateVault(pStarRecord)) {
			App::ConsolePrintF("A vault has also been generated.");
		}
		return;
	}
};


