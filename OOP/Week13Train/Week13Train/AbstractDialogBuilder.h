//
//  AbstractDialogBuilder.h
//  Week13Train
//
//  Created by 유진원 on 12/11/24.
//

#ifndef AbstractDialogBuilder_h
#define AbstractDialogBuilder_h

#include "Dialog.h"
#include <string>
class AbstractDialogBuilder{
public:
    virtual void build_title(const std::string & title) = 0;
    virtual void build_size(int width, int height) = 0;
    virtual void build_button(const std::string& lable) = 0;
    virtual void build_checkbox(const std::string& label, bool checked) = 0;
    virtual Dialog* get_result() = 0;
    virtual ~AbstractDialogBuilder() = default;
};

#endif /* AbstractDialogBuilder_h */
