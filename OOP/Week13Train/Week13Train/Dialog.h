//
//  Dialog.h
//  Week13Train
//
//  Created by 유진원 on 12/11/24.
//

#ifndef Dialog_h
#define Dialog_h

#include <vector>
#include <map>
class Dialog{
public:
    struct Component{
        std::map<std::string, std::string> properties;
    };
private:
    int width;
    int height;
    std::vector<Component> components;
public:
    Dialog(): width(0), height(0){}
    void set_size(int width, int height){
        this->width = width;
        this->height = height;
    }
    void add_component(const Component &component){
        components.push_back(component);
    }
    int get_width() const {return width;}
    int get_height() const {return height;}
    const std::vector<Component>& get_components() const
    {return components;}
};
#endif /* Dialog_h */

