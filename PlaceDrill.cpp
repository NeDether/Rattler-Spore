#include "stdafx.h"
#include "PlaceDrill.h"

PlaceDrill::PlaceDrill()
{
}


PlaceDrill::~PlaceDrill()
{
}

// For internal use, do not modify.
int PlaceDrill::AddRef()
{
	return DefaultRefCounted::AddRef();
}

// For internal use, do not modify.
int PlaceDrill::Release()
{
	return DefaultRefCounted::Release();
}

// You can extend this function to return any other types your class implements.
void* PlaceDrill::Cast(uint32_t type) const
{
	CLASS_CAST(Object);
	CLASS_CAST(PlaceDrill);
	return nullptr;
}
