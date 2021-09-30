#pragma once
#include <iostream>
using namespace std;

class SlotTime
{
private:
    string slotName;
    string day;
    int startHour;
    int startMinute;
    int endHour;
    int endMinute;

public:
    SlotTime();
    SlotTime(string, string, int,int,int,int);
    SlotTime(string, string, string, string);
    string getSlotName() ;
    string getDay() ;
    int getStartHour() const;
    int getStartMinute() const;
    int getEndHour() const;
    int getEndMinute() const;
    void setSlotName(string);
    void setDay(string);
    void setStartHour(int);
    void setStartMinute(int);
    void setEndHour(int);
    void setEndMinute(int);
    SlotTime (const SlotTime &old_obj); 

SlotTime& operator = (const SlotTime &t);
bool operator== (const SlotTime &rhs)const ;


    void printSlotTime();

    ~SlotTime();
    
};

SlotTime::SlotTime()
{
slotName="-1";
day="-1";
startHour=-1;
startMinute=-1;
endHour=-1;
endMinute=-1;

}
SlotTime::SlotTime(const SlotTime &old_obj)
{
    slotName=old_obj.slotName;
    day=old_obj.day;
    startHour=old_obj.startHour;
    startMinute=old_obj.startMinute;
    endHour=old_obj.endHour;
    endMinute=old_obj.endMinute;
}
SlotTime& SlotTime::operator = (const SlotTime &t){
    if (this == &t)
        return *this;
    slotName=t.slotName;
    day=t.day;
    startHour=t.startHour;
    startMinute=t.startMinute;
    endHour=t.endHour;
    endMinute=t.endMinute;
    return *this;
}

bool SlotTime::operator== (const SlotTime &rhs)const {
    if (slotName==rhs.slotName && day==rhs.day && startHour==rhs.startHour)
    {
        return true;
    }
    
    return false;
};


SlotTime::SlotTime(string name,string day, int startHour, int startMinute,int endHour, int endMinute):
slotName(name), day(day), startHour(startHour), startMinute(startMinute), endHour(endHour), endMinute(endMinute)
{
}
SlotTime::SlotTime(string name, string day, string startTime, string endTime):
slotName(name),day(day)
    {
        startHour=stoi(startTime.substr(0,2));
        startMinute=stoi(startTime.substr(3,2));

        endHour=stoi(endTime.substr(0,2));
        endMinute=stoi(endTime.substr(3,2));


    }

string SlotTime::getSlotName() {
    return slotName;
}
string SlotTime::getDay() {
    return day;
}
int SlotTime::getStartHour() const{
    return startHour;
}
int SlotTime::getStartMinute() const{
    return startMinute;
}
int SlotTime::getEndHour() const{
    return endHour;
}
int SlotTime::getEndMinute() const{
    return endMinute;
}

void SlotTime::setSlotName(string name)
{
    slotName=name;
}
void SlotTime::setDay(string day)
{
    this->day=day;
}
void SlotTime::setStartHour(int hr)
{
    startHour=hr;
}
void SlotTime::setStartMinute(int min)
{
    startMinute=min;
}
void SlotTime::setEndHour(int hr)
{
    endHour=hr;
}
void SlotTime::setEndMinute(int min)
{
    endMinute=min;
}
void SlotTime::printSlotTime()
{
    string startM=(startMinute==0)?"00" : to_string(startMinute);
    string endM=(endMinute==0)?"00" : to_string(endMinute);

    cout<<endl<<slotName<<'\n'<<day<<'\n'<<startHour<<':'<<startM<<" to "<<endHour<<':'<<endM<<endl;
}


SlotTime::~SlotTime()
{
}
