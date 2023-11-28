#include "stdafx.h"
#include "Fabricator.h"
#include <Spore\UTFWin\WinTreeView.h>
#include <Spore\UTFWin\IButton.h>
#include "FabricatorSystem.h"

using namespace Simulator;

Fabricator::Fabricator()
{


}
Fabricator::~Fabricator()
{


}

bool Fabricator::OnHit(cSpaceToolData* pTool, const Vector3& position, SpaceToolHit hitType, int) {
    return false;
}
bool Fabricator::Update(cSpaceToolData* pTool, bool showErrors, const char16_t** ppFailText)
{
    if (pTool->mRechargeTimer.IsRunning() == true)
    {
        if (pTool->mRechargeTimer.GetElapsed().LowPart >= pTool->mRechargeRate * 1000)
        {
            pTool->mRechargeTimer.Stop();
        }
    }
    if (pTool->mRechargeTimer.IsRunning() == false) {
        return true;
    }
        return false;
}


bool Fabricator::OnSelect(cSpaceToolData* pTool)
{   
    FabricatorSystemA.OpenFab(true);



  //  if (window->GetFlags() & UTFWin::kWinFlagEnabled) {
        // This code only gets executed if the window is enabled
   //     window->SetFlag(UTFWin::kWinFlagEnabled, false);
 //   }
   // else {
    //    window->SetFlag(UTFWin::kWinFlagEnabled, true);
    //}
    pTool->mbIsActive = false;
    pTool->mbIsInUse = false;
    pTool->mRechargeTimer.Start();
    return false;
}