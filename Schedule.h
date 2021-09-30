#pragma once
#include <iostream>
#include "SlotTime.h"
using namespace std;
class Schedule
{
private:
std::vector<SlotTime> slotTimes;
public:
    Schedule();
    Schedule(std::vector<SlotTime>);
    void printSchedule();
    bool scheduleGood();
    bool operator== (const Schedule &rhs)const;
    Schedule& operator = (const Schedule &t);
    Schedule(const Schedule& copy);

    ~Schedule();
};

Schedule::Schedule()
{
}
Schedule::Schedule(std::vector<SlotTime> ST)
{

for(std::vector<SlotTime>::size_type i = 0; i != ST.size(); i++) {
        slotTimes.push_back(ST[i]);
    }   
    }

Schedule& Schedule::operator = (  const Schedule &t){
    if (this == &t){
        return *this;
    }
slotTimes.clear();
for(std::vector<SlotTime>::size_type i = 0; i != t.slotTimes.size(); i++) {
        slotTimes.push_back(t.slotTimes[i]);
    }    return *this;
return *this;
}


void Schedule::printSchedule()
{
    std::cout<<endl<<"Schedule start---------------------------Schedule----------------------"<<endl;
for(std::vector<SlotTime>::size_type i = 0; i != slotTimes.size(); i++)    {
        slotTimes[i].printSlotTime();
    }
}
    bool Schedule::operator== (const Schedule &rhs)const {

for(std::vector<SlotTime>::size_type i = 0; i != slotTimes.size(); i++)        {
            if (slotTimes[i]==rhs.slotTimes[i])
            {
            }
            else
            {
                return false;
            }
            
        }
        return true;
    }

bool Schedule::scheduleGood(){
for(std::vector<SlotTime>::size_type i = 0; i != slotTimes.size(); i++)    {
    for(std::vector<SlotTime>::size_type j = 0; j != slotTimes.size(); j++)    {
        if (slotTimes[i].getStartHour()==-1 || slotTimes[j].getStartHour()==-1){
            return false;
        }
        else if (i==j)
        {
            continue;
        }

        else if (slotTimes[i].getDay()!= slotTimes[j].getDay())
        {
            continue;
        }
        else if((slotTimes[i].getStartHour() == slotTimes[j].getStartHour()) ){
            return false;
            }

        else if((slotTimes[i].getStartHour() > slotTimes[j].getEndHour()) || (slotTimes[j].getStartHour() > slotTimes[i].getEndHour())){
            continue;
            }
        else if (slotTimes[i].getStartHour() == slotTimes[j].getEndHour() && slotTimes[i].getStartMinute() >= slotTimes[j].getEndMinute())
            {
                    continue;
            }
         else if (slotTimes[i].getStartHour() == slotTimes[j].getEndHour())
            {

                return false;
            }
        else if (slotTimes[j].getStartHour() == slotTimes[i].getEndHour() && slotTimes[j].getStartMinute() >= slotTimes[i].getEndMinute())
            {
                continue;
            }
        else 

            {

                return false;
            }

        
    }
    }
 
    return true;

}
Schedule::Schedule(const Schedule& t){
for(std::vector<SlotTime>::size_type i = 0; i != t.slotTimes.size(); i++) {
        slotTimes.push_back(t.slotTimes[i]);
    } 
}

Schedule::~Schedule()
{
}
