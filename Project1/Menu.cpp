#include "Menu.h"
#include "schedule.h"

void displayMenu() {
    Schedule schedule;
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
    string name;
    string date;
    string time;
    string datetime;
    std::stringstream ss;

    switch (choice) {
        case 1: {
            cout << "Schedule Management" << endl;
            cout << endl;
            cout << "Choose an option:" << endl;
            cout << "1. Add Class" << endl;
            cout << "2. Add Activity" << endl;
            cout << "3. Add Commitment" << endl;
            cout << "4. Add Reminder" << endl;
            cout << "5. Display Schedule" << endl;
            cout << "6. Display Reminders" << endl;
            cout << "7. Display Upcoming" << endl;
            cout << "8. Display Daily" << endl;
            cout << "9. Display Weekly" << endl;
            cout << "10. Display Monthly" << endl;
            cout << "11. Display Yearly" << endl;
            cout << "12. Display All" << endl;
            cout << "13. Remove Class" << endl;
            cout << "14. Remove Activity" << endl;
            cout << "15. Remove Commitment" << endl;
            cout << "16. Remove Reminder" << endl;
            cout << "17. Edit Class" << endl;
            cout << "18. Edit Activity" << endl;
            cout << "19. Edit Commitment" << endl;
            cout << "20. Edit Reminder" << endl;
            cout << "21. Save Schedule" << endl;
            cout << "22. Load Schedule" << endl;
            cout << "0. Exit" << endl;

            cout << "Enter your choice: ";

            int subChoice;
            cin >> subChoice;

            std::tm classDateTime = {};
            std::tm activityDateTime = {};

            switch (subChoice) {
            case 1: {
                cout << "Enter class name: ";
                cin.ignore();  // Ignore the newline character from previous input
                getline(cin, name);  // Using getline to allow space in names

                int choice;
                cout << "Choose:\n1. Enter specific date and time\n2. Use current date and time\nEnter choice: ";
                cin >> choice;
                cin.ignore();  // To ignore the newline character after cin

                std::string date, time, datetime;
                std::tm classDateTime = {};  // Zero-initialize tm structure

                if (choice == 1) {
                    cout << "Enter activity date (YYYY-MM-DD): ";
                    getline(cin, date);

                    cout << "Enter activity time (HH:MM:SS): ";
                    getline(cin, time);

                    datetime = date + " " + time;
                } else if (choice == 2) {
                    // Get current time and format it
                    auto t = std::time(nullptr);
                    auto localTime = *std::localtime(&t);
                    std::ostringstream ss;
                    ss << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S");
                    datetime = ss.str();
                } else {
                    cout << "Invalid choice." << endl;
                    break;  // Exit switch case if invalid option
                }

                std::istringstream ss(datetime);
                ss >> std::get_time(&classDateTime, "%Y-%m-%d %H:%M:%S");
                if (ss.fail()) {
                    cout << "Failed to parse date and time." << endl;
                    break;  // Exit switch case on failure to parse
                }

                schedule.addClass(name, classDateTime);
                break;
            }
                case 2: {
                    // addActivity(name, datetime);

                    cout << "Enter activity name: ";
                    cin >> name;

                    cout << "Enter activity date (YYYY-MM-DD): ";
                    cin >> date;

                    cout << "Enter activity time (HH:MM:SS): ";
                    cin >> time;

                    datetime = date + " " + time;

                    ss.str(datetime);
                    ss >> std::get_time(&activityDateTime, "%Y-%m-%d %H:%M:%S");

                    schedule.addActivity(name, activityDateTime);
                    break;
                }
                case 3:
                    // addCommitment(name, datetime);
                    break;
                case 4:
                    // addReminder(name, datetime);
                    break;
                case 5:
                    // displaySchedule();
                    break;
                case 6:
                    // displayReminders();
                    break;
                case 7:
                    // displayUpcoming();
                    break;
                case 8:
                    // displayDaily();
                    break;
                case 9:
                    // displayWeekly();
                    break;
                case 10:
                    // displayMonthly();
                    break;
                case 11:
                    // displayYearly();
                    break;
                case 12:
                    // displayAll();
                    break;
                case 13:
                    // removeClass(name);
                    break;
                case 14:
                    // removeActivity(name);
                    break;
                case 15:
                    // removeCommitment(name);
                    break;
                case 16:
                    // removeReminder(name);
                    break;
                case 17:
                    // editClass(name, datetime);
                    break;
                case 18:
                    // editActivity(name, datetime);
                    break;
                case 19:
                    // editCommitment(name, datetime);
                    break;
                case 20:
                    // editReminder(name, datetime);
                    break;
                case 21:
                    // saveSchedule();
                    break;
                case 22:
                    // loadSchedule();
                    break;
                case 0:
                    cout << "Exiting..." << endl;
                    break;
                default:
                    cout << "Invalid choice" << endl;
                    break;
            }
            break;
        }
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
            break;
        default:
            cout << "Invalid choice" << endl;
            break;
    }
}
