#include <iostream>
#include <string>
#include "meeting.h"
#include <map>
using namespace std;

class Calender_t
{
    Calender_t();
    virtual ~Calender_t();
    bool insertMeeting(Meeting_t *meet);
    bool deleteMeeting(float startMeet);
    Meeting_t* findMeeting(float start_hour);
    void cleanCalender();
    void calenderToFile();

private:
    map<float, Meeting_t *> CalenderCont;
    Meeting_t *meetings;
    typedef typename map<float, Meeting_t *>::iterator iter;
    Calender_t(const Calender_t &t) {}
    Calender_t &operator=(const Calender_t &t) {}
};