#include "stdafx.h"
#include "FabricatorSystem.h"
#include "xFabClose.h"
#include "xFabOpen.h"

/// AUTOGENERATED METHODS ///

int FabricatorSystem::AddRef() {
	return Simulator::cStrategy::AddRef();
}
int FabricatorSystem::Release() {
	return Simulator::cStrategy::Release();
}

const char* FabricatorSystem::GetName() const {
	return "RattlerSpore::FabricatorSystem";
}

bool FabricatorSystem::Write(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Write(stream);
}
bool FabricatorSystem::Read(Simulator::ISerializerStream* stream)
{
	return Simulator::ClassSerializer(this, ATTRIBUTES).Read(stream);
}


bool FabricatorSystem::WriteToXML(Simulator::XmlSerializer* writexml)
{
	return false;
}

/// END OF AUTOGENERATED METHODS ///
////////////////////////////////////

Simulator::Attribute FabricatorSystem::ATTRIBUTES[] = {
	// Add more attributes here
	// This one must always be at the end
	Simulator::Attribute()
};

void FabricatorSystem::Initialize() {

	mpUIlayout = nullptr;
	sInstance = this;
}

void FabricatorSystem::Dispose() {
	
}

void FabricatorSystem::Update(int deltaTime, int deltaGameTime) {
	if (Simulator::IsSpaceGame()) //If we're in the space stage... (adventures do not count)
	{
		
		if (mpUIlayout)
		{
			auto window = mpUIlayout->FindWindowByID(0xFFFFFFFF, false);
			
		}
	}
}

FabricatorSystem* FabricatorSystem::Get()
{
	return sInstance;
}

bool FabricatorSystem::OpenFab(bool sex) {
	if (!mpUIlayout)
	{
		mpUIlayout = new UTFWin::UILayout();
	}

	if (mpUIlayout->LoadByID(id("FabMenu")))
	{
		mpUIlayout->LoadByID(id("FabMenu"));
		mpUIlayout->SetParentWindow(WindowManager.GetMainWindow());
		auto window = mpUIlayout->FindWindowByID(0xFFFFFFFF, false);
		WindowManager.GetMainWindow()->SendToBack(mpUIlayout->GetContainerWindow());

		mpUIlayout->SetVisible(true);
		auto menuWindow = mpUIlayout->FindWindowByID(id("FabMenu"));

		auto closeButton = mpUIlayout->FindWindowByID(id("exitRF"));
		closeButton->AddWinProc(new xFabClose());

		layout.SetParentWindow(window);


		return true;
	}
	return false;
}


bool FabricatorSystem::CloseFab(bool sex) {
	//App::ConsolePrintF("mario");
	if (mpUIlayout)
	{

		
		mpUIlayout->SetVisible(false);
		//App::ConsolePrintF("le test");
		WindowManager.GetMainWindow()->RemoveWindow(mpUIlayout->FindWindowByID(0xFFFFFFFF, false));
		auto Delete(mpUIlayout);
		mpUIlayout = nullptr;
		return true;
	}
	//App::ConsolePrintF("brug");
	return false;
}


FabricatorSystem* FabricatorSystem::sInstance;