#include "stdafx.h"
#include "FabricatorSystem.h"
#include "xFabClose.h"
#include "xFabOpen.h"
#include "RecipeIcon.h"
#include "ResourceIcon.h"
#include "CategoryIcon.h"
#include "Craft.h"
#include <Spore\UTFWin\WinTreeView.h>
#include <Spore\UTFWin\IButton.h>

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
	Selected = NULL;
	mpUIlayout = nullptr;
	sInstance = this;
}

void FabricatorSystem::Dispose() {
	
}
//TODO: FIX THIS CRAP
//eh later
void FabricatorSystem::Update(int deltaTime, int deltaGameTime) {
	if (Simulator::IsSpaceGame()) //If we're in the space stage... (adventures do not count)
	{
		

		if (mWindowOffset != 0 && mpUIlayout)
		{
			auto window = mpUIlayout->FindWindowByID(0xFFFFFFFF, false);
			float offset2 = (((mWindowOffset * -1) + 1) / 8); //max((((windowOffset * -1) + 1) / 8), 1.0)
			mWindowOffset = mWindowOffset + offset2;

			UTFWin::IWindow* parentWindow = window->GetParent();
			Math::Rectangle rec = parentWindow->GetArea();
			window->SetArea(Math::Rectangle(rec.right / 2 - (1601 / 2), (rec.bottom / 2 - (902 / 2)) + mWindowOffset, rec.right / 2 + (1601 / 2), (rec.bottom / 2 + (902 / 2)) + mWindowOffset));
		}
	}
	else
	{
		if (mpUIlayout)
		{
			CloseFab(false);
		}
	}
}

FabricatorSystem* FabricatorSystem::Get()
{
	return sInstance;
}

Recipe& FabricatorSystem::GetRecipe(uint32_t resID) {
	int g = 0;
	for (auto it = RecipeMap.begin(); it != RecipeMap.end(); it++)
	{
		//App::ConsolePrintF("Res ID: %d Iterator: %d Recipe Map ID of Iterator: %d", resID, g, RecipeMap[g].CraftingID);
	}
	if (RecipeMap.find(resID) != RecipeMap.end())
	{
		return RecipeMap[resID];
	}
	//App::ConsolePrintF("GetFailed.");
	return Recipe(0);
}

bool FabricatorSystem::IsSecret(uint32_t resID)
{
	if (Recipe& res = GetRecipe(resID)) {
	
		return res.Secret;
	
	}
	return false;
}

bool FabricatorSystem::InCategory(uint32_t resID, uint32_t cat)
{
	if (Recipe& res = GetRecipe(resID)) {
		//App::ConsolePrintF("The Catagory: %d",res.Cat);
		if (res.Cat == cat) {
			//App::ConsolePrintF("Zurgin' off.");
			return true;
		}
		return false;

	}
	return false;
}

