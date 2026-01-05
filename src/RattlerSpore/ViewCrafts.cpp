#include "stdafx.h"
#include "ViewCrafts.h"

ViewCrafts::ViewCrafts()
{
}


ViewCrafts::~ViewCrafts()
{
}


void ViewCrafts::ParseLine(const ArgScript::Line& line)
{
	App::ConsolePrintF("You Crafted %d times!", AchievementSystemA.CraftCount);
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
}

const char* ViewCrafts::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "View how many times you have crafted stuff.";
	}
	else {
		return "ViewCrafts: This is for debuggging purposes.";
	}
}
