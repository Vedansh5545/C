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
    cout << "4. Add Activity" << endl;
    cout << "5. Remove Activity" << endl;
    cout << "6. Edit Activity" << endl;
    cout << "7. Add Commitment" << endl;
    cout << "8. Remove Commitment" << endl;
    cout << "9. Edit Commitment" << endl;
    cout << "10. Add Reminder" << endl;
    cout << "11. Remove Reminder" << endl;
    cout << "12. Edit Reminder" << endl;
    cout << "0. Back" << endl;


    int choice;
    cout << "Enter your choice: ";
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

        case 4:
            // Process Add Activity
            schedule.addActivity();
            break;

        case 5:
            // Process Remove Activity
            schedule.removeActivity();
            break;
        
        case 6:
            // Process Edit Activity
            schedule.editActivity();
            break;
        
        case 7:
            // Process Add Commitment
            schedule.addCommitment();
            break;

        case 8:
            // Process Remove Commitment
            schedule.removeCommitment();
            break;

        case 9:
            // Process Edit Commitment
            schedule.editCommitment();
            break;
        
        case 10:

            // Process Add Reminder
            schedule.addReminder();
            break;

        case 11:
            // Process Remove Reminder
            schedule.removeReminder();
            break;

        case 12:

            // Process Edit Reminder
            schedule.editReminder();
            break;

        
        
        case 0:
            // Return to previous menu
            displayMenu();
            break;
        default:
            cout << "Invalid choice" << endl;
            break;

};

    schedule.saveClass();
}
