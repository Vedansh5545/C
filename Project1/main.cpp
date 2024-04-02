#include "main.h"
#include "schedule.h"

void displayMenu()
{
    cout << "1. Load Default Schedule" << endl;
    cout << "2. Edit Schedule" << endl;
    cout << "3. Input New Schedule" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}
int main()
{
    string filename = "Schedule.txt";
    Schedule schedule;
    int choice;
    schedule.displaySchedule(filename);
    schedule.clearSchedule(filename);

    return 0;
}