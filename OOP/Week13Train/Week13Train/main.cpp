//
//  main.cpp
//  Week13Train
//
//  Created by 유진원 on 12/11/24.
//

#include <iostream>

#include "DialogBuilderImpl.h"
#include "Dialog.h"
int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    
    DialogBuilderImpl *builder = new DialogBuilderImpl();
    builder->build_button("OK");
    builder->build_button("CANCLE");
    builder->build_size(10, 10);
    builder->build_checkbox("Male", 1);
    builder->build_checkbox("Female", 0);
    builder->build_title("Gender Check Dialog");
    
    Dialog *dialog = builder->get_result();
    std::vector comps = dialog->get_components();
    
    for (size_t i = 0; i < comps.size(); ++i) {
        std::cout << "Component " << i + 1 << ":" << std::endl;
        for (const auto& [key, value] : comps[i].properties) { // map 순회
            std::cout << "  " << key << ": " << value << std::endl;
        }
        std::cout << "------" << std::endl;
    }
    
    return 0;
}

