// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore/Simulator/cToolStrategy.h>
#include "MiningBeam.h"
#include <Spore/Simulator/cDefaultBeamTool.h>

// This is in dllmain.cpp

using namespace ArgScript;
using namespace ArgScript;


class PlanetBusterCheat
    : public ICommand
{
public:
    void ParseLine(const Line& line) {
        if (Simulator::IsSpaceGame()) {
            cSpaceToolDataPtr tool;
            ToolManager.LoadTool({ id("mining_beam1"), 0, 0 }, tool);

            
            size_t numArgs;
            auto args = line.GetArgumentsRange(&numArgs, 0, 1);
            if (numArgs == 1) {
                tool->mCurrentAmmoCount = mpFormatParser->ParseInt(args[0]);
            }

            auto inventory = SimulatorSpaceGame.GetPlayerInventory();
            SpaceTrading.ObtainTradingObject({ id("spice_mat_copper"), TypeIDs::prop, 0x034D97FA }, 3);
            inventory->AddItem(tool.get());
        }
    }

    const char* GetDescription(DescriptionMode mode) const {
        return "Call the cheat. Drop the bomb. BOOM!";
    }
};

void Initialize() {
    CheatManager.AddCheat("planetBuster", new PlanetBusterCheat());
    ToolManager.AddStrategy(new MiningBeam(), id("mining_beam1"));
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

