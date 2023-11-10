#include "stdafx.h"
#include "MiningScanner.h"

using namespace Simulator;

MiningScanner::MiningScanner() 
{


}
MiningScanner::~MiningScanner()
{


}

bool MiningScanner::OnHit(cSpaceToolData* pTool, const Vector3& position, SpaceToolHit hitType, int) {
	return false;
}
bool MiningScanner::Update(cSpaceToolData* pTool, bool showErrors, const char16_t** ppFailText)
{
    if (pTool->mRechargeTimer.IsRunning() == true)
    {
        if (pTool->mRechargeTimer.GetElapsed().LowPart >= pTool->mRechargeRate * 1000)
        {
            pTool->mRechargeTimer.Stop();
        }
    }

	if (GetCurrentContext() == SpaceContext::SolarSystem && pTool->mRechargeTimer.IsRunning() == false && GetActivePlanetRecord() != nullptr) {
		
		return true; 
	
	}
	else {
		return false; 
	}
}


bool MiningScanner::OnSelect(cSpaceToolData* pTool)
{  
    if ((GetActivePlanetRecord()->mTemperatureScore) >= 0.75) {                     //Kamacite
        App::ConsolePrintF("your dirt is: kamacite");
    }
    else if ((GetActivePlanetRecord()->mAtmosphereScore) >= 0.90) {      //Sulphide
        App::ConsolePrintF("your dirt is: sulphide");
    }
    else if ((GetActivePlanetRecord()->mTemperatureScore) <= 0.25) {     //Ice
        App::ConsolePrintF("your dirt is: ice");
    }
    else if ((GetActivePlanetRecord()->mAtmosphereScore) <= 0.20) {  //Silica
        App::ConsolePrintF("your dirt is: silica");
    }
    else {                                                                      //Carbon
        App::ConsolePrintF("your dirt is: carbon");
    }
    const PlanetID mario = GetActivePlanetRecord()->GetID();
    uint32_t greg = mario.internalValue;
    Math::RandomNumberGenerator rng(greg);
    int chud = rng.RandomInt(16);
    if (chud >= 0 && chud <= 4) { //Copper
        App::ConsolePrintF("your mineral is: copper");
    }
    else if (chud >= 5 && chud <= 8) { //Titanium
        App::ConsolePrintF("your mineral is: titanium");
    }
    else if (chud >= 9 && chud <= 12) { //Gold
        App::ConsolePrintF("your mineral is: gold");
    }
    else { //Latticine (le epic roomroot mineral :trolling:)
        App::ConsolePrintF("your mineral is: roomroot");
    }

	pTool->mbIsActive = false;
	pTool->mbIsInUse = false;
	pTool->mRechargeTimer.Start();
    return false;
}