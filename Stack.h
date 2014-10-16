/* 
 * File:   Stack.h
 * Author: Matt
 *
 * Created on June 5, 2013, 7:58 PM
 */

#ifndef STACK_H
#define	STACK_H

#include "LinkedList.h"

class Stack : protected LinkedList{
public:
	Stack();
	
	void push(const int);
	void pop();
};

#endif	/* STACK_H */

