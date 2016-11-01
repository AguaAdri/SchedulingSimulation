#ifndef SCHEDULER_H
#define SCHEDULER_H

//USE VECTOR INSTEAD OF QUEUE
#include <queue>
#include <iostream>
#include <vector>
#include "process.h"
#include "event.h"
#include "random.h"
using namespace std;

class Scheduler
{
 private:
  vector<Process>processTable;
  queue<Process>rq; //Process ready queue
  priority_queue<Event>eq;
  string CPUState;
 public:
  Scheduler(int, priority_queue<Event>&); //Int is how many process should be created
  void schedule();
  void handleProcArrival(Event);
  void handleCPUCompletion(Event);
  void handleIOCompletion(Event);
  void handleTimerExpiration(Event);
  void initProcessTable(int);
};

#endif
