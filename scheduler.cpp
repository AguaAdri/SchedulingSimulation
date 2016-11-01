#include "scheduler.h"

Scheduler::Scheduler(int num, priority_queue<Event>& priorq)
{
  initProcessTable(num);
  CPUState = "idle";
  eq = priorq;
}

void Scheduler::initProcessTable(int pAmnt)
{
  for(int i = 0;i < pAmnt; i++)
    {
      Process temp(i + 1);
      processTable.push_back(temp);
    }
}

void Scheduler::schedule()
{
  if(CPUState == "idle")
    {
      Process proc = rq.front();
      rq.pop();
      Event e('C',proc.pGetId()); //Creates new CPU completion event
      eq.push(e);
    }
}

void Scheduler::handleProcArrival(Event e)
{
  //First process events will be created in a for loop, with procId being initialized with the i since the process table will be random already
  
  Process proc = processTable[e.getId()];
  int nextBurst = CPUBurstRandom(proc.getAvgCPUB());
  proc.setCPUBurst(nextBurst);
  rq.push(proc);
  schedule();
}

void Scheduler::handleCPUCompletion(Event e)
{
  Process proc = processTable[e.getId()];
  if(proc.getrCpuDuration() == 0)
    {
      rq.pop();
      //Change status of process in the process table
      //Should we use pointers in the first line instead to use less memory?
    }
  else
    {
      proc.generateRIOB();
      Event IOEvent('I',proc.pGetId());
      eq.push(IOEvent);
    }
  CPUState = "idle";
  schedule();
}

void Scheduler::handleIOCompletion(Event e)
{
  Process proc = processTable[e.getId()];
  int nextBurst = CPUBurstRandom(proc.getAvgCPUB());
  //setfunction
  rq.push(proc);
}
