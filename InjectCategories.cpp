#include "stdafx.h"
#include "InjectCategories.h"

#include <string>


bool InjectCategories::InjectHeader()
{
    PropertyListPtr propertyList;
    App::Property* property;
    ResourceKey* resourceKeys;
    size_t resourceKeysCount = 0;
    static eastl::vector<ResourceKey> resourceKeysVector;
    ResourceKey moderatorCategoryResourceKey;
    static bool hasInjectedCategory = false;

    if (hasInjectedCategory)
    { // never inject twice
        return true;
    }


    // attempt to retrieve property list
    if (!PropManager.GetPropertyList(0x1caa6cd5, 0x6edc12d4, propertyList))
    {
        return false;
    }

    // attempt to retrieve property
    if (!propertyList->GetProperty(0x744717C0, property))
    {
        return false;
    }

    // get resource keys value from property
    if (!App::Property::GetArrayKey(propertyList.get(), 0x744717C0, resourceKeysCount, resourceKeys))
    {
        return false;
    }

    // add resource keys to vector
    for (size_t i = 0; i < resourceKeysCount; i++)
    {
        resourceKeysVector.push_back(resourceKeys[i]);
    }

    // attempt to retrieve resource key of the categories
    if (!ResourceKey::Parse(moderatorCategoryResourceKey, u"AssetBrowserFeedCategories!rattlerspore_category.prop"))
    {
        return false;
    }

    // inject it into the vector
    resourceKeysVector.push_back(moderatorCategoryResourceKey);

    // change the property with the injected category
    property->SetArrayKey(resourceKeysVector.data(), resourceKeysVector.size());
    hasInjectedCategory = true;
    return true;
}


bool InjectCategories::InjectCategory(char16_t* grug)
{
    PropertyListPtr propertyList;
    App::Property* property;
    ResourceKey* resourceKeys;
    size_t resourceKeysCount = 0;
    static eastl::vector<ResourceKey> resourceKeysVector;
    ResourceKey moderatorCategoryResourceKey;
    static bool hasInjectedCategory = false;

    if (hasInjectedCategory)
    { // never inject twice
        //HAHA GET FIXED BOOIIIIIi
       // return true;
    }


    // attempt to retrieve property list
    if (!PropManager.GetPropertyList(0xc06a3df9, 0x06b38241, propertyList))
    {
        return false;
    }

    // attempt to retrieve property
    if (!propertyList->GetProperty(0x744717C1, property))
    {
        return false;
    }

    // get resource keys value from property
    if (!App::Property::GetArrayKey(propertyList.get(), 0x744717C1, resourceKeysCount, resourceKeys))
    {
        return false;
    }
    
    // add resource keys to vector
    resourceKeysVector.clear();
    for (size_t i = 0; i < resourceKeysCount; i++)
    {
        
        resourceKeysVector.push_back(resourceKeys[i]);
    }

    // attempt to retrieve resource key of the categories
    if (!ResourceKey::Parse(moderatorCategoryResourceKey, grug))
    {   
        return false;
    }

    // inject it into the vector
    resourceKeysVector.push_back(moderatorCategoryResourceKey);

    // change the property with the injected category
    property->SetArrayKey(resourceKeysVector.data(), resourceKeysVector.size());
    hasInjectedCategory = true;
    resourceKeysVector.clear();
    return true;
}