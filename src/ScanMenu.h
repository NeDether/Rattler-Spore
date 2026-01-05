#pragma once

#include <Spore\BasicIncludes.h>
#include "stdafx.h"
#include "Spore/Simulator/SubSystem/SpaceTrading.h"
#include <Spore\BasicIncludes.h>
#include <Spore/CommonIDs.h>
#include <Spore/Simulator/cSpaceToolData.h>
#include "FabricatorSystem.h"
#include <exception>
#include <stdexcept>
#include <Spore\App\cJob.h>
#include <Spore\App\JobManager.h>
#include <Spore\UI\ScrollFrameVertical.h>
#include <set>

#define ScanMenuPtr intrusive_ptr<ScanMenu>
#define ScanMenuA (ScanMenu::Get())[0]
///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new ScanMenu(), ScanMenu::NOUN_ID);
///

class ScanMenu
	: public Simulator::cStrategy
{
public:
	static const uint32_t TYPE = id("RattlerSpore::ScanMenu");
	static const uint32_t NOUN_ID = TYPE;
	UTFWin::UILayout layout;
	int AddRef() override;
	int Release() override;
	void Initialize() override;
	void Dispose() override;
	const char* GetName() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool Read(Simulator::ISerializerStream* stream) override;
	void Update(int deltaTime, int deltaGameTime) override;
	bool WriteToXML(Simulator::XmlSerializer* writexml) override;
	vector<UTFWin::IWindow*> mapUI;
	bool AddResources(vector<uint32_t> resources);
	bool OpenScan(bool sex);
	bool CloseScan(bool sex);
	bool DeleteScan(bool sex);
	bool getClosed();
	//
	// You can add more methods here
	//
	static ScanMenu* Get();
	static Simulator::Attribute ATTRIBUTES[];

private:
	//
	// You can add members here
	//
	int counter;
	bool close;
	static ScanMenu* sInstance;
	UTFWin::UILayout* mpUIlayout;
	float mWindowOffset;
};