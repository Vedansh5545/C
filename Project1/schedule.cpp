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
        cout << startHour << " : " << endHour << " - " << task << endl;
    }
    file.close();
}

/**
 * @brief Edits the schedule by replacing the task associated with a specific starting hour.
 * 
 * This function takes a filename as input and opens the file for reading. It prompts the user to enter the starting hour to edit and the new task. 
 * It then searches for the starting hour in the file and replaces the task with the new task. The modified schedule is written to a temporary file.
 * Finally, the original file is deleted and the temporary file is renamed to the original filename.
 * 
 * @param filename The name of the file containing the schedule.
 */
void Schedule::editSchedule(string filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: File not found" << endl;
        return;
    }

    string tempFilename = "temp.txt";
    ofstream tempFile(tempFilename);
    int startHour;
    string newTask;
    cout << "Enter the starting hour to edit: ";
    cin >> startHour;

    cout << "Enter the new task: ";
    cin.ignore(); // Ignore the newline character left in the input stream
    getline(cin, newTask);

    bool found = false;
    string line;
    while (getline(file, line))
    {
        stringstream s(line);
        string currentStartHour, endHour, task;
        getline(s, currentStartHour, ',');
        getline(s, endHour, ',');
        getline(s, task, ',');
        try
        {
            int currentStartHourInt = std::stoi(currentStartHour);
            if (currentStartHourInt == startHour)
            {
                tempFile << currentStartHour << "," << endHour << "," << newTask << endl;
                found = true;
            }
            else
            {
                tempFile << line << endl;
            }
        }
        catch (const std::invalid_argument& e)
        {
            // Handle the case when the conversion fails
            cout << "Invalid starting hour: " << currentStartHour << endl;
        }
    }

    file.close();
    tempFile.close();

    remove(filename.c_str());
    rename(tempFilename.c_str(), filename.c_str());

    if (found)
    {
        cout << "Data edited successfully" << endl;
    }
    else
    {
        cout << "Starting hour not found" << endl;
    }
}


void Schedule::inputSchedule(string filename)
{
    ofstream file(filename, std::ios_base::app); // Open file in append mode
    if (!file.is_open())
    {
        cout << "Error: File not found" << endl;
        return;
    }

    int startHour, endHour;
    string task;
    cout << "Enter start hour: ";
    cin >> startHour;
    cout << "Enter end hour: ";
    cin >> endHour;
    cout << "Enter task: ";
    cin.ignore(); // Ignore the newline character left in the input stream
    getline(cin, task);

    file << startHour << "," << endHour << "," << task << endl;
    file.close();

    cout << "Schedule added successfully" << endl;
}


void Schedule::displaySchedule(string filename)
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
        cout << startHour << " : " << endHour << " - " << task << endl;
    }
    file.close();
}

void Schedule::clearSchedule(string filename)
{
    ofstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: File not found" << endl;
        return;
    }
    file.clear();
    file.close();
    cout << "Schedule cleared successfully" << endl;
}