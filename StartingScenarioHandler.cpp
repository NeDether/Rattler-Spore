#include "stdafx.h"
#include "StartingScenarioHandler.h"

StartingScenarioHandler::StartingScenarioHandler()
{
}


StartingScenarioHandler::~StartingScenarioHandler()
{
}

// For internal use, do not modify.
int StartingScenarioHandler::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int StartingScenarioHandler::Release()
{
	return DefaultRefCounted::Release();
}

void StartingScenarioHandler::Update()
{
	if (Simulator::GetGameModeID() == kGGEMode) {
		if (WindowManager.GetMainWindow()->FindWindowByID(0x0668E2BB)) {
			UTFWin::IWindow* stageDesc = WindowManager.GetMainWindow()->FindWindowByID(0x0668E2BB, true);
			
			LocalizedString stageDescText;

			stageDescText.SetText(0x1082e1c6, 0x00000000, u"Experience the Space Stage like never before. Exploit valueble resources. Fabricate new technologies. Subjegate or befriend your intergalactic peers. Will you be set on a path of creating new life, or destroying those who stand in your way?");

			stageDesc->SetCaption(stageDescText.GetText());

		}
	}

}

// You can extend this function to return any other types your class implements.
void* StartingScenarioHandler::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(StartingScenarioHandler);
	return nullptr;
}
