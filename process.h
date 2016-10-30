#ifndef PROCESS_H
#define PROCESS_H

#include <stdlib.h>
#include <time.h>
using namespace std;

class Process
{
 private:
  int processId;
  int startTime;
  int cpuDuration;
  int rCpuDuration; //remaining cpu duration
  float averageCpuBurst;
  int cPuBurstlength;
  int IOBurst;
  int priority;
  string status;
 public:
  Process(int);
};

#endif
