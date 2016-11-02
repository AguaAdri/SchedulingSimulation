# SchedulingSimulation

Adrian Agauyo and Richard Casillas.
11/02/2016. 
 CS433Operating Systems, Assignment 3 

This program implements both first come first serve and shortest job first scheduling algorithms. 
FCFS Scheduling: The FCFS scheduling takes in different amounts of event processes based on a command line prompt and are immediately added to the event(process) queue. The program will then move the event which entered the process queue first into the ready queue. The process is then sent to the scheduler where a series of CPU and I/O bursts complete until the CPU bursts completed are equal to the total CPU duration. The process is then terminated, the total time spent of CPU/IO bursts is added to the current time and the event queue is checked to assign the next process to run based on the smallest start time. It will continue to transfer events to the ready queue until the 5 minutes has passed or until there are no more processes left to assign.

SJF: The shortest job first scheduling takes in different amounts of event processes based on a command line prompt and are immediately added to the event queue. The program will them move the event with the shortest CPU duration into the ready queue. The process is then sent to the scheduler where a series of CPU and I/O bursts complete until the CPU bursts completed are equal to the total CPU duration. The process is then terminated, the total time spent of CPU/IO bursts is added to the current time and the event queue is checked to assign the next process to run based on the next shortest CPU duration. It will continue to transfer events to the ready queue until the 5 minutes has passed or until there are no more processes left to assign.

6. Compilation/Run: In order to compile the program navigate to the desired directory with the correct program files. Type:
make
into the command line prompt. This will optimize and compile the program into and executable called executable.
To run the program type:
./executable


