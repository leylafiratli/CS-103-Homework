/*
Author: Samuel Resendez
CSCI 103 - Fall 2016
saresend@usc.edu
Cheers!
*/


#ifndef USER_H
#define USER_H



/* ------ imports ----- */
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

/*----------------------*/

class User {
 public:

 	User();

 	User(int id);

 	User(string name, int id, int year, int zip);

 	~User();

 	void add_friend(int id);

 	void delete_friend(int id);

 	/* ---- getters ---- */

 	int get_id();

 	string get_name();

 	int get_year();

 	int get_zip();

 	vector<int> get_friends();

 	


 	/* ----- setters ---- */

 	void set_id(int id);

 	void set_name(string name);

 	void set_year(int year);

 	void set_zip(int zip);


 private:
 	/* ------ Int attributes -------- */
 	int id;

 	int year;

 	int zip;
 

 	/* -------String attributes ----- */

 	string name;


 	/* ------- Vector attributes ---- */
 	vector<int> friends;

};


#endif
