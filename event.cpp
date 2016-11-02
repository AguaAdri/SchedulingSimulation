#include "event.h"

Event::Event()
{
}

Event::Event(char typeD, int id)
{
  type = typeD;
  procId = id;
}

char Event::getType()
{
  return type;
}

int Event::getId()
{
  return procId;
}

void Event::setTime(int num)
{
  time = num;
}

int Event::getTime()
{
  return time;
}

bool Event::operator<(const Event& e)
{
  if(this->time < e.time)
    return true;
  else
    return false;
}
