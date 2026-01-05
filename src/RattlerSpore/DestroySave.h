#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\CommonIDs.h>
#include <Spore\UTFWin\WinTreeView.h>
#include <Spore\UTFWin\IButton.h>
class DestroySave 
	: public ArgScript::ICommand
{
public:
	DestroySave();
	~DestroySave();

	// Called when the cheat is invoked
	void ParseLine(const ArgScript::Line& line) override;
	
	// Returns a string containing the description. If mode != DescriptionMode::Basic, return a more elaborated description
	const char* GetDescription(ArgScript::DescriptionMode mode) const override;
};

