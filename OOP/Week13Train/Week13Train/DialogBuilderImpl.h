//
//  DialogBuilderImpl.h
//  Week13Train
//
//  Created by 유진원 on 12/11/24.
//

#ifndef DialogBuilderImpl_h
#define DialogBuilderImpl_h

#include "AbstractDialogBuilder.h"
class DialogBuilderImpl : AbstractDialogBuilder{
private:
    Dialog * dialog;
public:
    DialogBuilderImpl();
    void build_title(const std::string & title);
    void build_size(int width, int height);
    void build_button(const std::string& lable);
    void build_checkbox(const std::string& label, bool checked);
    Dialog* get_result();
    
};
#endif /* DialogBuilderImpl_h */
