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
                .SetScale(1.1f));
            effect->Start();
        }
       

        if (Math::rand(2) == 0) {
            return success;
        }
        //Loottable
        
        const Simulator::PlanetID mario = Simulator::GetActivePlanetRecord()->GetID();
        uint32_t greg = mario.internalValue;
        RandomNumberGenerator rng(greg);
        int abudnacne = rng.RandomInt(6)+1;
        for (int i = 0; i < power; i++) {
            if (inventory->HasTool({ id("mineral_scanner1"), 0, 0 })) {
             //   App::ConsolePrintF("LOOOOOOL");
            
            }
            if (Math::rand(abudnacne) == 0 && ((inventory->HasTool({ id("mineral_scanner1"), 0, 0 })) || (inventory->HasTool({ id("mineral_scanner2"), 0, 0 })) || (inventory->HasTool({ id("mineral_scanner3"), 0, 0 })))) {
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
                //App::ConsolePrintF(to_string(chud).c_str()); Millions must debug
                if ((Simulator::GetActivePlanetRecord()->mTemperatureScore) >= 0.75) {
                    SpaceTrading.ObtainTradingObject({ id("spice_drt_kamacite"), 0, 0 }, 1);
                }
                else if ((Simulator::GetActivePlanetRecord()->mAtmosphereScore) >= 0.90) {
                    SpaceTrading.ObtainTradingObject({ id("spice_drt_sulphide"), 0, 0 }, 1);
                }
                else if ((Simulator::GetActivePlanetRecord()->mTemperatureScore) <= 0.25) {
                    SpaceTrading.ObtainTradingObject({ id("spice_drt_ice"), 0, 0 }, 1);
                }
                else if ((Simulator::GetActivePlanetRecord()->mAtmosphereScore) <= 0.20) {
                    SpaceTrading.ObtainTradingObject({ id("spice_drt_silica"), 0, 0 }, 1);
                }
                else {
                    SpaceTrading.ObtainTradingObject({ id("spice_drt_carbon"), 0, 0 }, 1);
                }
            }
        }
    
    
    
    }
   
    
    // rest of code
    return success;
}

void MiningBeam::getPool(uint32_t seed, int k) {
    RandomNumberGenerator rng(seed);
    auto inventory = SimulatorSpaceGame.GetPlayerInventory();
    if (k == 0) {
    //    App::ConsolePrintF("Chud1");
        int chud = rng.RandomInt(16);
      //  if (inventory->HasTool({ id("mineral_scanner1"), 0, 0 })) {
            if (chud >= 0 && chud <= 4) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_copper"), 0, 0 }, 1);
            }
            else if (chud >= 5 && chud <= 8) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_titanium"), 0, 0 }, 1);
            }
            else if (chud >= 9 && chud <= 13) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_gold"), 0, 0 }, 1);
            }
            else {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_latticine"), 0, 0 }, 1);
            }
        
        
   //     }
    
    
    }
    if (k == 1) {
       // App::ConsolePrintF("Chud2");
        int chud = rng.RandomInt(37);
      //  if (inventory->HasTool({ id("mineral_scanner2"), 0, 0 })) {
            if (chud >= 0 && chud <= 15) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_crude"), 0, 0 }, 1);
            }
            else if (chud >= 16 && chud <= 22) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_lithium"), 0, 0 }, 1);
            }
            else if (chud >= 23 && chud <= 29) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_cobalt"), 0, 0 }, 1);
            }
            else if (chud >= 30 && chud <= 32) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_serenidite"), 0, 0 }, 1);
            }
            else if (chud >= 33 && chud <= 34) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_quartz"), 0, 0 }, 1);
            }
            else if (chud >= 35 && chud <= 35) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_amethyst"), 0, 0 }, 1);
            }
            else {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_obsidian"), 0, 0 }, 1);
            }


  //      }


    }
    if (k == 2) {
     //   App::ConsolePrintF("Chud3");
        int chud = rng.RandomInt(5);
     //   if (inventory->HasTool({ id("mineral_scanner3"), 0, 0 })) {
            if (chud == 0) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_uranium"), 0, 0 }, 1);
            }
            else if (chud == 1) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_nvidium"), 0, 0 }, 1);
            }
            else if (chud == 2) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_diamond"), 0, 0 }, 1);
            }
            else if (chud == 3) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_zurg"), 0, 0 }, 1);
            }
            else {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_flesh"), 0, 0 }, 1);
            }


   //     }


    }


    

}


bool MiningBeam::OnSelect(Simulator::cSpaceToolData* pTool)
{
    //App::ConsolePrintF(to_string(Simulator::GetActivePlanetRecord()->mAtmosphereScore).c_str());
    //App::ConsolePrintF(to_string(Simulator::GetActivePlanetRecord()->mTemperatureScore).c_str());
	//App::ConsolePrintF("Selected!");
	//SpaceTrading.ObtainTradingObject({ id("spice_mat_copper"), TypeIDs::prop, 0x034D97FA }, 1);
	return false;
}

