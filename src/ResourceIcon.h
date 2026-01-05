#pragma once

#include <Spore\BasicIncludes.h>

#define ResourceIconPtr intrusive_ptr<ResourceIcon>

// To avoid repeating UTFWin:: all the time.
using namespace UTFWin;

class ResourceIcon 
	: public IWinProc
	, public DefaultRefCounted
{
public:
	static const uint32_t TYPE = id("ResourceIcon");
	
	ResourceIcon(UTFWin::IWindow* window, uint32_t juh, uint32_t needed);
	~ResourceIcon();

	int AddRef() override;
	int Release() override;
	void* Cast(uint32_t type) const override;
	
	int GetEventFlags() const override;
	// This is the function you have to implement, called when a window you added this winproc to received an event
	bool HandleUIMessage(IWindow* pWindow, const Message& message) override;

private:
	uint32_t myResource;
	UTFWin::IWindow* mapItemWindow;
	string16 mapError;
	UTFWin::Tooltip* myTooltip;
};
