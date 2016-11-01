#include "scheduler.h"
#include "event.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
  priority_queue<Event>eq;
  for(int i = 0; i < 5; i++)
    {
      Event e('P', i + 1);
      eq.push(e);
    }
  for(int i = 0; i < eq.size(); i++)
    eq[i].getinfo();
}