bool FabricatorSystem::SelectRecipe(Recipe ThatRecipe){
	Selected = ThatRecipe;

	auto resourcesWindow = mpUIlayout->FindWindowByID(id("req"), true);
	if (resourcesWindow) {
		vector<UTFWin::IWindow*> shin;
		for (UTFWin::IWindow* child : resourcesWindow->children()) {

			if (child) {
				//resourcesWindow->RemoveWindow(child);
				shin.push_back(child);
			}
		}
		while (shin.size()!=0) {
			
			resourcesWindow->RemoveWindow(shin.back());
			shin.pop_back();
		
		}
	}

	int i = 0;

	vector<Recipe> ingred;
	if (Recipe& res = ThatRecipe) {
		for each (uint32_t zurg in res.Ingredients)
		{
		//	App::ConsolePrintF("%d", zurg);
			if (true)
			{
				UTFWin::UILayout* layout = new UTFWin::UILayout();
				layout->LoadByID(id("recipeslot"));
				layout->SetParentWindow(resourcesWindow);

				layout->SetVisible(true);
				
				if (auto itemWindow = layout->FindWindowByID(id("crapingslot")))
				{
					auto icon = itemWindow->FindWindowByID(id("icon"));
					ResourceKey imgKey;
					PropertyListPtr sillyPropList;
					if (PropManager.GetPropertyList(zurg, 0x034d97fa, sillyPropList))
					{
					//	App::ConsolePrintF("Yay!");
						if (App::Property::GetKey(sillyPropList.get(), 0x3068D95C, imgKey))
						{
						//	App::ConsolePrintF("Wahoo!");
							ImagePtr img;
							if (Image::GetImage(imgKey, img))
							{
								//App::ConsolePrintF("Yipee!");
								ImageDrawable* drawable = new ImageDrawable();
								drawable->SetImage(img.get());
								uint32_t rColor;

								if (App::Property::GetUInt32(sillyPropList.get(), 0x058CBB75, rColor)) {
									//App::ConsolePrintF("ZurgTastic!");
									rColor = rColor + 4278190080;
									Color ColR = Color::Color(rColor);
									icon->SetShadeColor(ColR);
								//	LocalizedString westyorkshire;
								//	App::Property::GetText(sillyPropList.get(), 0x3068D95D, westyorkshire);
								//	itemWindow->FindWindowByID(0x03754e6c)->SetCaption(westyorkshire.GetText());
								}

								//	icon->SetShadeColor(Color::RED); Use later when setting recipe node colors.
								icon->SetDrawable(drawable);
							}
						}
					}
					if (!HasMaterial(res.Ingredients[i], res.IngCount[i])) {
						
						itemWindow->FindWindowByID(id("zurgtastic"))->SetShadeColor(Color::RED);
						
					}

					itemWindow->SetFlag(UTFWin::WindowFlags::kWinFlagAlwaysInFront, true);
					itemWindow->FindWindowByID(id("zurgtastic"))->AddWinProc(new ResourceIcon(itemWindow, zurg, res.IngCount[i]));
					itemWindow->SetLayoutLocation((60 * (i % 6)) + (8 * ((i % 6) + 1)), div((i), 6).quot * 80);

					mapUI.push_back(itemWindow);
				}
				i++;
			}

		}
	
	}

	
	return false;
}

bool FabricatorSystem::OpenFab(bool sex){
	if (!mpUIlayout)
	{
		mpUIlayout = new UTFWin::UILayout();
	}

	if (mpUIlayout->LoadByID(id("FabMenu")))
	{
		
		auto paws = GameTimeManager.Pause(Simulator::TimeManagerPause::CommScreen);
		Selected = NULL;
		//mpUIlayout->LoadByID(id("FabMenu"));
		mpUIlayout->SetVisible(true);
		mpUIlayout->SetParentWindow(WindowManager.GetMainWindow());
		auto window = mpUIlayout->FindWindowByID(0xFFFFFFFF, false);
		window->SetSize(1601.0F, 802.0F);
		WindowManager.GetMainWindow()->SendToBack(mpUIlayout->GetContainerWindow());

		Math::Rectangle rec = window->GetParent()->GetArea();

		if (sex)
		{
			mWindowOffset = (rec.bottom / 2 + (902 / 2));
		}
		else
		{
			mWindowOffset = 0;
		}

		window->SetArea(Math::Rectangle(rec.right / 2 - (1601 / 2), (rec.bottom / 2 - (902 / 2)) + mWindowOffset, rec.right / 2 + (1601 / 2), (rec.bottom / 2 + (902 / 2)) + mWindowOffset));


		auto closeButton = mpUIlayout->FindWindowByID(id("exitRF"));
		closeButton->AddWinProc(new xFabClose());

		auto craftButton = mpUIlayout->FindWindowByID(id("craft"));
		craftButton->AddWinProc(new Craft());


		auto menuWindow = mpUIlayout->FindWindowByID(id("FabMenu"));
		layout.SetParentWindow(window);

		ReadRecipes();
		return true;
	}
	return false;
}




