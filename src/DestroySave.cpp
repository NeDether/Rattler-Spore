#include "stdafx.h"
#include "DestroySave.h"
#include "AchievementSystem.h"
DestroySave::DestroySave()
{
}


DestroySave::~DestroySave()
{
}


void DestroySave::ParseLine(const ArgScript::Line& line)
{	
	if (Simulator::IsSpaceGame()) //If we're in the space stage... (adventures do not count)
	{

	}
	else {
	
		App::ConsolePrintF("Save File Erased.");
		return;
	}

	//AchievementSystemA.SecretPhrase = true;
	PropertyListPtr sillyPropList;
	ResourceKey imgKey;
	//Gets the achievment spacetool
	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	if (inventory->GetTool({ id("ach_core_sec"), 0, 0 }) != nullptr) {
		App::ConsolePrintF("Achievement already achieved.");
		return;
	}

	if (PropManager.GetPropertyList(0xf3e2a175, 0x30608f0b, sillyPropList))
	{
		LocalizedString toolName;
		LocalizedString toolDesc;

		
		if (App::Property::GetText(sillyPropList.get(), 0x3068D95D, toolName) && (App::Property::GetText(sillyPropList.get(), 0x04CAD19B, toolDesc)))
		{
			string16 achName;
			string16 achDesc;
			achName.assign_convert(toolName.GetText());
			achDesc.assign_convert(toolDesc.GetText());
			//App::ConsolePrintF("sex");
			if (App::Property::GetKey(sillyPropList.get(), 0x3068D95C, imgKey))
			{
				ImagePtr img;
				if (UTFWin::Image::GetImage(imgKey, img))
				{
				//	App::ConsolePrintF("autism");
					AchievementSystemA.Achieve(achName, achDesc, img);


					cSpaceToolDataPtr tool;
					ToolManager.LoadTool({ id("ach_core_sec"), 0, 0 }, tool);
					inventory->AddItem(tool.get());
				}
			}
		}
		


	}
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
}

const char* DestroySave::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "";
	}
	else {
		return "...";
	}
}
