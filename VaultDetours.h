#pragma once
#include "stdafx.h"
#include "VaultManager.h"


using namespace ArgScript;

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