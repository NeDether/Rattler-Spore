#pragma once

#include <Spore\BasicIncludes.h>

#define xFabOpenPtr intrusive_ptr<xFabOpen>

// To avoid repeating UTFWin:: all the time.
using namespace UTFWin;

class xFabOpen 
	: public IWinProc
	, public DefaultRefCounted
{
public:
	static const uint32_t TYPE = id("xFabOpen");
	
	xFabOpen();
	~xFabOpen();

	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
	void hell();
	int GetEventFlags() const override;
	// This is the function you have to implement, called when a window you added this winproc to received an event
	bool HandleUIMessage(IWindow* pWindow, const Message& message) override;
	
private:
};