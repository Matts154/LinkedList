/* 
 * File:   Queue.cpp
 * Author: Matt
 * 
 * Created on June 5, 2013, 7:58 PM
 */

#include "Queue.h"

Queue::Queue() {
}

void Queue::enqueue(const int d){
	appendNode(d);
}

void Queue::dequeue(){
	printOne(0);
	deleteNode(0);
}