#include "schedule.h"

Schedule::Schedule() {
    loadSchedule();
}

Schedule::~Schedule() {
    saveSchedule();
}

void Schedule::addClass(const std::string& name, const std::tm& datetime) {
    Event newClass;
    newClass.name = name;
    newClass.datetime = datetime;
    classes.push_back(newClass);
}

void Schedule::addActivity(const std::string& name, const std::tm& datetime) {
    Event newActivity;
    newActivity.name = name;
    newActivity.datetime = datetime;
    activities.push_back(newActivity);
}

void Schedule::addCommitment(const std::string& name, const std::tm& datetime) {
    Event newCommitment;
    newCommitment.name = name;
    newCommitment.datetime = datetime;
    commitments.push_back(newCommitment);
}

void Schedule::addReminder(const std::string& name, const std::tm& datetime) {
    Event newReminder;
    newReminder.name = name;
    newReminder.datetime = datetime;
    reminders.push_back(newReminder);
}

void Schedule::displaySchedule() {
    displayReminders();
    displayUpcoming();
}

void Schedule::displayReminders() {
    std::cout << "Reminders:" << std::endl;
    for (Event reminder : reminders) {
        std::cout << reminder.name << " - " << std::put_time(&reminder.datetime, "%c") << std::endl;
    }
    std::cout << std::endl;
}

void Schedule::displayUpcoming() {
    std::cout << "Upcoming:" << std::endl;
    for (Event upcoming : classes) {
        std::cout << upcoming.name << " - " << std::put_time(&upcoming.datetime, "%c") << std::endl;
    }
    for (Event upcoming : activities) {
        std::cout << upcoming.name << " - " << std::put_time(&upcoming.datetime, "%c") << std::endl;
    }
    for (Event upcoming : commitments) {
        std::cout << upcoming.name << " - " << std::put_time(&upcoming.datetime, "%c") << std::endl;
    }
    std::cout << std::endl;
}

void Schedule::displayDaily() {
    std::cout << "Daily:" << std::endl;
    std::time_t now = std::time(0);
    std::tm* today = std::localtime(&now);
    for (Event daily : classes) {
        if (daily.datetime.tm_year == today->tm_year && daily.datetime.tm_mon == today->tm_mon && daily.datetime.tm_mday == today->tm_mday) {
            std::cout << daily.name << " - " << std::put_time(&daily.datetime, "%c") << std::endl;
        }
    }
    for (Event daily : activities) {
        if (daily.datetime.tm_year == today->tm_year && daily.datetime.tm_mon == today->tm_mon && daily.datetime.tm_mday == today->tm_mday) {
            std::cout << daily.name << " - " << std::put_time(&daily.datetime, "%c") << std::endl;
        }
    }
    for (Event daily : commitments) {
        if (daily.datetime.tm_year == today->tm_year && daily.datetime.tm_mon == today->tm_mon && daily.datetime.tm_mday == today->tm_mday) {
            std::cout << daily.name << " - " << std::put_time(&daily.datetime, "%c") << std::endl;
        }
    }
    std::cout << std::endl;
}

void Schedule::displayWeekly() {
    std::cout << "Weekly:" << std::endl;
    std::time_t now = std::time(0);
    std::tm* today = std::localtime(&now);
    for (Event weekly : classes) {
        if (weekly.datetime.tm_year == today->tm_year && weekly.datetime.tm_mon == today->tm_mon && weekly.datetime.tm_mday >= today->tm_mday && weekly.datetime.tm_mday < today->tm_mday + 7) {
            std::cout << weekly.name << " - " << std::put_time(&weekly.datetime, "%c") << std::endl;
        }
    }
    for (Event weekly : activities) {
        if (weekly.datetime.tm_year == today->tm_year && weekly.datetime.tm_mon == today->tm_mon && weekly.datetime.tm_mday >= today->tm_mday && weekly.datetime.tm_mday < today->tm_mday + 7) {
            std::cout << weekly.name << " - " << std::put_time(&weekly.datetime, "%c") << std::endl;
        }
    }
    for (Event weekly : commitments) {
        if (weekly.datetime.tm_year == today->tm_year && weekly.datetime.tm_mon == today->tm_mon && weekly.datetime.tm_mday >= today->tm_mday && weekly.datetime.tm_mday < today->tm_mday + 7) {
            std::cout << weekly.name << " - " << std::put_time(&weekly.datetime, "%c") << std::endl;
        }
    }
    std::cout << std::endl;
}

void Schedule::displayMonthly() {
    std::cout << "Monthly:" << std::endl;
    std::time_t now = std::time(0);
    std::tm* today = std::localtime(&now);
    for (Event monthly : classes) {
        if (monthly.datetime.tm_year == today->tm_year && monthly.datetime.tm_mon == today->tm_mon) {
            std::cout << monthly.name << " - " << std::put_time(&monthly.datetime, "%c") << std::endl;
        }
    }
    for (Event monthly : activities) {
        if (monthly.datetime.tm_year == today->tm_year && monthly.datetime.tm_mon == today->tm_mon) {
            std::cout << monthly.name << " - " << std::put_time(&monthly.datetime, "%c") << std::endl;
        }
    }
    for (Event monthly : commitments) {
        if (monthly.datetime.tm_year == today->tm_year && monthly.datetime.tm_mon == today->tm_mon) {
            std::cout << monthly.name << " - " << std::put_time(&monthly.datetime, "%c") << std::endl;
        }
    }
    std::cout << std::endl;
}

