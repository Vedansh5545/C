#include "Menu.h"
#include "schedule.h"

void Menu::displayMenu() {

    Menu menu;
    cout << "Welcome to the Student Assistant!" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Schedule Management" << endl;
    cout << "2. Task Tracking" << endl;
    cout << "3. Study Assistance" << endl;
    cout << "4. Goal Setting" << endl;
    cout << "5. Resource Organization" << endl;
    cout << "6. Customization" << endl;
    cout << "7. Integration" << endl;
    cout << "8. Feedback and Improvement" << endl;
    cout << "9. Community and Support" << endl;
    cout << "0. Exit" << endl;

    cout << "Enter your choice: ";

    int choice;
    cin >> choice;
    cin.ignore();  // Ignore the newline character from previous input

    // Initialize date/time variables outside the switch-case
    std::tm classDateTime = {};
    std::tm activityDateTime = {};

    switch (choice) {
        case 1:
            // Process Schedule Management
            cout << "Schedule Management" << endl;
            // Additional code for Schedule Management...
            displayScheduleMenu();
            break;
        case 2:
            cout << "Task Tracking" << endl;
            break;
        case 3:
            cout << "Study Assistance" << endl;
            break;
        case 4:
            cout << "Goal Setting" << endl;
            break;
        case 5:
            cout << "Resource Organization" << endl;
            break;
        case 6:
            cout << "Customization" << endl;
            break;
        case 7:
            cout << "Integration" << endl;
            break;
        case 8:
            cout << "Feedback and Improvement" << endl;
            break;
        case 9:
            cout << "Community and Support" << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            return; // Exit function directly
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}

void Menu::displayScheduleMenu(){
    Schedule schedule;
    cout << "Schedule Management" << endl;
    cout << endl;
    cout << "Choose an option:" << endl;
    cout << "1. Add Class" << endl;
    cout << "2. Remove Class" << endl;
    cout <<"3. Edit Class" << endl;

    int choice;
    cin >> choice;
    cin.ignore();  // Ignore the newline character from previous input

    switch (choice) {
        case 1:
            // Process Add Class
            schedule.addClass();
            break;
        case 2:
            // Process Remove Class
            schedule.removeClass();
            break;
        case 3:
            // Process Edit Class
            schedule.editClass();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;

};

    schedule.saveClass();
}
