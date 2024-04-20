#ifndef SCHEDULE_H
#define SCHEDULE_H

#include "main.h"

struct Event {
    std::string name;
    std::tm datetime;
};

class Schedule {
private:
    std::vector<Event> classes;
    std::vector<Event> activities;
    std::vector<Event> commitments;
    std::vector<Event> reminders;

public:
    Schedule();
    ~Schedule();

    void addClass(const std::string& name, const std::tm& datetime);
    void addActivity(const std::string& name, const std::tm& datetime);
    void addCommitment(const std::string& name, const std::tm& datetime);
    void addReminder(const std::string& name, const std::tm& datetime);

    void displaySchedule();
    void displayReminders();
    void displayUpcoming();
    void displayDaily();
    void displayWeekly();
    void displayMonthly();
    void displayYearly();
    void displayAll();

    void removeClass(const std::string& name);
    void removeActivity(const std::string& name);
    void removeCommitment(const std::string& name);
    void removeReminder(const std::string& name);

    void editClass(const std::string& name, const std::tm& datetime);
    void editActivity(const std::string& name, const std::tm& datetime);
    void editCommitment(const std::string& name, const std::tm& datetime);
    void editReminder(const std::string& name, const std::tm& datetime);

    void saveSchedule();
    void loadSchedule();
    void loadEventsFromFile(const std::string& filename, const std::string& type);
    

};

#endif // SCHEDULE_H