void Schedule::displayYearly() {
    std::cout << "Yearly:" << std::endl;
    std::time_t now = std::time(0);
    std::tm* today = std::localtime(&now);
    for (Event yearly : classes) {
        if (yearly.datetime.tm_year == today->tm_year) {
            std::cout << yearly.name << " - " << std::put_time(&yearly.datetime, "%c") << std::endl;
        }
    }
    for (Event yearly : activities) {
        if (yearly.datetime.tm_year == today->tm_year) {
            std::cout << yearly.name << " - " << std::put_time(&yearly.datetime, "%c") << std::endl;
        }
    }
    for (Event yearly : commitments) {
        if (yearly.datetime.tm_year == today->tm_year) {
            std::cout << yearly.name << " - " << std::put_time(&yearly.datetime, "%c") << std::endl;
        }
    }
    std::cout << std::endl;
}

void Schedule::displayAll() {
    std::cout << "All:" << std::endl;
    for (Event all : classes) {
        std::cout << all.name << " - " << std::put_time(&all.datetime, "%c") << std::endl;
    }
    for (Event all : activities) {
        std::cout << all.name << " - " << std::put_time(&all.datetime, "%c") << std::endl;
    }
    for (Event all : commitments) {
        std::cout << all.name << " - " << std::put_time(&all.datetime, "%c") << std::endl;
    }
    for (Event all : reminders) {
        std::cout << all.name << " - " << std::put_time(&all.datetime, "%c") << std::endl;
    }
    std::cout << std::endl;
}

void Schedule::removeClass(const std::string& name) {
    for (std::vector<Event>::iterator it = classes.begin(); it != classes.end(); ++it) {
        if (it->name == name) {
            classes.erase(it);
            break;
        }
    }
}

void Schedule::removeActivity(const std::string& name) {
    for (std::vector<Event>::iterator it = activities.begin(); it != activities.end(); ++it) {
        if (it->name == name) {
            activities.erase(it);
            break;
        }
    }
}


void Schedule::removeCommitment(const std::string& name) {
    for (std::vector<Event>::iterator it = commitments.begin(); it != commitments.end(); ++it) {
        if (it->name == name) {
            commitments.erase(it);
            break;
        }
    }
}

void Schedule::removeReminder(const std::string& name) {
    for (std::vector<Event>::iterator it = reminders.begin(); it != reminders.end(); ++it) {
        if (it->name == name) {
            reminders.erase(it);
            break;
        }
    }
}

void Schedule::editClass(const std::string& name, const std::tm& datetime) {
    for (Event& edit : classes) {
        if (edit.name == name) {
            edit.datetime = datetime;
            break;
        }
    }
}

void Schedule::editActivity(const std::string& name, const std::tm& datetime) {
    for (Event& edit : activities) {
        if (edit.name == name) {
            edit.datetime = datetime;
            break;
        }
    }
}

void Schedule::editCommitment(const std::string& name, const std::tm& datetime) {
    for (Event& edit : commitments) {
        if (edit.name == name) {
            edit.datetime = datetime;
            break;
        }
    }
}

void Schedule::editReminder(const std::string& name, const std::tm& datetime) {
    for (Event& edit : reminders) {
        if (edit.name == name) {
            edit.datetime = datetime;
            break;
        }
    }
}

void Schedule::saveSchedule() {
    std::ofstream file("schedule.txt");
    if (file.is_open()) {
        for (Event save : classes) {
            file << "class " << save.name << " " << std::put_time(&save.datetime, "%c") << std::endl;
        }
        for (Event save : activities) {
            file << "activity " << save.name << " " << std::put_time(&save.datetime, "%c") << std::endl;
        }
        for (Event save : commitments) {
            file << "commitment " << save.name << " " << std::put_time(&save.datetime, "%c") << std::endl;
        }
        for (Event save : reminders) {
            file << "reminder " << save.name << " " << std::put_time(&save.datetime, "%c") << std::endl;
        }
        file.close();
    }
}

void Schedule::loadSchedule() {
    std::ifstream file("schedule.txt");
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            std::string type;
            std::string name;
            std::tm datetime;
            iss >> type >> name;
            std::string datetimeString;
            iss >> datetimeString;
            std::istringstream datetimeStream(datetimeString);
            datetimeStream >> std::get_time(&datetime, "%c");
            if (type == "class") {
                addClass(name, datetime);
            }
            else if (type == "activity") {
                addActivity(name, datetime);
            }
            else if (type == "commitment") {
                addCommitment(name, datetime);
            }
            else if (type == "reminder") {
                addReminder(name, datetime);
            }
        }
        file.close();
    }
}
