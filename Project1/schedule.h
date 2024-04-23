#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "main.h"


struct Event {
    std::string name;
    std::tm datetime;

    Event() : name(""), datetime() {} // Default constructor
    Event(const std::string& n, const std::tm& dt) : name(n), datetime(dt) {} // Parameterized constructor
};


class Schedule {
private:
    std::vector<Event> classes;
    std::vector<Event> activities;
    std::vector<Event> commitments;
    std::vector<Event> reminders;
    static Schedule* instance;



public:
    static Schedule* getInstance() {
        if (instance == nullptr) {
            instance = new Schedule();
        }
        return instance;
    }
    Schedule();
    ~Schedule();

    void addClass();
    void removeClass();
    void editClass();
    void saveClass();
    void loadClass();

    void addActivity();
    void removeActivity();
    void editActivity();
    void saveActivity();
    void loadActivity();

    void addCommitment();
    void removeCommitment();
    void editCommitment();
    void saveCommitment();
    void loadCommitment();

    void addReminder();
    void removeReminder();
    void editReminder();
    void saveReminder();
    void loadReminder();

};

#endif // SCHEDULE_H
