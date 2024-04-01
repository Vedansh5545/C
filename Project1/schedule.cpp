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
        stringstream s(line);
        string startHour, endHour, task;
        getline(s, startHour, ',');
        getline(s, endHour, ',');
        getline(s, task, ',');
        cout << "Start Hour: " << startHour << ", End Hour: " << endHour << ", Task: " << task << endl;
    }
    file.close();
}

// Function to convert a string to lowercase
std::string toLower(std::string str)
{

    for (char& c : str)
    {
        if (c >= 'A' && c <= 'Z')
        {
            c = c + 32; // Convert uppercase to lowercase
        }
    }
    return str;
}


void Schedule::editSchedule(string filename)
{
    ifstream file;
    ofstream tempFile;
    file.open(filename);
    tempFile.open("temp.txt");

    if (!file.is_open())
    {
        cout << "Error: File not found" << endl;
        return;
    }

    string line;
    cout << "Enter the starting hour to edit: ";
    cin.ignore();
    string startHour;
    getline(cin, startHour);

    string newTask;
    cout << "Enter the new task: ";
    getline(cin, newTask);

    bool found = false;
    while (getline(file, line))
    {
        stringstream s(line);
        string currentStartHour, endHour, task;
        getline(s, currentStartHour, ',');
        getline(s, endHour, ',');
        getline(s, task, ',');

        // Convert both hours to the same format for comparison
        string formattedCurrentStartHour = currentStartHour.substr(0, 2) + ":" + currentStartHour.substr(3, 2);
        if (toLower(formattedCurrentStartHour) == toLower(startHour))
        {
            tempFile << currentStartHour << "," << endHour << "," << newTask << endl;
            found = true;
        }
        else
        {
            tempFile << line << endl;
        }
    }

    file.close();
    tempFile.close();

    remove(filename.c_str());
    rename("temp.txt", filename.c_str());

    if (found)
    {
        cout << "Data edited successfully" << endl;
    }
    else
    {
        cout << "Starting hour not found" << endl;
    }
}
