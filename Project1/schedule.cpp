#include "schedule.h"

void Schedule::loadSchedule(string filename)
{
    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        cout << "Error: File not found" << endl;
        return;
    }
    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }
    file.close();
}

void Schedule::editSchedule(string filename)
{
    
    ofstream file;
    ifstream file2;

    file.open(filename, ios::app);
    if (!file.is_open())
    {
        cout << "Error: File not found" << endl;
        return;
    }
    string line;
    cout << "Enter the hour to edit: ";
    cin.ignore();
    getline(cin, line);
    
    

    file << line << endl;
    file.close();
}
