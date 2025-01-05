// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore/Simulator/cToolStrategy.h>
#include "MiningBeam.h"
#include "Fabricator.h"
#include "FabricatorSystem.h"
#include "MiningScanner.h"
#include "InjectCategories.h"
#include "ScanMenu.h"
#include <Spore/Simulator/cDefaultBeamTool.h>
#include "ViewCrafts.h"
#include "DestroySave.h"
#include "FactoryManager.h"
#include "DrillBuilding.h"
#include "PlaceDrill.h"
#include "SkondEmpire.h"
#include "SpawnBee.h"
#include "SpawnStation.h"
#include "ReadPlanet.h"
#include "SolarSystemResources.h"
#include "SolarSystemResourceEntry.h"
#include "SolSysResourcesCheat.h"
#include "VaultManager.h"
#include "VaultPlanet.h"
#include "VaultDetours.h"
#include "WareDetours.h"
#include "StartingScenarioDetours.h"
#include "StartingScenarioHandler.h"
#include "TriviteEmpire.h"
#include "SpawnDrone.h"
#include "ReadPirates.h"
// This is in dllmain.cpp

using namespace ArgScript;




void Initialize() {
	//Inject Categories in the Space Stage Tool Menu.
	InjectCategories::InjectHeader();
	InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_core.prop");
	App::ConsolePrintF("RattlerSPORE: Core Enabled");
	//May seem pointless but this is for copy and pasting config and stuff.

	if (PropManager.HasPropertyList(id("grindytools"), id("rattlerConfig")))
	{
		App::ConsolePrintF("RattlerSPORE: Grindy Tool Recipes Addon Enabled");
		InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_grindytools.prop");
	}
	if (PropManager.HasPropertyList(id("normaltools"), id("rattlerConfig")))
	{
		App::ConsolePrintF("RattlerSPORE: Normal Tool Recipes Addon Enabled");
		InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_normaltools.prop");
	}
	if (PropManager.HasPropertyList(id("casualtools"), id("rattlerConfig")))
	{
		App::ConsolePrintF("RattlerSPORE: Casual Tool Recipes Addon Enabled");
		InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_casualtools.prop");
	}

	if (PropManager.HasPropertyList(id("creativeTools"), id("rattlerConfig")))
	{
		App::ConsolePrintF("RattlerSPORE: Creative Recipes Addon Enabled");
		InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_creativetools.prop");
	}
	//Core Wares
	if (PropManager.HasPropertyList(id("wares"), id("rattlerConfig")))
	{
		App::ConsolePrintF("RattlerSPORE: Core Wares Enabled");
		InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_wares.prop");
		


	}
	//Core Industry
	if (PropManager.HasPropertyList(id("industry"), id("rattlerConfig")))
	{
		App::ConsolePrintF("RattlerSPORE: Core Industry Enabled");
		InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_industry.prop");
		ClassManager.AddFactory(new DrillBuildingFactory());

		ToolManager.AddStrategy(new PlaceDrill(), id("placedrill"));

		//SimulatorSystem.AddStrategy(new FactoryManager(), FactoryManager::NOUN_ID);
		SimulatorSystem.AddStrategy(new SolarSystemResources(), SolarSystemResources::NOUN_ID);
	}

	//Spice Dyeing Addon
	if (PropManager.HasPropertyList(id("spicedye"), id("rattlerConfig")))
	{
		App::ConsolePrintF("RattlerSPORE: Spice Dyeing Addon Enabled");
		InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_dye.prop");
	}
	//Species
	//SimulatorSystem.AddStrategy(new SkondEmpire(), SkondEmpire::NOUN_ID);
	SimulatorSystem.AddStrategy(new TriviteEmpire(), TriviteEmpire::NOUN_ID);

	//Add the New Core Tools
    ToolManager.AddStrategy(new MiningBeam(1), id("mining_beam1"));
	ToolManager.AddStrategy(new MiningScanner(1), id("mineral_scanner1"));
	ToolManager.AddStrategy(new MiningBeam(2), id("mining_beam2"));
	ToolManager.AddStrategy(new MiningScanner(2), id("mineral_scanner2"));
	ToolManager.AddStrategy(new MiningBeam(3), id("mining_beam3"));
	ToolManager.AddStrategy(new MiningScanner(3), id("mineral_scanner3"));
	ToolManager.AddStrategy(new Fabricator(), id("rattler_forge"));


	//Add The New Systems
	SimulatorSystem.AddStrategy(new FabricatorSystem(), FabricatorSystem::NOUN_ID);
	SimulatorSystem.AddStrategy(new VaultManager(), VaultManager::NOUN_ID);
	SimulatorSystem.AddStrategy(new ScanMenu(), ScanMenu::NOUN_ID);
	SimulatorSystem.AddStrategy(new AchievementSystem(), AchievementSystem::NOUN_ID);


	App::AddUpdateFunction(new StartingScenarioHandler());

	//Add System Subobjects
	ClassManager.AddFactory(new VaultPlanetFactory());

	//Add New Cheats.
	//CheatManager.AddCheat("viewCrafts", new ViewCrafts());
	//CheatManager.AddCheat("SpawnStation", new SpawnStation());
	CheatManager.AddCheat("ReadPlanet", new ReadPlanet());
	CheatManager.AddCheat("ReadPirates", new ReadPirates());
	//CheatManager.AddCheat("SpawnBee", new SpawnBee());
	CheatManager.AddCheat("SpawnDrone", new SpawnDrone());
	CheatManager.AddCheat("roomroot", new DestroySave());
	CheatManager.AddCheat("doSys", new SolSysResourcesCheat());
}

void Dispose()
{
	// This method is called when the game is closing
}



void AttachDetours()
{	
	GenerateVaultDetour::attach(GetAddress(Simulator::cStarManager, GeneratePlanetsForStar));
	displayPlanetIconDetour::attach(GetAddress(Simulator::cPlanetRecord, GetTypeIconKey));
	GenerateNPCStoreDetour::attach(GetAddress(Simulator::cSpaceTrading, GenerateNPCStore));
	ReadSPUI_Detour::attach(GetAddress(UTFWin::UILayout, Load));
	spawnUFODetour::attach(GetAddress(Simulator::cGameDataUFO, Initialize));
	// Call the attach() method on any detours you want to add
	// For example: cViewer_SetRenderType_detour::attach(GetAddress(cViewer, SetRenderType));
}


// Generally, you don't need to touch any code here
BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		ModAPI::AddPostInitFunction(Initialize);
		ModAPI::AddDisposeFunction(Dispose);

		PrepareDetours(hModule);
		AttachDetours();
		CommitDetours();
		break;

	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return TRUE;
}

