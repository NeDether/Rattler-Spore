#include "stdafx.h"
#include "MiningBeam.h"

MiningBeam::MiningBeam()
{
}


MiningBeam::~MiningBeam()
{
}

bool MiningBeam:: OnHit(Simulator::cSpaceToolData* pTool, const Vector3& position, Simulator::SpaceToolHit hitType, int unk) {
    IVisualEffectPtr effect;
    bool success = Simulator::cDefaultBeamTool::OnHit(pTool, position, hitType, unk);
    if (hitType == 1) {
    
        if (EffectsManager.CreateVisualEffect(0x03fd5261, 0, effect)) {
            // X and Y can go negative, but we will only use positive Z so it doesn't go below the ground
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
        int chud = (int)((greg >> 24) & 0x3F);
        if (Math::rand(9)!=0) {
            if ((Simulator::GetActivePlanetRecord()->mTemperatureScore) >= 0.75) {
                SpaceTrading.ObtainTradingObject({ id("spice_drt_kamacite"), TypeIDs::prop, 0x034D97FA }, 1);
            }
            else if ((Simulator::GetActivePlanetRecord()->mAtmosphereScore) <= 0.20) {
                SpaceTrading.ObtainTradingObject({ id("spice_drt_sulphide"), TypeIDs::prop, 0x034D97FA }, 1);
            }
            else if ((Simulator::GetActivePlanetRecord()->mTemperatureScore) <= 0.25) {
                SpaceTrading.ObtainTradingObject({ id("spice_drt_ice"), TypeIDs::prop, 0x034D97FA }, 1);
            }
            else if ((Simulator::GetActivePlanetRecord()->mAtmosphereScore) >= 0.90 ) {
                SpaceTrading.ObtainTradingObject({ id("spice_drt_silica"), TypeIDs::prop, 0x034D97FA }, 1);
            }
            else {
                SpaceTrading.ObtainTradingObject({ id("spice_drt_carbon"), TypeIDs::prop, 0x034D97FA }, 1);
            }
        
        
        
        }
        else {
            //App::ConsolePrintF(to_string(chud).c_str()); Millions must debug
            if (chud >= 0 && chud <= 3) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_copper"), TypeIDs::prop, 0x034D97FA }, 1);
            }
            else if (chud >= 4 && chud <= 7) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_titanium"), TypeIDs::prop, 0x034D97FA }, 1);
            }
            else if (chud >= 8 && chud <= 9) {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_gold"), TypeIDs::prop, 0x034D97FA }, 1);
            }
            else {
                SpaceTrading.ObtainTradingObject({ id("spice_mat_latticine"), TypeIDs::prop, 0x034D97FA }, 1);
            }
        }
    
    
    
    
    }
   
    
    // rest of code
    return success;
}




bool MiningBeam::OnSelect(Simulator::cSpaceToolData* pTool)
{
    //App::ConsolePrintF(to_string(Simulator::GetActivePlanetRecord()->mAtmosphereScore).c_str());
    //App::ConsolePrintF(to_string(Simulator::GetActivePlanetRecord()->mTemperatureScore).c_str());
	//App::ConsolePrintF("Selected!");
	//SpaceTrading.ObtainTradingObject({ id("spice_mat_copper"), TypeIDs::prop, 0x034D97FA }, 1);
	return false;
}

