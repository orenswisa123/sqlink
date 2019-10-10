#include "calender.h"
#include <map>

bool Calender_t::insertMeeting(Meeting_t *meet)
{
    iter it;
    if (CalenderCont.begin() == CalenderCont.end())
    {
        CalenderCont[meet->getStart()] = meet;
        return true;
    }
    it = CalenderCont.begin();
    Meeting_t *M = it->second;
    if (meet->getEnd() < M->getStart())
    {
        CalenderCont[meet->getStart()] = meet;
        return true;
    }
    it = CalenderCont.end();
    it--;
    M = it->second;
    if (meet->getStart() > M->getEnd())
    {
        CalenderCont[meet->getStart()] = meet;
        return true;
    }
    it = CalenderCont.begin();
    M = it->second;
    it++;
    Meeting_t *NM = it->second;
    while (it != CalenderCont.end())
    {
        if (meet->getStart() > M->getEnd() && meet->getEnd() < NM->getStart())
        {
            CalenderCont[meet->getStart()] = meet;
            return true;
        }
        it++;
        M = it->second;
        NM = it->second;
    }
    return false;
}
bool Calender_t::deleteMeeting(float startMeet)
{
    iter it;
    try
    {
        it = CalenderCont.find(startMeet);
        CalenderCont.erase(it);
        return true;
    }
    catch (...)
    {
        return false;
    }
}
Meeting_t *Calender_t::findMeeting(float start_hour)
{
    iter it;
    try
    {
        it = CalenderCont.find(start_hour);
        return it->second;
    }
    catch (...)
    {
        return NULL;
    }
}
void Calender_t::cleanCalender()
{
    CalenderCont.clear();
}
