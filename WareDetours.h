#pragma once
#include "stdafx.h"
#include "TriviteEmpire.h"


using namespace ArgScript;

member_detour(GenerateNPCStoreDetour, Simulator::cSpaceTrading, void(cPlanetRecord* planetRecord, LocalizedString& dstSpiceText)) {
	void detoured(cPlanetRecord * planetRecord, LocalizedString & dstSpiceText) {
		
		
		App::ConsolePrintF("Opened up a Trade Menu.");
		auto& storeItems = SpaceTrading.mNPCStore;
		//cSpaceInventoryItemPtr john;
		//auto f74 = SpaceTrading.field_74;
		//auto f88 = SpaceTrading.field_88;
		//SpaceTrading.CreateTradingObject(john, { id("spice_drt_carbon"),0, 0}, 1, 1.0f);
		
		//john->mItemType = SpaceInventoryItemType::TradingObject;
		//john->mItemCount = 1;
		
		//storeItems.back()->mNPCInventory.emplace_back(john.get());
		//storeItems.back()->mSpiceID.emplace_back(ResourceKey{ id("spice6"),0, 0 });
		original_function(this, planetRecord, dstSpiceText);
	}
};

member_detour(spawnUFODetour, Simulator::cGameDataUFO, void(UfoType type,cEmpire* empire)) {
	void detoured(UfoType type, cEmpire * empire) {

		
		

		if (empire == nullptr) {
		App::ConsolePrintF("Spawned A UFO | Empire Hash : has no empire :( ");
		}
		else {
		App::ConsolePrintF("Spawned A UFO | Empire Hash : 0x%x", empire->GetEmpireID());
		
		}

		if (type == UfoType::SecurityDrone) {
			App::ConsolePrintF("Spawned A Trivite Drone.");
			
			//this->field_7E0 = u"Trivite Drone";
			//cEmpire* rizz = StarManager.GetEmpire(TriviteEmpireA.GetEmpireID());
			//empire = rizz;
			original_function(this, type, empire);
			this->SetModelKey({ 0x2538FB35, TypeIDs::ufo, GroupIDs::UFOModels });
			return;
		}
		original_function(this, type, empire);
	}
};
