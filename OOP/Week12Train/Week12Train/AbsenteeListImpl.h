//
//  AbsenteeListImpl.h
//  Week12Train
//
//  Created by 유진원 on 12/18/24.
//

#ifndef AbsenteeListImpl_h
#define AbsenteeListImpl_h

#include "AbstractAbsenteeList.h"

class AbsenteeListImpl : public AbstractAbsenteeList{
private:
    std::ostringstream oss;
protected:
    void find_duplicates(
        const std::vector<std::string>& mid,
        const std::vector<std::string>& finals);
    std::ostringstream& get_output_ss();
public:
    AbsenteeListImpl();
    ~AbsenteeListImpl();
};

#endif /* AbsenteeListImpl_h */
