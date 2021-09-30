# Conflict-free Schedules

This program takes a list of courses and their time slots and creates schedules out of them while eliminating schedule conflicts.
Don't be too harsh, it's only 2 hours' work.

Find below an annotated input.txt file.

6                     <- number of courses (The program assumes each course has one interval, so plan accordingly)\
CIE301L               <- Course name\
2                     <- number of alternative time slots to choose from\
Sunday 10:30 12:20.   <- (alternative 1) day, start time, end time (24 hour format)\
Sunday 13:10 15:00.   <- (alternative 2)\
CIE301T               <- second course name ...\
2\
Monday 10:30 12:20\
Monday 14:10 16:00\
CIE302L\
1\
Monday 10:30 12:20\
CIE302T\
2\
Thursday 14:10 16:00\
Thursday 10:30 12:20\
CIE328L\
2\
Sunday 12:20 14:00\
Sunday 10:30 12:20\
CIE328T\
1\
Monday 12:20 14:00
