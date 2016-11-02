//HW1P1 queue
//Your name: Adrian Aguayo
//Complier:  g++
//File type: Queue class implementation queue.cpp

//================================================================

#include "queue.h"   
#include <iostream>
using namespace std;

// constructor
queue::queue()
{
  rear = -1;
  front = 0;
  count = 0;
}

//destructor
queue::~queue()
{
}

// PURPOSE: returns true if queue is empty, otherwise false
bool queue::isEmpty()
{
  if(count == 0)
    return true;
  else
    return false;
}

// PURPOSE: returns true if queue is full, otherwise false
bool queue::isFull()
{
  if(count == MAX_SIZE)
    return true;
  else
    return false;
}

// PURPOSE: if full, throws an exception Overflow
// if not full, enters an element at the rear
// HOW TO CALL: provide the element to be added
void queue::add(el_t elem)
{
  if(isFull())
    throw Overflow();
  rear = (rear + 1) % MAX_SIZE;
  el[rear] = elem;
  count++;
}

// PURPOSE: if empty, calls an emergency exit routine
// if not empty, removes the front element to give it back
// HOW TO CALL: provide a holder for the element removed (pass by ref)
  void queue::remove(el_t& elem)
{
  if(isEmpty())
    throw EmergencyExit();
  elem = el[front];
  //el[front] = ;
  front = (front + 1) % MAX_SIZE;
  count--;
}

// PURPOSE: if empty, throws an exception Underflow
// if not empty, give back the front element (but does not remove it)
// TO CALL: provide a holder for the element (pass by ref)
  void queue::frontElem(el_t& elem)
{
  if(isEmpty())
    throw Underflow();
  else
    elem = el[front];
}

// PURPOSE: returns the current size to make it
// accessible to the client caller
  int queue::getSize()
{
  return count;
}

// PURPOSE: display everything in the queue from front to rear
//  enclosed in []
// if empty, displays [ empty ]
  void queue::displayAll()
{
  if(isEmpty())
    cout<<"[ empty ]"<<endl;
  for(int i = front; i != (rear + 1)%count; i = (i+1) % MAX_SIZE)
      {
	cout<<"[ "<<el[i].getId()<<" ]"<<endl;
      }
}
  

// PURPOSE: if empty, throws an exception Underflow
//if queue has just 1 element, does nothing
//if queue has more than 1 element, moves the front one to the rear
  void queue::goToBack()
{
  if(isEmpty())
    throw Underflow();
  else if(front == rear)
    return;
  int temp = front; //stores front 
  front = (front + 1)%count;
  rear = temp;
}
