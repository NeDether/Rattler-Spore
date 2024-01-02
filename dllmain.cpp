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

// This is in dllmain.cpp

using namespace ArgScript;
using namespace ArgScript;



void Initialize() {
	//Inject Categories in the Space Stage Tool Menu.
	InjectCategories::InjectHeader();
	InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_core.prop");


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
	SimulatorSystem.AddStrategy(new ScanMenu(), ScanMenu::NOUN_ID);
	SimulatorSystem.AddStrategy(new AchievementSystem(), AchievementSystem::NOUN_ID);

	//Add New Cheats.
	CheatManager.AddCheat("viewCrafts", new ViewCrafts());
	CheatManager.AddCheat("roomroot", new DestroySave());
}

void Dispose()
{
	// This method is called when the game is closing
}

void AttachDetours()
{
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

