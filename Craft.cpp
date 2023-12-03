#include "stdafx.h"
#include "Craft.h"

Craft::Craft()
{
}


Craft::~Craft()
{
}

// For internal use, do not modify.
int Craft::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int Craft::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void* Craft::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(IWinProc);
	CLASS_CAST(Craft);
	return nullptr;
}

// This method returns a combinations of values in UTFWin::EventFlags.
// The combination determines what types of events (messages) this window procedure receives.
// By default, it receives mouse/keyboard input and advanced messages.
int Craft::GetEventFlags() const
{
	return kEventFlagBasicInput | kEventFlagAdvanced;
}

// The method that receives the message. The first thing you should do is probably
// checking what kind of message was sent...
bool Craft::HandleUIMessage(IWindow* window, const Message& message)
{
	if (message.eventType == MessageType::kMsgButtonClick)
	{
		if (!HasMaterial(id("spice_drt_ice"), 20) || !HasMaterial(id("spice_mat_copper"), 5)) {
			
			return true;
		}
		if (!UseMaterial(id("spice_drt_ice"), 20) || !UseMaterial(id("spice_mat_copper"), 5)) {

			return true;
		}
		if (GiveItem(id("energypotion"), 1)) {

			return true;
		//Run if happen.
		}
		return true;
		
	}
	// Return true if the message was handled, and therefore no other window procedure should receive it.
	return false;
	
	// Return true if the message was handled, and therefore no other window procedure should receive it.
	
}
bool Craft::UseMaterial(uint32_t WareID, int neededAmount)
{//Returns True if Has Material. Returns False if Does not.
	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	auto X = inventory->IndexOf(Simulator::SpaceInventoryItemType(4), { WareID, 0, 0 });
	auto H = inventory->GetItem(X);
	if (H == nullptr) {
		App::ConsolePrintF("Does not have Any Resources...");
		return false;
	}
	size_t itemCount;
	if (H->GetItemCount(itemCount))
	{

		if (itemCount >= neededAmount) {

			App::ConsolePrintF("The total ''Count'' in the inv: %d", H);
			auto D = inventory->RemoveItem(H);
			
			if (itemCount != neededAmount) {

				SpaceTrading.ObtainTradingObject({ WareID, 0, 0 }, (itemCount - neededAmount));

			}
			return true;
			//do stuff
		}
		if (itemCount == 0) {
			//Deletes the cargo if reaches 0 because spore is ok with having '0' of a cargo slot.
			auto D = inventory->RemoveItem(H);
		}
		App::ConsolePrintF("Insufficient Resources...");
	}
	App::ConsolePrintF("I had a bruh moment.");
	return false;
}


bool Craft::GiveItem(uint32_t WareID, int givenAmount)
{ //Returns true if Gives Item, returns false if does not.
				//Gives energy potion.
	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	cSpaceToolDataPtr tool;
	ToolManager.LoadTool({ WareID, 0, 0 }, tool);
	tool->mCurrentAmmoCount = givenAmount;
	
	inventory->AddItem(tool.get());

	if (inventory->mbHasAddedItem) {
		return true;

	}
	return false;
}
bool Craft::HasMaterial(uint32_t WareID, int neededAmount)
{ //Checks if has the materials in the first place before using them up.
	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	auto X = inventory->IndexOf(Simulator::SpaceInventoryItemType(4), { WareID, 0, 0 });
	auto H = inventory->GetItem(X);
	if (H == nullptr) {
		App::ConsolePrintF("Does not have Any Resources...");
		return false;
	}
	size_t itemCount;
	if (H->GetItemCount(itemCount))
	{

		if (itemCount >= neededAmount) {

			return true;
			//do stuff
		}
		
		App::ConsolePrintF("Insufficient Resources...");
	}
	App::ConsolePrintF("I had a bruh moment.");
	return false;
}
//