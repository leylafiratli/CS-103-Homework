#ifndef NETWORK_H
#define NETWORK_H


#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <functional>
#include "user.h"
#include <iomanip>

class Network {
 public:
  Network();

  ~Network();

  int read_friends(const char *filename);

  int write_friends(const char *filename);

  void add_user(User* user);

  int add_connection(std::string name1, std::string name2);

  int remove_connection(std::string name1, std::string name2);

  int get_id(std::string username);

  void print_users();

  int get_network_size();

  User* get_user(int id);

  User* get_user(std::string username);

 private:

 	vector<User*> users;

  
};


#endif
