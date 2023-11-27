#include "stdafx.h"
#include "Fabricator.h"

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

        return false;
}


bool Fabricator::OnSelect(cSpaceToolData* pTool)
{

    pTool->mbIsActive = false;
    pTool->mbIsInUse = false;
    pTool->mRechargeTimer.Start();
    return false;
}