#include "schedule.h"

void Schedule::addClass() {
    std::cout << "Enter the name of the class: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Do you want to use the current time? (Y/N): ";
    char choice;
    std::cin >> choice;
    std::cin.ignore();

    std::tm datetime = {};
    if (tolower(choice) == 'n') {
        std::cout << "Enter the date and time of the class (MM/DD/YYYY HH:MM): ";
        std::string datetimeString;
        std::getline(std::cin, datetimeString);

        std::istringstream datetimeStream(datetimeString);
        strptime(datetimeString.c_str(), "%m/%d/%Y %H:%M", &datetime);
    } else {
        std::time_t now = std::time(nullptr);
        localtime_r(&now, &datetime);
    }

    classes.push_back(Event(name, datetime));
    std::cout << "Class added successfully. Total classes: " << classes.size() << std::endl;
}

void Schedule::removeClass() {
    std::cout << "Enter the name of the class to remove: ";
    std::string name;
    std::getline(std::cin, name);

    std::vector<Event>::iterator it = classes.end();
    for (std::vector<Event>::iterator i = classes.begin(); i != classes.end(); ++i) {
        if (i->name == name) {
            it = i;
            break;
        }
    }

    if (it != classes.end()) {
        classes.erase(it);
        std::cout << "Class removed successfully." << std::endl;
    } else {
        std::cout << "Class not found." << std::endl;
    }
}

void Schedule::editClass() {
    std::cout << "Enter the name of the class to edit: ";
    std::string name;
    std::getline(std::cin, name);

    for (std::vector<Event>::iterator it = classes.begin(); it != classes.end(); ++it) {
        if (it->name == name) {
            std::cout << "Enter the new date and time of the class (MM/DD/YYYY HH:MM): ";
            std::string datetimeString;
            std::getline(std::cin, datetimeString);

            std::istringstream datetimeStream(datetimeString);
            std::tm datetime = {};
            strptime(datetimeString.c_str(), "%m/%d/%Y %H:%M", &datetime);
            it->datetime = datetime;

            std::cout << "Class edited successfully." << std::endl;
            return;
        }
    }
    std::cout << "Class not found." << std::endl;
}


void Schedule::loadClass() {
    std::ifstream file("classes.txt");
    if (file.is_open()) {
        classes.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            Event e;
            lineStream >> e.name;
            std::string datetimePart;
            std::getline(lineStream, datetimePart);
            std::istringstream datetimeStream(datetimePart);
            strptime(datetimePart.c_str(), "%m/%d/%Y %H:%M", &e.datetime);
            classes.push_back(e);
        }
        file.close();

    } else {
        std::cout << "Unable to open file for loading classes." << std::endl;
    }
}


void Schedule::saveClass() {
    std::ofstream file("./classes.txt", std::ios::trunc);  // Explicit relative path
    if (file.is_open()) {
        if (classes.empty()) {
            std::cout << "Warning: No classes to save at final save." << std::endl;
        } else {
            for (const Event& e : classes) {
                char buf[80];
                strftime(buf, sizeof(buf), "%m/%d/%Y %H:%M", &e.datetime);
                file << e.name << " " << buf << std::endl;

            }
            file.flush();

        }
        file.close();
    } else {
        std::cout << "Unable to open file for final saving classes." << std::endl;
    }
}


Schedule::Schedule() {
    static int count = 0;

    loadClass();
    loadActivity();
    loadCommitment();
    loadReminder();

}

Schedule::~Schedule() {
        char saveChoice;
        std::cout << "Do you want to save changes to the files? (Y/N): ";
        std::cin >> saveChoice;
        if (tolower(saveChoice) == 'y') {
                saveClass();
                saveActivity();
                saveCommitment();
                saveReminder();
        }
    }



