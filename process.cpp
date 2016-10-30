#include "process.h"

Process::Process(int id)
{
  srand(time(NULL));
  processId = id;
  //startTime = rand() % 300 + 1;
  cpuDuration = rand() % 60 + 1;
  averageCpuBurst = rand() % .1 + .005;
  //priority
  status = "Ready";
}
