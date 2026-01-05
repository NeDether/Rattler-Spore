#pragma once
#include <exception>
#include <stdexcept>
#include <Spore\BasicIncludes.h>
#include <Spore\App\cJob.h>
#include <Spore\App\JobManager.h>
#include <Spore\UI\ScrollFrameVertical.h>
#include <set>
#include <Spore/UTFWin/UILayout.h>
#include "Fabricator.h"


//Pointers as shown in solar spore code by VanillaCold the absolute GOAT
#define uFabMenuPtr intrusive_ptr<uFabMenu>
#define FabMenu (uFabMenu::Get())[0]

using namespace UTFWin;

class uFabMenu
	: public IWinProc
	, public DefaultRefCounted

{
public:
	static const uint32_t TYPE = id("uFabMenu");
	uFabMenu();
	~uFabMenu();


};