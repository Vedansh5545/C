#include "main.h"
#include "schedule.h"

int main()
{
    string filename = "Schedule.txt";
    Schedule schedule;
    schedule.loadSchedule(filename);
    schedule.editSchedule(filename);

    return 0;
}