/*
Author: Samuel Resendez
Email: saresend@usc.edu
*/

/* ----- imports ---- */
#include <iostream>
#include "user.h"
#include <string>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

  User* testUser1 = new User("Steve",0,1998,92818);
  User* testUser2 = new User("Satan",0,1998,82382);
  User* testUser3 = new User("Satan",-1,1991,89823);
  User* testUser4 = new User("Hullo",5,2342,2342312);

  testUser1 -> add_friend(testUser2->get_id());
  testUser1 -> add_friend(testUser3->get_id());
  testUser1 -> add_friend(testUser4->get_id());

  vector<User*> friends = testUser1 -> get_friends();
 
  testUser1 -> print_friends();

  testUser1 -> delete_friend(0);
  testUser1 -> delete_friend(2);
  
  testUser1 -> print_friends();

  delete testUser1;
  delete testUser2;
  delete testUser3;
  delete testUser4;

  return 0;
}
