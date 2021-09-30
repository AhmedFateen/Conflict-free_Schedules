#pragma once
#include <iostream>
#include "SlotTime.h"
using namespace std;
class Course 
{
private:
 string name;
    std::vector<SlotTime> slotTimes;
public:
Course();
Course(const string, std::vector<SlotTime>);
SlotTime getSlotTime(int index);
Course& operator = (const Course &t);

    ~Course();
};
Course::Course(){
}
Course::Course(const string name, std::vector<SlotTime> times): 
name(name)
{    
    for(std::vector<SlotTime>::size_type i = 0; i != times.size(); i++) {
        slotTimes.push_back(times[i]);

    }
}
SlotTime Course::getSlotTime(int index)
{
    if (index>slotTimes.size()-1)
    {
        return slotTimes[0];
    }
    return slotTimes[index];
}
Course& Course::operator = (const Course &t){
    if (this == &t)
        return *this;
    name=t.name;
    slotTimes.clear();
for(std::vector<SlotTime>::size_type i = 0; i != t.slotTimes.size(); i++) {
        slotTimes.push_back(t.slotTimes[i]);
    }    return *this;
}


Course::~Course()
{
}