void Schedule::addActivity() {
    std::cout << "Enter the name of the activity: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Do you want to use the current time? (Y/N): ";
    char choice;
    std::cin >> choice;
    std::cin.ignore();

    std::tm datetime = {};
    if (tolower(choice) == 'n') {
        std::cout << "Enter the date and time of the activity (MM/DD/YYYY HH:MM): ";
        std::string datetimeString;
        std::getline(std::cin, datetimeString);

        std::istringstream datetimeStream(datetimeString);
        strptime(datetimeString.c_str(), "%m/%d/%Y %H:%M", &datetime);
    } else {
        std::time_t now = std::time(nullptr);
        localtime_r(&now, &datetime);
    }

    activities.push_back(Event(name, datetime));
    std::cout << "Activity added successfully. Total activities: " << activities.size() << std::endl;
}

void Schedule::removeActivity() {
    std::cout << "Enter the name of the activity to remove: ";
    std::string name;
    std::getline(std::cin, name);

    std::vector<Event>::iterator it = activities.end();
    for (std::vector<Event>::iterator i = activities.begin(); i != activities.end(); ++i) {
        if (i->name == name) {
            it = i;
            break;
        }
    }

    if (it != activities.end()) {
        activities.erase(it);
        std::cout << "Activity removed successfully." << std::endl;
    } else {
        std::cout << "Activity not found." << std::endl;
    }
}

void Schedule::editActivity() {
    std::cout << "Enter the name of the activity to edit: ";
    std::string name;
    std::getline(std::cin, name);

    for (std::vector<Event>::iterator it = activities.begin(); it != activities.end(); ++it) {
        if (it->name == name) {
            std::cout << "Enter the new date and time of the activity (MM/DD/YYYY HH:MM): ";
            std::string datetimeString;
            std::getline(std::cin, datetimeString);

            std::istringstream datetimeStream(datetimeString);
            std::tm datetime = {};
            strptime(datetimeString.c_str(), "%m/%d/%Y %H:%M", &datetime);
            it->datetime = datetime;

            std::cout << "Activity edited successfully." << std::endl;
            return;
        }
    }
    std::cout << "Activity not found." << std::endl;
}

void Schedule::loadActivity() {
    std::ifstream file("activities.txt");
    if (file.is_open()) {
        activities.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            Event e;
            lineStream >> e.name;
            std::string datetimePart;
            std::getline(lineStream, datetimePart);
            std::istringstream datetimeStream(datetimePart);
            strptime(datetimePart.c_str(), "%m/%d/%Y %H:%M", &e.datetime);
            activities.push_back(e);
        }
        file.close();

    } else {
        std::cout << "Unable to open file for loading activities." << std::endl;
    }
}

void Schedule::saveActivity() {
    std::ofstream file("activities.txt", std::ios::trunc);
    if (file.is_open()) {
        for (const Event& e : activities) {
            char buf[80];
            strftime(buf, sizeof(buf), "%m/%d/%Y %H:%M", &e.datetime);
            file << e.name << " " << buf << std::endl;
        }
        file.close();

    } else {
        std::cout << "Unable to open file for saving activities." << std::endl;
    }
}


void Schedule::addCommitment() {
    std::cout << "Enter the name of the commitment: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Do you want to use the current time? (Y/N): ";
    char choice;
    std::cin >> choice;
    std::cin.ignore();

    std::tm datetime = {};
    if (tolower(choice) == 'n') {
        std::cout << "Enter the date and time of the commitment (MM/DD/YYYY HH:MM): ";
        std::string datetimeString;
        std::getline(std::cin, datetimeString);

        std::istringstream datetimeStream(datetimeString);
        strptime(datetimeString.c_str(), "%m/%d/%Y %H:%M", &datetime);
    } else {
        std::time_t now = std::time(nullptr);
        localtime_r(&now, &datetime);
    }

    commitments.push_back(Event(name, datetime));
    std::cout << "Commitment added successfully. Total commitments: " << commitments.size() << std::endl;
}

