//
//  DialogBuilderImpl.cpp
//  Week13Train
//
//  Created by 유진원 on 12/11/24.
//

#include "DialogBuilderImpl.h"

DialogBuilderImpl::DialogBuilderImpl(){
    dialog = new Dialog();
}
void DialogBuilderImpl::build_title(const std::string & title){
    Dialog::Component titleComponent;
    titleComponent.properties["type"] = "title";
    titleComponent.properties["label"] = title;
    dialog->add_component(titleComponent);
}
void DialogBuilderImpl::build_size(int width, int height){
    dialog->set_size(width, height);
}
void DialogBuilderImpl::build_button(const std::string& label){
    Dialog::Component buttonComponent;
    buttonComponent.properties["type"] = "button";
    buttonComponent.properties["label"] = label;
    dialog->add_component(buttonComponent);
}
void DialogBuilderImpl::build_checkbox(const std::string& label, bool checked){
    Dialog::Component checkboxComponent;
    checkboxComponent.properties["type"] = "checkbox";
    checkboxComponent.properties["label"] = label;
    checkboxComponent.properties["value"] = checked ? "true" : "false";
    dialog->add_component(checkboxComponent);
}
Dialog* DialogBuilderImpl::get_result(){
    return dialog;
}

