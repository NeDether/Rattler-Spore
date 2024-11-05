#pragma once
#include "stdafx.h"


using namespace ArgScript;

//bool Class::HandleUIMessage(IWindow* window, const Message& message)
//{
  //  if (message.IsType(kMsgButtonClick)) {
    //    auto id = message.source->GetControlID();
      //  if (id == 0x05384D05) {
//            DoThing();
  //      }
  //  }
    // returning true stops the message from continuing on
  //  return true;
//}

member_detour(ReadSPUI_Detour, UTFWin::UILayout, bool(const ResourceKey&, bool, uint32_t)) {
    bool detoured(const ResourceKey & name, bool arg_4, uint32_t arg_8) {
        if (name.instanceID == id("GGENewGameFlowUIv1-EP1")) {
            ResourceKey newGGE = ResourceKey(id("RsporeNewGameGGE"), name.typeID, name.groupID);
            return original_function(this, newGGE, arg_4, arg_8);
        }
        return original_function(this, name, arg_4, arg_8);
    }


};