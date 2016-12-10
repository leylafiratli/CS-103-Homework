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
#include <algorithm>

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

  vector<vector<int> > groups();

  void bfs(User* initial);

  vector<int> suggest_friends(int who, int& score);

  vector<int> shortest_path(int from, int to);

  User* get_user(int id);

  User* get_user(std::string username);

 private:

 	vector<User*> users;

  
};


#endif
