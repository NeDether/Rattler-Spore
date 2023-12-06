#include "stdafx.h"
#include "MiningScanner.h"
#include "ScanMenu.h"
using namespace Simulator;

MiningScanner::MiningScanner(int john) 
{
    power = john;

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
            ScanMenuA.CloseScan(true);
            pTool->mRechargeTimer.Stop();
        }
    }

	if ((GetCurrentContext() == SpaceContext::Planet || GetCurrentContext() == SpaceContext::SolarSystem) && pTool->mRechargeTimer.IsRunning() == false && GetActivePlanetRecord() != nullptr) {
		
		return true; 
	
	}
	else {
		return false; 
	}
}


bool MiningScanner::OnSelect(cSpaceToolData* pTool)
{
    vector<uint32_t> gaksterrific;
    
    if ((GetActivePlanetRecord()->mTemperatureScore) >= 0.75) {                     //Kamacite
        gaksterrific.push_back(id("spice_drt_kamacite"));
      ///  App::ConsolePrintF("your dirt is: kamacite");
    }
    else if ((GetActivePlanetRecord()->mAtmosphereScore) >= 0.90) {      //Sulphide
        gaksterrific.push_back(id("spice_drt_sulphide"));
    ///    App::ConsolePrintF("your dirt is: sulphide");
    }
    else if ((GetActivePlanetRecord()->mTemperatureScore) <= 0.25) {     //Ice
        gaksterrific.push_back(id("spice_drt_ice"));
      //  App::ConsolePrintF("your dirt is: ice");
    }
    else if ((GetActivePlanetRecord()->mAtmosphereScore) <= 0.20) {  //Silica
        gaksterrific.push_back(id("spice_drt_silica"));
    //    App::ConsolePrintF("your dirt is: silica");
    }
    else {                                                                      //Carbon
        gaksterrific.push_back(id("spice_drt_carbon"));
   //     App::ConsolePrintF("your dirt is: carbon");
    }
    const PlanetID mario = GetActivePlanetRecord()->GetID();
    uint32_t greg = mario.internalValue;
    Math::RandomNumberGenerator rng(greg);
    int chud = rng.RandomInt(16);
    if (chud >= 0 && chud <= 4) { //Copper
  //      App::ConsolePrintF("your mineral is: copper");
        gaksterrific.push_back(id("spice_mat_copper"));
    }
    else if (chud >= 5 && chud <= 8) { //Titanium
   //     App::ConsolePrintF("your mineral is: titanium");
        gaksterrific.push_back(id("spice_mat_titanium"));
    }
    else if (chud >= 9 && chud <= 13) { //Gold
      //  App::ConsolePrintF("your mineral is: gold");
        gaksterrific.push_back(id("spice_mat_gold"));
    }
    else { //Latticine (le epic roomroot mineral :trolling:)
    //    App::ConsolePrintF("your mineral is: roomroot");
        gaksterrific.push_back(id("spice_mat_latticine"));
    }
    if (power > 1) {
        Math::RandomNumberGenerator rng(greg);
        chud = rng.RandomInt(37);
        if (chud >= 0 && chud <= 15) {
            gaksterrific.push_back(id("spice_mat_crude"));
        }
        else if (chud >= 16 && chud <= 22) {
            gaksterrific.push_back(id("spice_mat_lithium"));
        }
        else if (chud >= 23 && chud <= 29) {
            gaksterrific.push_back(id("spice_mat_cobalt"));
        }
        else if (chud >= 30 && chud <= 32) {
            gaksterrific.push_back(id("spice_mat_serenidite"));
        }
        else if (chud >= 33 && chud <= 34) {
            gaksterrific.push_back(id("spice_mat_quartz"));
        }
        else if (chud >= 35 && chud <= 35) {
            gaksterrific.push_back(id("spice_mat_amethyst"));
        }
        else {
            gaksterrific.push_back(id("spice_mat_obsidian"));
        }
    
    }
    if (power > 2) {
        Math::RandomNumberGenerator rng(greg);
        chud = rng.RandomInt(5);
        if (chud == 0) {
            gaksterrific.push_back(id("spice_mat_uranium"));
        }
        else if (chud == 1) {
            gaksterrific.push_back(id("spice_mat_nvidium"));
        }
        else if (chud == 2) {
            gaksterrific.push_back(id("spice_mat_diamond"));
        }
        else if (chud == 3) {
            gaksterrific.push_back(id("spice_mat_zurg"));
        }
        else {
            gaksterrific.push_back(id("spice_mat_flesh"));
        }
    
    
    
    
    }
    ScanMenuA.OpenScan(true);
    ScanMenuA.AddResources(gaksterrific);
	pTool->mbIsActive = false;
	pTool->mbIsInUse = false;
	pTool->mRechargeTimer.Start();
    return false;
}