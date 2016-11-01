#ifndef EVENT_H
#define EVENT_H

#include <iostream>
using namespace std;

class Event
{
 private:
  int time;
  char type;
  int procId;
 public:
  Event(char, int);
  bool operator<(const Event& e);
  int getId();
  void getInfo();
};
#endif
