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
        
        auto b = original_function(this, name, arg_4, arg_8);
        if (name.instanceID == id("GGENewGameFlowUIv1-EP1")) {
        //    ManualBreakpoint();
            //ResourceKey newGGE = ResourceKey(id("GGE_SpaceDesc"), name.typeID, name.groupID);
                App::ConsolePrintF("RETARD ALERT");
            auto imageWindow = this->FindWindowByID(0x05941BB0, true);
  
 
            UTFWin::ImageDrawable::SetImageForWindow(imageWindow, { id("RSporeGGENewImage"),0x2F7D0004 ,0x74f5252c });
            UTFWin::IWindow* stageDesc = this->FindWindowByID(0x0668E2BB, true);
            App::ConsolePrintF("%s", stageDesc->GetCaption());
            LocalizedString stageDescText;
           
            stageDescText.SetText(0x1082e1c6, 0x00000000, u"I AM THE RATTLERSPORE!");
          
            stageDesc->SetCaption(stageDescText.GetText());
            App::ConsolePrintF("%s", stageDesc->GetCaption());
            //return original_function(this, newGGE, arg_4, arg_8);

        }
  
        
        return b;
    }


};


member_detour(SetVisibleSPUI_Detour, UTFWin::UILayout, bool(bool)) {
    bool detoured(bool value) {

        auto b = original_function(this, value);
        
        
        return b;
    }

    
};