void Schedule::removeCommitment() {
    std::cout << "Enter the name of the commitment to remove: ";
    std::string name;
    std::getline(std::cin, name);

    std::vector<Event>::iterator it = commitments.end();
    for (std::vector<Event>::iterator i = commitments.begin(); i != commitments.end(); ++i) {
        if (i->name == name) {
            it = i;
            break;
        }
    }

    if (it != commitments.end()) {
        commitments.erase(it);
        std::cout << "Commitment removed successfully." << std::endl;
    } else {
        std::cout << "Commitment not found." << std::endl;
    }
}

void Schedule::editCommitment() {
    std::cout << "Enter the name of the commitment to edit: ";
    std::string name;
    std::getline(std::cin, name);

    for (std::vector<Event>::iterator it = commitments.begin(); it != commitments.end(); ++it) {
        if (it->name == name) {
            std::cout << "Enter the new date and time of the commitment (MM/DD/YYYY HH:MM): ";
            std::string datetimeString;
            std::getline(std::cin, datetimeString);

            std::istringstream datetimeStream(datetimeString);
            std::tm datetime = {};
            strptime(datetimeString.c_str(), "%m/%d/%Y %H:%M", &datetime);
            it->datetime = datetime;

            std::cout << "Commitment edited successfully." << std::endl;
            return;
        }
    }
    std::cout << "Commitment not found." << std::endl;
}

void Schedule::loadCommitment() {
    std::ifstream file("commitments.txt");
    if (file.is_open()) {
        commitments.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            Event e;
            lineStream >> e.name;
            std::string datetimePart;
            std::getline(lineStream, datetimePart);
            std::istringstream datetimeStream(datetimePart);
            strptime(datetimePart.c_str(), "%m/%d/%Y %H:%M", &e.datetime);
            commitments.push_back(e);
        }
        file.close();

    } else {
        std::cout << "Unable to open file for loading commitments." << std::endl;
    }
}

void Schedule::saveCommitment() {
    std::ofstream file("commitments.txt", std::ios::trunc);
    if (file.is_open()) {
        for (const Event& e : commitments) {
            char buf[80];
            strftime(buf, sizeof(buf), "%m/%d/%Y %H:%M", &e.datetime);
            file << e.name << " " << buf << std::endl;
        }
        file.close();

    } else {
        std::cout << "Unable to open file for saving commitments." << std::endl;
    }
}

void Schedule::addReminder() {
    std::cout << "Enter the name of the reminder: ";
    std::string name;
    std::getline(std::cin, name);

    std::cout << "Do you want to use the current time? (Y/N): ";
    char choice;
    std::cin >> choice;
    std::cin.ignore();

    std::tm datetime = {};
    if (tolower(choice) == 'n') {
        std::cout << "Enter the date and time of the reminder (MM/DD/YYYY HH:MM): ";
        std::string datetimeString;
        std::getline(std::cin, datetimeString);

        std::istringstream datetimeStream(datetimeString);
        strptime(datetimeString.c_str(), "%m/%d/%Y %H:%M", &datetime);
    } else {
        std::time_t now = std::time(nullptr);
        localtime_r(&now, &datetime);
    }

    reminders.push_back(Event(name, datetime));
    std::cout << "Reminder added successfully. Total reminders: " << reminders.size() << std::endl;
}

void Schedule::removeReminder() {
    std::cout << "Enter the name of the reminder to remove: ";
    std::string name;
    std::getline(std::cin, name);

    std::vector<Event>::iterator it = reminders.end();
    for (std::vector<Event>::iterator i = reminders.begin(); i != reminders.end(); ++i) {
        if (i->name == name) {
            it = i;
            break;
        }
    }

    if (it != reminders.end()) {
        reminders.erase(it);
        std::cout << "Reminder removed successfully." << std::endl;
    } else {
        std::cout << "Reminder not found." << std::endl;
    }
}

void Schedule::editReminder() {
    std::cout << "Enter the name of the reminder to edit: ";
    std::string name;
    std::getline(std::cin, name);

    for (std::vector<Event>::iterator it = reminders.begin(); it != reminders.end(); ++it) {
        if (it->name == name) {
            std::cout << "Enter the new date and time of the reminder (MM/DD/YYYY HH:MM): ";
            std::string datetimeString;
            std::getline(std::cin, datetimeString);

            std::istringstream datetimeStream(datetimeString);
            std::tm datetime = {};
            strptime(datetimeString.c_str(), "%m/%d/%Y %H:%M", &datetime);
            it->datetime = datetime;

            std::cout << "Reminder edited successfully." << std::endl;
            return;
        }
    }
    std::cout << "Reminder not found." << std::endl;
}

