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
        std::cout << "Classes loaded from file." << std::endl;
    } else {
        std::cout << "Unable to open file for loading classes." << std::endl;
    }
}

void Schedule::saveAllClasses() {
    std::ofstream file("all_classes.txt", std::ios::trunc);
    if (file.is_open()) {
        for (const Event& e : classes) {
            char buf[80];
            strftime(buf, sizeof(buf), "%m/%d/%Y %H:%M", &e.datetime);
            file << e.name << " " << buf << std::endl;
        }
        file.close();
        std::cout << "All classes saved to file." << std::endl;
    } else {
        std::cout << "Unable to open file for saving all classes." << std::endl;
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
                std::cout << "Final save: Writing to file: " << e.name << " " << buf << std::endl;
            }
            file.flush();
            std::cout << "Final classes saved to file. Total classes written: " << classes.size() << std::endl;
        }
        file.close();
    } else {
        std::cout << "Unable to open file for final saving classes." << std::endl;
    }
}


Schedule::Schedule() {
    static int count = 0;
    std::cout << "Constructing Schedule #" << ++count << ". Loading classes..." << std::endl;
    loadClass();
    std::cout << "Classes loaded from file at startup. Total classes: " << classes.size() << std::endl;
}

Schedule::~Schedule() {
    static int count = 0;
    std::cout << "Destructing Schedule #" << ++count << ". Saving classes..." << std::endl;
    saveClass();
}
