// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore/Simulator/cToolStrategy.h>
#include "MiningBeam.h"
#include "Fabricator.h"
#include "FabricatorSystem.h"
#include "MiningScanner.h"
#include "InjectCategories.h"
#include <Spore/Simulator/cDefaultBeamTool.h>

// This is in dllmain.cpp

using namespace ArgScript;
using namespace ArgScript;



void Initialize() {
	InjectCategories::InjectHeader();
	InjectCategories::InjectCategory(u"AssetBrowserFeedItems!rspore_core.prop");
    ToolManager.AddStrategy(new MiningBeam(), id("mining_beam1"));
	ToolManager.AddStrategy(new MiningScanner(), id("mineral_scanner1"));
	ToolManager.AddStrategy(new Fabricator(), id("rattler_forge"));
	SimulatorSystem.AddStrategy(new FabricatorSystem(), FabricatorSystem::NOUN_ID);
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

