/* 
 * File:   main.cpp
 * Author: Matt
 *
 * Created on June 21, 2013, 1:29 PM
 */

#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
	LinkedList list1;
	LinkedList list2;
	
	list1.appendNode(5);
	list1.appendNode(6);
	list1.appendNode(15);
	list1.insertNode(2, 0);
	
	cout << "Index Operator: " << list1[1] << endl << endl;
	
	cout << "Size: " << list1.getSize() << endl;
	
	cout << endl << "List 1:" << endl;
	list1.print();
	list1.printReverse();
	
	list1.deleteNode(0);
	
	cout << endl << "List 1 (after delete):" << endl;
	list1.print();
	
	list2.appendNode(10);
	list2 = list1;
	list2.appendNode(7);
	
	cout << endl << "List 2:" << endl;
	list2.print();
	
	return 0;
}
