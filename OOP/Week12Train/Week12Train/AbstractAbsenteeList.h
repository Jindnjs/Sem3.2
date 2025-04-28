//
//  AbstractAbsenteeList.h
//  Week12Train
//
//  Created by 유진원 on 12/18/24.
//

#ifndef AbstractAbsenteeList_h
#define AbstractAbsenteeList_h

#include <string>
#include <sstream>
#include <vector>

class AbstractAbsenteeList
{
protected:
     virtual std::ostringstream& get_output_ss() = 0;
     virtual void find_duplicates(
        const std::vector<std::string>& mid,
        const std::vector<std::string>& final) = 0;
public:
     std::string find_absentee(
        const std::vector<std::string>& mid,
        const std::vector<std::string>& final)
     {
         find_duplicates(mid, final);
         return get_output_ss().str();
     }
 
     virtual ~AbstractAbsenteeList() = default;
};

#endif /* AbstractAbsenteeList_h */
