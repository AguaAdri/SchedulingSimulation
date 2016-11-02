#include "scheduler.h"
#include "event.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
using namespace std;

void handleTheEvent(Event,Scheduler,EBST&);

int main(int argc, char* argv[])
{
  srand(time(NULL));
  int endTime = 300;
  EBST eq;
  Scheduler scheduler(5); //change 5 to command line arguement
  Event firstProc('P', 1);
  firstProc.setTime(0);
  eq.insertProc(firstProc);
  for(int i = 0; i < 4; i++)
    {
      Event e('P', i + 2);
      scheduler.initializeTime(e);
      eq.insertProc(e);
    }
  eq.displayQueue();
  int curTime = 0;
  while((curTime < endTime) && (eq.getSize() != 0))
  {
    Event e = eq.removeHighestProc();
    handleTheEvent(e, scheduler,eq);
    curTime = e.getTime();
    cout << "Time: "<<curTime << endl;
  }
}

void handleTheEvent(Event e, Scheduler scheduler, EBST& eq)
{
  char type = e.getType();
  switch (type) 
    {
    case 'P':
      scheduler.handleProcArrival(e, eq);
      break;
    case 'C':
      scheduler.handleCPUCompletion(e, eq);
      break;
    case 'I':
      scheduler.handleIOCompletion(e, eq);
      break;
      //case 'T':
      //scheduler.handleTimerExpiration(e);
      // break;
    }
}
