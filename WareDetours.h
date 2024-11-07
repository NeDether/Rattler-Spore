#pragma once
#include "stdafx.h"


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
