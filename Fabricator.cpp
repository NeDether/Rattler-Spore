#include "stdafx.h"
#include "Fabricator.h"
#include <Spore\UTFWin\WinTreeView.h>
#include <Spore\UTFWin\IButton.h>


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
    

    auto window = WindowManager.GetMainWindow();
    layout.LoadByID(id("FabMenu"));
    layout.SetVisible(true);
    auto menuWindow = layout.FindWindowByID(id("FabMenu"));
    layout.SetParentWindow(window);
    


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