void Schedule::loadReminder() {
    std::ifstream file("reminders.txt");
    if (file.is_open()) {
        reminders.clear();
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            Event e;
            lineStream >> e.name;
            std::string datetimePart;
            std::getline(lineStream, datetimePart);
            std::istringstream datetimeStream(datetimePart);
            strptime(datetimePart.c_str(), "%m/%d/%Y %H:%M", &e.datetime);
            reminders.push_back(e);
        }
        file.close();

    } else {
        std::cout << "Unable to open file for loading reminders." << std::endl;
    }
}

void Schedule::saveReminder() {
    std::ofstream file("reminders.txt", std::ios::trunc);
    if (file.is_open()) {
        for (const Event& e : reminders) {
            char buf[80];
            strftime(buf, sizeof(buf), "%m/%d/%Y %H:%M", &e.datetime);
            file << e.name << " " << buf << std::endl;
        }
        file.close();

    } else {
        std::cout << "Unable to open file for saving reminders." << std::endl;
    }
}

void Schedule::displayClasses() const {
    std::ifstream file("classes.txt");
    std::cout << "\nClasses:\n";
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::string name, datetimePart;
            lineStream >> name;
            std::getline(lineStream, datetimePart);
            std::cout << "Class: " << name << ", Scheduled at: " << datetimePart << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading classes." << std::endl;
    }
}

void Schedule::displayActivities() const {
    std::ifstream file("activities.txt");
    std::cout << "\nActivities:\n";
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::string name, datetimePart;
            lineStream >> name;
            std::getline(lineStream, datetimePart);
            std::cout << "Activity: " << name << ", Scheduled at: " << datetimePart << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading activities." << std::endl;
    }
}

void Schedule::displayCommitments() const {
    std::ifstream file("commitments.txt");
    std::cout << "\nCommitments:\n";
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::string name, datetimePart;
            lineStream >> name;
            std::getline(lineStream, datetimePart);
            std::cout << "Commitment: " << name << ", Scheduled at: " << datetimePart << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading commitments." << std::endl;
    }
}

void Schedule::displayReminders() const {
    std::ifstream file("reminders.txt");
    std::cout << "\nReminders:\n";
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream lineStream(line);
            std::string name, datetimePart;
            lineStream >> name;
            std::getline(lineStream, datetimePart);
            std::cout << "Reminder: " << name << ", Scheduled at: " << datetimePart << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file for reading reminders." << std::endl;
    }
}

void Schedule::viewFullSchedule() const {
    std::cout << "Full Schedule Overview:\n";
    displayClasses();
    displayActivities();
    displayCommitments();
    displayReminders();
}

void Schedule::resetFiles() const {
    std::vector<std::string> filenames;
    filenames.push_back("classes.txt");
    filenames.push_back("activities.txt");
    filenames.push_back("commitments.txt");
    filenames.push_back("reminders.txt");

    for (const auto& filename : filenames) {
        std::ifstream fileCheck(filename);
        if (fileCheck.good()) {  // Check if file exists
            fileCheck.close();
            // File exists, delete it
            if (std::remove(filename.c_str()) == 0) {
                std::cout << "Deleted existing file: " << filename << std::endl;
            } else {
                std::cerr << "Failed to delete file: " << filename << std::endl;
                continue;  // Skip to next file if deletion fails
            }
        }

        // Create new file
        std::ofstream fileCreate(filename);
        if (fileCreate.is_open()) {
            std::cout << "Created new file: " << filename << std::endl;
            fileCreate.close();
        } else {
            std::cerr << "Failed to create file: " << filename << std::endl;
        }
    }
}

