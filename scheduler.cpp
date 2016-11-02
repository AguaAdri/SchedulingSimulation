#include "scheduler.h"

Scheduler::Scheduler(int num)
{
  initProcessTable(num);
  CPUState = "idle";
}

void Scheduler::initProcessTable(int pAmnt)
{
  Process firstProc;
  firstProc.setId(1);
  firstProc.setTime(0);
  processTable.push_back(firstProc);
  for(int i = 0;i < pAmnt - 1; i++)
    {
      Process temp;
      temp.setId(i+2);
      cout << temp.getStartTime() << endl;
      processTable.push_back(temp);
    }
}

void Scheduler::schedule(EBST& eq)
{
  cout << "in schedule" << endl;
  if(CPUState == "idle")
    {
      Process proc;
      if(!rq.isEmpty())
      rq.frontElem(proc);
      //change state of proc to running
      Event e('C',proc.getId()); //Creates new CPU completion event
      e.setTime(proc.getCPUBL());
      cout<< e.getTime();
      eq.insertProc(e);
      eq.displayQueue();
      CPUState = "running";
    }
}

void Scheduler::initializeTime(Event& e)
{
  Process proc = processTable[e.getId() - 1];
  e.setTime(proc.getStartTime());
}

void Scheduler::handleProcArrival(Event& e, EBST& evq)
{
  Process proc = processTable[e.getId() - 1]; 
  int nextBurst = CPUBurstRandom(proc.getAvgCPUB());
  proc.setCPUBurst(nextBurst);
  rq.add(proc);
  schedule(evq);
}

void Scheduler::handleCPUCompletion(Event e, EBST& evq)
{
  Process proc = processTable[e.getId()];
  //  if(proc.getrCpuDuration() == 0)
    //{
  if(!rq.isEmpty())
    rq.remove(proc);
      //Change status of process in the process table
      // }
      // else
      // {
      // proc.generateRIOB();
      // Event IOEvent('I',proc.getId());
      // evq.insertProc(IOEvent);
      // }
  CPUState = "idle";
  schedule(evq);
}

void Scheduler::handleIOCompletion(Event e, EBST& evq)
{
  Process proc = processTable[e.getId()];
  int nextBurst = CPUBurstRandom(proc.getAvgCPUB());
  //setfunction
  rq.add(proc);
  schedule(evq);
}
