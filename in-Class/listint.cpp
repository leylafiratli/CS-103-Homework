#include <iostream>
#include "listint.h"

using namespace std;

  // Initialize an empty list
ListInt::ListInt()
{
  cout << "***Creating ListInt object" << endl;
  head = NULL;
}

// Destructor (free all memory for each item)
ListInt::~ListInt()
{
  cout << "***Deleteing ListInt object" << endl;
  IntItem *tmp;
  // Add your code here to delete all IntItem structures in the list
  while(head != NULL) {
    tmp = head;
    head = head -> next;
    delete tmp;
  }
}

// Returns true if the list is empty
bool ListInt::is_empty()
{
  return !head;
}

// Returns the number of items in the list 
int ListInt::size()
{
  int num = 0;
  IntItem* tmp = head
  while(tmp != NULL) {
    num++;
    tmp = tmp -> next;
  }
  return num;
  
}

// Prints each integer item in the list (separated by a space)
void ListInt::print_list()
{
  IntItem* tmp = head;
  while(tmp != NULL) {
    cout << tmp -> val << " ";
    tmp = tmp->next;
  }
}

// Add a new integer, new_val, to the back of the list
void ListInt::push_back(int new_val)
{
  IntItem* newItem = new IntItem;
  newItem->val = new_val;
  newItem->next = NULL;
  if(head == NULL) {
    head = newItem;
  }
  IntItem* tmp = head;
  while(tmp != NULL) {
    tmp = tmp ->next;
  }
  tmp -> next = newItem;
}

// Add a new integer, new_val, to the front of the list
// pushing every other item back one
void ListInt::push_front(int new_val)
{
  IntItem* newItem = new IntItem;
  newItem -> val = new_val;
  new_item -> next = head;
  head = new_item;

}

// Remove the front item it there is one
void ListInt::pop_front()
{
  if(head != NULL) {
      IntItem* tmp = head;
      head = head -> next;
      delete tmp;
  }
}

// Return the item value at the front of the list
int ListInt::front()
{

}


// IntItem *ListInt::find(int find_val)
// {

// }

// bool ListInt::remove(int del_val)
// {

// }

// ListInt &ListInt::operator+(const ListInt &rhs)
// {

// } 


