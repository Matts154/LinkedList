/* 
 * File:   Queue.h
 * Author: Matt
 *
 * Created on June 5, 2013, 7:58 PM
 */

#ifndef QUEUE_H
#define	QUEUE_H

#include "LinkedList.h"

class Queue : protected LinkedList{
public:
	Queue();
	
	void enqueue(const int);
	void dequeue();
};

#endif	/* QUEUE_H */

