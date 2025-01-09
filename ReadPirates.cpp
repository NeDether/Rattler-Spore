#include "stdafx.h"
#include "ReadPirates.h"
using namespace Simulator;
ReadPirates::ReadPirates()
{
}


ReadPirates::~ReadPirates()
{
}


void ReadPirates::ParseLine(const ArgScript::Line& line)
{

	auto ufos = GetData<cGameDataUFO>(); //Causing Error

	for (auto thaUFO : ufos ) {
		if (thaUFO->mUFOType == (int) UfoType::Unk7) {
			cGameDataUFO* readMe = thaUFO.get();
			readMe->SetModelKey({ 0x2538FB35, TypeIDs::ufo, GroupIDs::UFOModels });

		
		}

	
	}
	// This method is called when your cheat is invoked.
	// Put your cheat code here.
}

const char* ReadPirates::GetDescription(ArgScript::DescriptionMode mode) const
{
	if (mode == ArgScript::DescriptionMode::Basic) {
		return "This cheat does something.";
	}
	else {
		return "ReadPirates: Elaborate description of what this cheat does.";
	}
}
