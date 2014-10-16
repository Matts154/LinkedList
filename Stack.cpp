/* 
 * File:   Stack.cpp
 * Author: Matt
 * 
 * Created on June 5, 2013, 7:58 PM
 */

#include "Stack.h"

Stack::Stack() {
}

void Stack::push(const int d){
	insertNode(d, 0);
}

void Stack::pop(){
	printOne(0);
	deleteNode(0);
}