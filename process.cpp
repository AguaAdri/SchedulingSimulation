#include "process.h"

Process::Process()
{
  startTime = rand() %301 + 1;
  cpuDuration = rand() % 60 + 1;
  averageCpuBurst = rand() % 100 + 5;
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

int Process::getId()
{
  return processId;
}

int Process::getCPUBL()
{
  return cpuBurstLength;
}

int Process::getAvgCPUB()
{
  return averageCpuBurst;
}

void Process::setId(int num)
{
  processId = num;
}

int Process::getStartTime()
{
  return startTime;
}

void Process::setTime(int num)
{
  startTime = num;
}
