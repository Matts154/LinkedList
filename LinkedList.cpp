/* 
 * File:   LinkedList.cpp
 * Author: Matt
 * 
 * Created on June 21, 2013, 1:30 PM
 */

#include <cstdlib>
#include <iostream>
#include "LinkedList.h"

using namespace std;

LinkedList::LinkedList() {
	head = NULL;
	size = 0;
}

LinkedList::LinkedList(const LinkedList &orig) {
	head = NULL;
	size = 0;
	
	Node *current = orig.head;

	while(current){ //While current is something, keep looping. Ends on NULL
		appendNode(current->data); //Append 'this' pointer with originals values
		current = current->next; //Move along the original list.
	}
}

LinkedList::~LinkedList() {
	emptyList();
}


void LinkedList::appendNode(const int d){
	Node *newNode = new Node;
	Node *current = head;
	
	newNode->data = d;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(!head)
		head = newNode;
	else{
		while(current->next)
			current = current->next;
		
		current->next = newNode;
		newNode->prev = current;
	}

	size++;
}

bool LinkedList::insertNode(const int d, const int i){
	if(i > size){
		return false;
	}
	
	Node *current = head;
	Node *newNode = new Node;

	newNode->data = d;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	if(i == 0){ //Inserting at the beginning of the list
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
	else{
		for(int pos = 0; pos < i; pos++){
			current = current->next;
		}

		newNode->prev = current->prev;
		newNode->next = current;

		current->prev->next = newNode;
		current->prev = newNode;
	}
	
	size++;
	return true;
}

bool LinkedList::deleteNode(const int i){
	Node *current = head;
	
	if(current == NULL){
		return false;
	}
	
	if(i > size){
		return false;
	}
	
	if(i == 0){
		
		head = current->next;
		head->prev = NULL;
	}
	else{
		for(int pos = 0; pos < i; pos++){
			current = current->next;
		}

		current->prev->next = current->next;
		current->next->prev = current->prev;
	}
	
	delete current;
	size--;
	
	return true;
}

void LinkedList::emptyList(){
	Node *nodePtr;   // To traverse the list
	Node *nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != NULL)
	{
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
	
	head = NULL;
	
	size = 0;
}

void LinkedList::print(){
	Node *current = head;

	if(!head){
		cout << "List empty.";
		return;
	}
	
	while(current){
		cout << current->data << endl;
		current = current->next;
	}
}

void LinkedList::printReverse(){
	Node *current = head;

	if(!head){
		cout << "List empty.";
		return;
	}
	
	while(current->next){
		current = current->next;
	}
	
	while(current){
		cout << current->data << endl;
		current = current->prev;
	}
}

void LinkedList::printOne(const int i){
	Node *current = head;
	
	if(i > size){
		cout << "Given index is larger than list size." << endl;
		return;
	}
	
	for(int a = 0; a < i; a++){
		current = current->next;
	}
	
	cout << current->data << endl;
}

//ostream LinkedList::operator<<(ostream &stream){
//	Node *current = head;
//
//	if(!current){
//		stream << "List empty.";
//	}
//	else{
//		while(current){
//			stream << current->data << endl;
//			current = current->next;
//		}
//	}
//	
//	return stream;
//}

LinkedList LinkedList::operator=(const LinkedList &orig){
	if(this == &orig)
		return *this;
	
	Node *current = orig.head;

	emptyList();
	
	while(current){ //While current is something, keep looping. Ends on NULL
		appendNode(current->data); //Append 'this' pointer with originals values
		current = current->next; //Move along the original list.
	}
	
	return *this;
}

int LinkedList::operator[](int i){
	Node *current = head;
	
	if(i > size){
		return -1;
	}
	
	for(int a = 0; a < i; a++){
		current = current->next;
	}
	
	return current->data;
}