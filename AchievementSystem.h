#pragma once

#include <Spore\BasicIncludes.h>
#include <Spore\App\cJob.h>
#include <Spore\App\JobManager.h>
#include <Spore\UI\ScrollFrameVertical.h>
#include <algorithm>
#define AchievementSystemPtr intrusive_ptr<AchievementSystem>
#define AchievementSystemA (AchievementSystem::Get())[0]

///
/// In your dllmain Initialize method, add the system like this:
/// ModAPI::AddSimulatorStrategy(new AchievementSystem(), AchievmentSystem::NOUN_ID);
///

class AchievementSystem
	: public Simulator::cStrategy
{
public:
	static const uint32_t TYPE = id("RattlerSpore::AchievementSystem");
	static const uint32_t NOUN_ID = TYPE;
	UTFWin::UILayout layout;
	int AddRef() override;
	int Release() override;
	void Initialize() override;
	void Dispose() override;
	const char* GetName() const override;
	bool Write(Simulator::ISerializerStream* stream) override;
	bool Read(Simulator::ISerializerStream* stream) override;
	bool WriteToXML(Simulator::XmlSerializer* writexml) override;
	void Update(int deltaTime, int deltaGameTime) override;

	//
	// You can add more methods here
	//

	bool Achieve(string16 name, string16 desc, ImagePtr grug);
	bool Achieve(string ied);
	bool Close();

	bool Discover(string matname);

	static Simulator::Attribute ATTRIBUTES[];
	static AchievementSystem* Get();
	vector <string> Discoveries;
	bool SecretPhrase;
	int CraftCount = 0;
	int MineCount = 0;

private:
	int counter;
	static AchievementSystem* sInstance;
	UTFWin::UILayout* mpUIlayout;
	//
	// You can add members here
	//
};