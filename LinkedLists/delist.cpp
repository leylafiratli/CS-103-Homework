/* Author: Samuel Resendez
CSCI 103 - Linked Lists
saresend@usc.edu
Cheers! 
*/

/* References:
struct DEItem {
  int val;
  DEItem* prev;
  DEItem* next;
};

 ----- imports ------ */
#include <iostream>
#include "delist.h"

using namespace std;

DEList::DEList() {
	head = NULL;
	tail = NULL;
}
DEList::~DEList() {
	//I don't fucking know.
	DEItem* item;
	while(head != NULL) {
		item = head;
		head = head -> next;
		delete item;
	}
}
bool DEList::empty() {
	//cout << head -> val << endl;
	if(head) {
		return false;
	}
	return true;

}
int DEList::size() {
	if(head) {
		int counter = 0;
		DEItem* tmp = head;
		while(tmp != NULL) {
			tmp = tmp->next;
			counter++;
		}
		return counter;
	}
	return -1;
}

int DEList::front() {
	if(head) {
		return head -> val;
	}
	return -1;
}
int DEList::back() {
	if(tail) {
		return tail -> val;
	}
	return -1;

}


void DEList::push_back(int val) {
	DEItem *item = new DEItem;
	item -> val = val;
	item -> next = NULL;
	if(!tail) {
		item -> prev = NULL;
		head = item;
		tail = item;
		return;
	}
	tail -> next = item;
	item -> prev = tail;
	tail = item;
}


void DEList::push_front(int val) {
	DEItem* item = new DEItem;
	item -> val = val;
	item -> prev = NULL;
	if(!head) {
		item -> next = NULL;
		tail = item;
		head = item;
		return;
	}
	head -> prev = item;
	item -> next = head;
	head = item;

}
void DEList::pop_front() {
	if(head==tail) {
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	if(head) {
		DEItem* temp = head;
		head = head -> next;
		delete temp;
	}
	
}

void DEList::pop_back() {
	if(head == tail) {
		delete head;
		head = NULL;
		tail = NULL;
		return;
	}
	if(tail) {
		DEItem *temp = tail;
		tail = tail -> prev;
		delete temp;
	}	
}
	