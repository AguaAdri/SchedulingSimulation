#include "event.h"

Event::Event(char typeD, int id)
{
  type = typeD;
  procId = id;
}

void Event::getInfo()
{
  cout << "Event is type: " << type << " and has process ID: " << procId << 
    endl;
}

int Event::getId()
{
  return procId;
}

bool Event::operator<(const Event& e)
{
  if(this->time < e.time)
    return true;
  else
    return false;
}