bool FabricatorSystem::CloseFab(bool sex) {
	//App::ConsolePrintF("mario");
	if (mpUIlayout)
	{

		
		auto paws = GameTimeManager.Resume(Simulator::TimeManagerPause::CommScreen);
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

bool FabricatorSystem::Fabricate(Recipe res)
{
	if (!res) {
		return false;
	}
	if (!AbleToCraft(res)) {
		return false;
	}
	int j = 0;
	for each (uint32_t mat in res.Ingredients) {
		if (!UseMaterial(mat, res.IngCount[j])) 
		{
			return false;
		}
			j++;
	}
	//If a spacetrading~
	if (res.CargoType) {
		if (!GiveSpice(res.mToolID, res.productAmount)) {

			return false;
		}
	}
	else {
	//If a spacetools~

		if (!GiveItem(res.mToolID, res.productAmount)) {

			return false;
		}
	}

	AchievementSystemA.CraftCount += res.productAmount;

	if (AchievementSystemA.CraftCount > 50) {
		AchievementSystemA.Achieve("ach_core_cr1");
	}
	if (AchievementSystemA.CraftCount > 200) {
		AchievementSystemA.Achieve("ach_core_cr2");
	}
	if (AchievementSystemA.CraftCount > 1000) {
		AchievementSystemA.Achieve("ach_core_cr3");
	}
	if (AchievementSystemA.CraftCount > 7500) {
		AchievementSystemA.Achieve("ach_core_cr4");
	}

	return true;
}

void FabricatorSystem::RenderRecipies(uint32_t cat)
{
	auto categoryWindow = mpUIlayout->FindWindowByID(id("cat_list"), true);
	auto inventoryWindow = mpUIlayout->FindWindowByID(id("cat"), true);
	auto catText = mpUIlayout->FindWindowByID(id("cat_name"), true);
	//Remove children of these windows.
	if (inventoryWindow) {
		vector<UTFWin::IWindow*> shin;
		for (UTFWin::IWindow* child : inventoryWindow->children()) {

			if (child) {
				shin.push_back(child);
			}
		}
		while (shin.size() != 0) {

			inventoryWindow->RemoveWindow(shin.back());
			shin.pop_back();

		}
	}

	//Sets the name of the fabricator to the selected categories's name.
	


			
	if (categoryWindow) {
		vector<UTFWin::IWindow*> shit;
		for (UTFWin::IWindow* child : categoryWindow->children()) {

			if (child) {
				shit.push_back(child);
			}
		}
		while (shit.size() != 0) {

			categoryWindow->RemoveWindow(shit.back());
			shit.pop_back();

		}
	}
	int i = 0;
	
	vector<Recipe> validRecipes;
	vector<Recipe> invalidRecipes;
	vector<Category> categoryList;
	//Emplaces categories first.
	for (auto it = CatMap.begin(); it != CatMap.end(); it++) {
		//Emplaces Nodes on Red-Black tree.
		categoryList.insert(categoryList.begin(), it.mpNode->mValue.second);
	
	}

	//Render Categories.

	for each (Category zurg in categoryList)
	{
		UTFWin::UILayout* layout = new UTFWin::UILayout();
		//Uses recipeslot UI node.
		layout->LoadByID(id("catslot"));
		layout->SetParentWindow(categoryWindow);

		layout->SetVisible(true);

		if (auto itemWindow = layout->FindWindowByID(id("crapingslotZ")))
		{
			

			auto icon = itemWindow->FindWindowByID(id("iconZ"));
			ResourceKey imgKey;
			PropertyListPtr sillyPropList;

			if (PropManager.GetPropertyList(zurg.mCatID, 0x30608f0b, sillyPropList))
			{
				if (App::Property::GetKey(sillyPropList.get(), 0x3068D95C, imgKey))
				{
					if (catText) {
						//App::ConsolePrintF("cat name exists");
						if (cat == zurg.Cat) {
							LocalizedString silly;
							//App::ConsolePrintF("found the hash of the icon tool.");
							if (App::Property::GetText(sillyPropList.get(), 0x3068D95D, silly))
							{
								//App::ConsolePrintF("found the text of the icon tool.");
								//Gets spaceToolDescription of the item.

								string16 products;
								products.assign_convert(silly.GetText());
								mpUIlayout->FindWindowByID(id("cat_name"), true)->SetCaption(products.c_str());
							}
						
						
						}
					}
					//App::ConsolePrintF("Wahoo!");
					ImagePtr img;
					if (Image::GetImage(imgKey, img))
					{
						ImageDrawable* drawable = new ImageDrawable();
						drawable->SetImage(img.get());

						//	icon->SetShadeColor(Color::RED); Use later when setting recipe node colors.
						icon->SetDrawable(drawable);

					}
				}
			}
			if (zurg.Cat != cat) {

				itemWindow->FindWindowByID(id("zurgtasticZ"))->SetShadeColor(Color(0.5, 0.5, 0.5, 0.8));

			}
			itemWindow->SetFlag(UTFWin::WindowFlags::kWinFlagAlwaysInFront, true);
			itemWindow->FindWindowByID(id("zurgtasticZ"))->AddWinProc(new CategoryIcon(itemWindow, zurg));
			itemWindow->SetLayoutLocation((55 * (i % 16)) + (8 * ((i % 16) + 1)), div((i), 16).quot * 75);

			mapUI.push_back(itemWindow);
		}
		i++;
	}
	//Resets i
	i = 0;
	//Emplaces non-secret and selected category Recipes
	for (auto it = RecipeMap.begin(); it != RecipeMap.end(); it++)
	{
		//string error;
		
		if (!IsSecret(it.mpNode->mValue.second.CraftingID)) //Replace this with if secret later
		{	
			if (InCategory(it.mpNode->mValue.second.CraftingID, cat)) {
				validRecipes.push_back(it.mpNode->mValue.second);
				//App::ConsolePrintF("Added Valid");
			}
			else
			{	//App::ConsolePrintF("Is not in category, skipping");
				invalidRecipes.push_back(it.mpNode->mValue.second);
			}

			
		}
		else
		{
			//App ::ConsolePrintF("Is secret, skipping.");
			invalidRecipes.push_back(it.mpNode->mValue.second);
		}

	}

	//validRecipes.insert(validRecipes.end(), validRecipes.begin(), invalidRecipes.end());
	


	for each (Recipe zurg in validRecipes)
	{
		if (true)
		{
			bool canShow = false;
	
			canShow = true;


			if (canShow)
			{
				UTFWin::UILayout* layout = new UTFWin::UILayout();
				layout->LoadByID(id("recipeslot"));
				layout->SetParentWindow(inventoryWindow);

				layout->SetVisible(true);
				

				

				if (auto itemWindow = layout->FindWindowByID(id("crapingslot")))
				{
					auto icon = itemWindow->FindWindowByID(id("icon"));
					ResourceKey imgKey;
					PropertyListPtr sillyPropList;
					//If is a cargotype, get info from spacetrading~ rather than spacetools~
					if (zurg.CargoType) {
						App::ConsolePrintF("Wahoo!");
						if (PropManager.GetPropertyList(zurg.mToolID, 0x034d97fa, sillyPropList))
						{
							ImagePtr img;
							if (App::Property::GetKey(sillyPropList.get(), 0x3068D95C, imgKey))
							{
								//App::ConsolePrintF("Wahoo!");
								ImagePtr img;
								if (Image::GetImage(imgKey, img))
								{
									ImageDrawable* drawable = new ImageDrawable();
									drawable->SetImage(img.get());
									uint32_t rColor;

									if (App::Property::GetUInt32(sillyPropList.get(), 0x058CBB75, rColor)) {
										//App::ConsolePrintF("ZurgTastic!");
										rColor = rColor + 4278190080;
										Color ColR = Color::Color(rColor);
										icon->SetShadeColor(ColR);
										//	LocalizedString westyorkshire;
										//	App::Property::GetText(sillyPropList.get(), 0x3068D95D, westyorkshire);
										//	itemWindow->FindWindowByID(0x03754e6c)->SetCaption(westyorkshire.GetText());
									}

									//	icon->SetShadeColor(Color::RED); Use later when setting recipe node colors.
									icon->SetDrawable(drawable);
								}
							}
						}
					}
					else {
						//Get it from spacetools~
						if (PropManager.GetPropertyList(zurg.mToolID, 0x30608f0b, sillyPropList))
						{
							ImagePtr img;
							if (App::Property::GetKey(sillyPropList.get(), 0x3068D95C, imgKey))
							{
								//App::ConsolePrintF("Wahoo!");
								ImagePtr img;
								if (Image::GetImage(imgKey, img))
								{
									ImageDrawable* drawable = new ImageDrawable();
									drawable->SetImage(img.get());
									//	icon->SetShadeColor(Color::RED); Use later when setting recipe node colors.
									icon->SetDrawable(drawable);
								}
							}
						}
					}

					itemWindow->SetFlag(UTFWin::WindowFlags::kWinFlagAlwaysInFront, true);
					itemWindow->FindWindowByID(id("zurgtastic"))->AddWinProc(new RecipeIcon(itemWindow, zurg));
					itemWindow->SetLayoutLocation((55 * (i % 16)) + (8 * ((i % 16) + 1)), div((i), 16).quot * 75);

					mapUI.push_back(itemWindow);
				}
				i++;
			}
		}

	}

}

bool FabricatorSystem::ReadRecipes()
{
	//Reads Categories First
	vector<uint32_t> categoryIDs;
	PropManager.GetPropertyListIDs(id("RecipeCategories"), categoryIDs);
	for each (uint32_t catID in categoryIDs)
	{
		try
		{
			Category cat = Category(catID);
			CatMap.emplace(cat.mCatID, cat);
		}
		catch (std::exception except)
		{
			const char* text = except.what();
			wstring report;
			report.assign_convert(text);
			MessageBox(NULL, report.c_str(), LPCWSTR(u"Error adding category"), 0x00000010L);
		}


	}
	//Reads Recipies Second
	vector<uint32_t> recipeIDs;
	PropManager.GetPropertyListIDs(id("Recipes"), recipeIDs);
	//App::ConsolePrintF("Reading Recipes...");
		
	
		for each (uint32_t resID in recipeIDs)
		{
			try
			{
				Recipe res = Recipe(resID);
				
				bool SecretRecip;
				if (App::Property::GetBool(res.mpPropList.get(), id("SecretRecip"), SecretRecip))
				{	
					if (SecretRecip != true) {
					
						RecipeMap.emplace(res.CraftingID, res);
					
					}

						
				}
				else
				{
					
					RecipeMap.emplace(res.CraftingID, res);
				}
			}
			catch (std::exception except)
			{
				const char* text = except.what();
				wstring report;
				report.assign_convert(text);
				MessageBox(NULL, report.c_str(), LPCWSTR(u"Error adding recipe"), 0x00000010L);
			}
		
		}
	RenderRecipies(id("tool_category"));
	return false;

}

bool FabricatorSystem::UseMaterial(uint32_t WareID, int neededAmount)
{//Returns True if Has Material. Returns False if Does not.
	if (PropManager.HasPropertyList(id("creativeTools"), id("rattlerConfig"))) {
		return true;
	}
	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	auto X = inventory->IndexOf(Simulator::SpaceInventoryItemType(4), { WareID, 0, 0 });
	auto H = inventory->GetItem(X);
	if (H == nullptr) {
		//App::ConsolePrintF("Does not have Any Resources...");
		return false;
	}
	size_t itemCount;
	if (H->GetItemCount(itemCount))
	{

		if (itemCount >= neededAmount) {

			//App::ConsolePrintF("The total ''Count'' in the inv: %d", H);
			auto D = inventory->RemoveItem(H);

			if (itemCount != neededAmount) {

				SpaceTrading.ObtainTradingObject({ WareID, 0, 0 }, (itemCount - neededAmount));

			}
			return true;
			//do stuff
		}
		if (itemCount == 0) {
			//Deletes the cargo if reaches 0 because spore is ok with having '0' of a cargo slot.
			auto D = inventory->RemoveItem(H);
		}
		//App::ConsolePrintF("Insufficient Resources...");
	}
	//App::ConsolePrintF("I had a bruh moment.");
	return false;
}


bool FabricatorSystem::GiveItem(uint32_t WareID, uint32_t givenAmount)
{ //Returns true if Gives Item, returns false if does not.
				//Gives energy potion.
	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	cSpaceToolDataPtr tool;
	ToolManager.LoadTool({ WareID, 0, 0 }, tool);
	tool->mCurrentAmmoCount = givenAmount;

	inventory->AddItem(tool.get());

	if (inventory->mbHasAddedItem) {
		return true;

	}
	return false;
}
bool FabricatorSystem::GiveSpice(uint32_t WareID, uint32_t givenAmount)
{
	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	
	SpaceTrading.ObtainTradingObject({ WareID, 0, 0 }, givenAmount);



	return true;
}
bool FabricatorSystem::HasMaterial(uint32_t WareID, int neededAmount)
{ //Checks if has the materials in the first place before using them up.
	if (PropManager.HasPropertyList(id("creativeTools"), id("rattlerConfig"))) {
		return true;
	}
	auto inventory = SimulatorSpaceGame.GetPlayerInventory();
	auto X = inventory->IndexOf(Simulator::SpaceInventoryItemType(4), { WareID, 0, 0 });
	auto H = inventory->GetItem(X);
	if (H == nullptr) {
	//	App::ConsolePrintF("Does not have Any Resources...");
		return false;
	}
	size_t itemCount;
	if (H->GetItemCount(itemCount))
	{

		if (itemCount >= neededAmount) {

			return true;
			//do stuff
		}

	//	App::ConsolePrintF("Insufficient Resources...");
	}
//	App::ConsolePrintF("I had a bruh moment.");
	return false;
}
bool FabricatorSystem::AbleToCraft(Recipe res)
{
	int r = 0;
	for each (uint32_t mat in res.Ingredients) {
		if (!HasMaterial(mat, res.IngCount[r])) {
		
			return false;
		}
		
		r++;
	}

	return true;
}
FabricatorSystem* FabricatorSystem::sInstance;


Recipe::Recipe(uint32_t propID) {

	if (propID == 0)
	{
		CraftingID = 0;
		mToolID = 0;
		productAmount = 0;
		Cat = 0;
		Secret = true;
		CargoType = false;
		return;
	}

	if (PropManager.GetPropertyList(propID, id("Recipes"), mpPropList))
	{
		CraftingID = propID;
		App::Property::GetUInt32(mpPropList.get(), id("Recipe"), mToolID); //Gets .prop of the item it gives you.
		//App::Property::GetText(mpPropList.get(), id("CName"), CName);
		//App::Property::GetText(mpPropList.get(), id("CDesc"), CDesc);
		CargoType = false;
		if (!App::Property::GetUInt32(mpPropList.get(), id("productAmount"), productAmount))
		{
			string error = "Research property list " + to_string(propID) + " has no output amount!";
			throw std::invalid_argument(error.c_str());
		}
		App::Property::GetBool(mpPropList.get(), id("SecretRecip"), Secret);
		
		if (!App::Property::GetBool(mpPropList.get(), id("CargoType"), CargoType)) {
			CargoType = false;
		};
		App::Property::GetUInt32(mpPropList.get(), id("Catagory"), Cat);
		size_t count;
		uint32_t* ids;
		App::Property::GetArrayUInt32(mpPropList.get(), id("Ingredients"), count, ids);
		if (count != 0)
		{
			for (int i = 0; i < count; i++)
			{
				Ingredients.push_back(ids[i]);
			}
		}

		App::Property::GetArrayUInt32(mpPropList.get(), id("IngCount"), count, ids);
		if (count != 0)
		{
			for (int i = 0; i < count; i++)
			{
				IngCount.push_back(ids[i]);
			}
		}

		App::Property::GetArrayUInt32(mpPropList.get(), id("Blueprint"), count, ids);
		if (count != 0)
		{
			for (int i = 0; i < count; i++)
			{
				Blueprint.push_back(ids[i]);
			}
		}

	
	}
	else
	{
		string error = "Crafting property " + to_string(propID) + " is not valid!";
		throw std::invalid_argument(error.c_str());
	}


}

Recipe::Recipe(){
	CraftingID = 0;
	mToolID = 0;
	productAmount = 0;
	Cat = 0;
	Secret = true;
	CargoType = false;
}

Recipe::operator bool() const
{
	return (CraftingID != 0);
}

Category::Category(uint32_t propID)
{
	if (propID == 0)
	{
		mCatID = 0; //Tool Icon n' name. :emoji_9:
		Cat = 0; //The internal id or something.

		return;
	}

	if (PropManager.GetPropertyList(propID, id("RecipeCategories"), mpPropList))
	{
		App::Property::GetUInt32(mpPropList.get(), id("CatID"), mCatID);
		Cat = propID;

	}
	else
	{
		string error = "Category prop " + to_string(propID) + " is not valid!";
		throw std::invalid_argument(error.c_str());
	}

}

Category::Category()
{
	mCatID = 0; //Tool Icon n' name. :emoji_9:
	Cat = 0; //The internal id or something.
}
