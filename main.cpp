
#include <fstream>
#include <sstream>
#include <random>
#include<vector>
using std::ofstream;
#include "Schedule.h"
#include "Course.h"

std::random_device rd;
std::mt19937 rng(rd());
int random_in_range(int min, int max) {
    std::uniform_int_distribution<int> uni(min, max);
    return uni(rng);
}

void generateSchedules(std::vector<Course> allCourses, int number_of_courses){
    int k=0;
    std::vector<Schedule> validSchedules;
    for (int i=0;i<100000;i++) 
    {
        std::vector<SlotTime> slotTimes;
        for (int j=0;j<number_of_courses;j++)
            {
                int random_integer=random_in_range(0,1);
                slotTimes.push_back(allCourses[j].getSlotTime(random_integer));

            }
        Schedule Sc=Schedule(slotTimes);
            
         if (Sc.scheduleGood())
            {
                bool uniqueS=true;
            for(std::vector<Schedule>::size_type ii = 0; ii != validSchedules.size(); ii++)
             {
                 if (Sc==validSchedules[ii])
                 {
                     uniqueS=false;
                     break;
                 }
            }
            if (uniqueS)validSchedules.push_back(Sc);
        
            }
    }
for(std::vector<Schedule>::size_type ii = 0; ii != validSchedules.size(); ii++) {
    validSchedules[ii].printSchedule();
}


    
}
int main()
{
std::ifstream inputFile;

inputFile.open("input.txt");
string lineRead;
int number_of_courses;
getline(inputFile, lineRead);
std::istringstream iss(lineRead);
iss>>number_of_courses;
std::vector<Course> allCourses;
for (int i=0;i<number_of_courses;++i)
{
getline(inputFile,lineRead);
string courseName;
iss.clear();iss.str(lineRead);
iss>>courseName;
getline(inputFile,lineRead);
iss.clear();iss.str(lineRead);

int number_of_slots;
iss>>number_of_slots;

std:vector<SlotTime> slotTimes;
    for (int j=0;j<number_of_slots;++j)
    {
        getline(inputFile,lineRead);
        iss.clear();iss.str(lineRead);


        string day;
        string startTime;
        string endTime;
        iss>>day>>startTime>>endTime;

        slotTimes.push_back(SlotTime(courseName,day,startTime,endTime));

    }
    Course t(courseName,slotTimes);
    allCourses.push_back(t);
}
    generateSchedules(allCourses, number_of_courses);

    return EXIT_SUCCESS;

}