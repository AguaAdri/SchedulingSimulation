#ifndef PROCESS_H
#define PROCESS_H

#include <stdlib.h>
#include <time.h>
#include <string>
using namespace std;

class Process
{
 private:
  int processId;
  int startTime;
  int cpuDuration;
  int rCpuDuration; //remaining cpu duration
  int averageCpuBurst;
  int cpuBurstLength;
  int IOBurst;
  int priority;
  string status;
 public:
  Process(int);
  int getrCpuDuration();
  int getAvgCPUB();
  void generateRIOB();
  void setCPUBurst(int);
  int pGetId();
};

#endif
