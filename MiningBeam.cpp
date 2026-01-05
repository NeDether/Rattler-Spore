#include "stdafx.h"
#include "MiningBeam.h"
MiningBeam::MiningBeam(int silly)
{
    power = silly;
}


MiningBeam::~MiningBeam()
{
}

bool MiningBeam::OnHit(Simulator::cSpaceToolData* pTool, const Vector3& position, Simulator::SpaceToolHit hitType, int unk) {
    auto inventory = SimulatorSpaceGame.GetPlayerInventory();
    bool success = Simulator::cDefaultBeamTool::OnHit(pTool, position, hitType, unk);
    if (hitType == 1) {
        IVisualEffectPtr effect;
        if (EffectsManager.CreateVisualEffect(0x03fd5261, 0, effect)) {        
            effect->SetRigidTransform(Transform()
                .SetOffset(position)
                .SetScale(1.3f));
            effect->Start();
        }
       

        if (Math::rand(2) != 0) {
            return success;
        }
        //Loottable
        
        const Simulator::PlanetID mario = Simulator::GetActivePlanetRecord()->GetID();
        uint32_t greg = mario.internalValue;
        
        RandomNumberGenerator rng(greg);
        int abudnacne = rng.RandomInt(7);
        //abudnacne is the exclusive value on a planet that gives you more or less of a dirt type mineral
        for (int i = 0; i < power; i++) {
            if (inventory->HasTool({ id("mineral_scanner1"), 0, 0 })) {
             //   App::ConsolePrintF("LOOOOOOL");
            
            }//Sbiv is what TIER of rock you are gonna get
            if (Math::rand(abudnacne+2) == 1 && ((inventory->HasTool({ id("mineral_scanner1"), 0, 0 })) || (inventory->HasTool({ id("mineral_scanner2"), 0, 0 })) || (inventory->HasTool({ id("mineral_scanner3"), 0, 0 })))) {
                int sbiv = 1;
     //           App::ConsolePrintF("is this clled?");
                if (inventory->HasTool({ id("mineral_scanner2"), 0, 0 })) {
                    sbiv++;
                }
                if (inventory->HasTool({ id("mineral_scanner3"), 0, 0 })) {
                    sbiv++;
                    sbiv++;
                }
                getPool(greg, Math::rand(sbiv));


            }
            else {
                string john = "spice1";
                //App::ConsolePrintF(to_string(chud).c_str()); Millions must debug
                if ((Simulator::GetActivePlanetRecord()->mTemperatureScore) >= 0.75) {
                   
                    john = "spice_drt_kamacite";
                }
                else if ((Simulator::GetActivePlanetRecord()->mAtmosphereScore) >= 0.90) {
                    john = "spice_drt_sulphide";
                }
                else if ((Simulator::GetActivePlanetRecord()->mTemperatureScore) <= 0.25) {
                    john = "spice_drt_ice";
                }
                else if ((Simulator::GetActivePlanetRecord()->mAtmosphereScore) <= 0.20) {
                    john = "spice_drt_silica";
                }
                else {
                    john = "spice_drt_carbon";
                }

                SpaceTrading.ObtainTradingObject({ id(john.c_str()), 0, 0 }, 1);
                AchievementSystemA.MineCount++;
                AchievementSystemA.Discover({ id(john.c_str()), 0, 0 });


            }
        }
    
    
    
    }
   
    
    // rest of code

    if (AchievementSystemA.MineCount > 50) {
        AchievementSystemA.Achieve("ach_core_mine1");
    }
    if (AchievementSystemA.MineCount > 750) {
        AchievementSystemA.Achieve("ach_core_mine2");
    }
    if (AchievementSystemA.MineCount > 2500) {
        AchievementSystemA.Achieve("ach_core_mine3");
    }
    if (AchievementSystemA.MineCount > 50000) {
        AchievementSystemA.Achieve("ach_core_mine4");
    }
    if (AchievementSystemA.MineCount > 1000000) {
        AchievementSystemA.Achieve("ach_core_mine5");
    }

    return success;
}


void MiningBeam::getPool(uint32_t seed, int k) {
    RandomNumberGenerator rng(seed);
    auto inventory = SimulatorSpaceGame.GetPlayerInventory();
    string john = "spice1";
    if (k == 0) {

        int chud = rng.RandomInt(17);

            if (chud >= 0 && chud <= 5) {
                john = "spice_mat_copper";
            }
            else if (chud >= 6 && chud <= 10) {
                john = "spice_mat_titanium";
            }
            else if (chud >= 11 && chud <= 15) {
                john = "spice_mat_gold";
            }
            else {
                john = "spice_mat_latticine";
            }
        
        

    
    
    }
    if (k == 1) {
       // App::ConsolePrintF("Chud2");
        int chud = rng.RandomInt(37);
      //  if (inventory->HasTool({ id("mineral_scanner2"), 0, 0 })) {
            if (chud >= 0 && chud <= 15) {
                john = "spice_mat_crude";
            }
            else if (chud >= 16 && chud <= 22) {
                john = "spice_mat_lithium";
            }
            else if (chud >= 23 && chud <= 29) {
                john = "spice_mat_cobalt";
            }
            else if (chud >= 30 && chud <= 32) {
                john = "spice_mat_serenidite";
            }
            else if (chud >= 33 && chud <= 34) {
                john = "spice_mat_quartz";
            }
            else if (chud >= 35 && chud <= 35) {
                john = "spice_mat_amethyst";
            }
            else {
                john = "spice_mat_obsidian";
            }


  //      }


    }
    if (k == 2) {
     //   App::ConsolePrintF("Chud3");
        int chud = rng.RandomInt(5);
     //   if (inventory->HasTool({ id("mineral_scanner3"), 0, 0 })) {
            if (chud == 0) {
                john = "spice_mat_uranium";
            }
            else if (chud == 1) {
                john = "spice_mat_nvidium";
            }
            else if (chud == 2) {
                john = "spice_mat_diamond";
            }
            else if (chud == 3) {
                john = "spice_mat_zurg";
            }
            else {
                john = "spice_mat_flesh";
            }


   //     }


    }
    ResourceKey rekkey = { id(john.c_str()), 0, 0 };

    SpaceTrading.ObtainTradingObject(rekkey, 1);
    AchievementSystemA.Discover(rekkey);

}


bool MiningBeam::OnSelect(Simulator::cSpaceToolData* pTool)
{
    //App::ConsolePrintF(to_string(Simulator::GetActivePlanetRecord()->mAtmosphereScore).c_str());
    //App::ConsolePrintF(to_string(Simulator::GetActivePlanetRecord()->mTemperatureScore).c_str());
	//App::ConsolePrintF("Selected!");
	//SpaceTrading.ObtainTradingObject({ id("spice_mat_copper"), TypeIDs::prop, 0x034D97FA }, 1);
	return false;
}

bool MiningBeam::Update(Simulator::cSpaceToolData* pTool, bool showErrors, const char16_t**)
{
    if (Simulator::GetCurrentContext() == Simulator::SpaceContext::Planet) {
        if (VaultManagerA.isVaultPlanet(Simulator::GetActivePlanet()->mPlanetKey)) {
            return false;
        }
        return true;
    }
    return false;
}

