#include "process.h"

Process::Process(int id)
{
  srand(time(NULL));
  processId = id;
  //startTime = rand() % 300 + 1;
  cpuDuration = rand() % 60 + 1;
  averageCpuBurst = rand() % 100 + 5;
  //priority
  status = "Ready";
}

int Process::getrCpuDuration()
{
  return rCpuDuration;
}

void Process::generateRIOB()
{
  IOBurst = rand() % 100 + 30;
}

void Process::setCPUBurst(int nextCPU)
{
  cpuBurstLength = nextCPU;
}

int Process::pGetId()
{
  return processId;
}

int Process::getAvgCPUB()
{
  return averageCpuBurst;
}
