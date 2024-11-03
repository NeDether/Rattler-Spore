#pragma once
#include "stdafx.h"


using namespace ArgScript;

member_detour(GenerateNPCStoreDetour, Simulator::cSpaceTrading, void(cPlanetRecord* planetRecord, LocalizedString& dstSpiceText)) {
	void detoured(cPlanetRecord * planetRecord, LocalizedString & dstSpiceText) {
		original_function(this, planetRecord, dstSpiceText);
		
		App::ConsolePrintF("Opened up a Trade Menu.");
		auto& storeItems = SpaceTrading.mNPCStore;
		cSpaceInventoryItemPtr john;
		cSpaceInventoryItem::CreateTradingObject(john, { id("spice_mat_zurg"),TypeIDs::prop, 0x034D97FA }, 1, 1.0f);
		storeItems.front()->mNPCInventory.emplace_back(john.get());
		
		return;
	}
};
