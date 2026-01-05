#pragma once

#include <Spore\BasicIncludes.h>
#include "AchievementSystem.h"
class ViewCrafts 
	: public ArgScript::ICommand
{
public:
	ViewCrafts();
	~ViewCrafts();

	// Called when the cheat is invoked
	void ParseLine(const ArgScript::Line& line) override;
	
	// Returns a string containing the description. If mode != DescriptionMode::Basic, return a more elaborated description
	const char* GetDescription(ArgScript::DescriptionMode mode) const override;
};

