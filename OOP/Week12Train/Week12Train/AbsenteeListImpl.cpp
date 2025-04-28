//
//  AbsenteeListImpl.cpp
//  Week12Train
//
//  Created by 유진원 on 12/18/24.
//

#include "AbsenteeListImpl.h"

void AbsenteeListImpl::find_duplicates(const std::vector<std::string> &mid, const std::vector<std::string> &finals){
    
    bool check = false;
    
    for (std::string singleMid : mid){
        for (std::string singleFin : finals){
            if(singleMid == singleFin){
                check = true;
                break;
            }
        }
        if(check == true){
            oss << singleMid << std::endl;
            check = false;
            continue;;
        }
    }
}

std::ostringstream& AbsenteeListImpl::get_output_ss(){
    return this->oss;
}

AbsenteeListImpl::~AbsenteeListImpl(){
    
}

AbsenteeListImpl::AbsenteeListImpl(){
    oss << "count" << std::endl;
}
