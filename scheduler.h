#ifndef SCHEDULER_H
#define SCHEDULER_H

#include "queue.h"
#include "EReadyQueue.h"
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
  queue rq; //Process ready queue
  string CPUState;
 public:
  Scheduler(int); //Int is how many process should be created
  void schedule(EBST&);
  void initializeTime(Event&);
  void handleProcArrival(Event&, EBST&);
  void handleCPUCompletion(Event, EBST&);
  void handleIOCompletion(Event, EBST&);
  void initProcessTable(int);
};

#endif
