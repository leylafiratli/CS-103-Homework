/*
Author: Samuel Resendez
CSCI 103 - Fall 2016
saresend@usc.edu
Cheers!
*/

/* --- import --- */
#include <iostream>
#include "user.h"


using namespace std;

/* -------- method implementation -------- */
// name id year zip

User::User() {
	name = "";
	id = -1;
	year = -1;
	zip = -1;
}

User::User(int i) {
	name = "";
	id = i;
	year = -1;
	zip = -1;
}

User::User(string n, int i, int y, int z) {
	this->name = n;
	this->id = i;
	this->year = y;
	this->zip = z;
}

User::~User() {
	//Empty on Purpose
}

void User::add_friend(int ID) {
	bool doesExist = false;
	for(int i = 0; i < friends.size(); i++ ) {
		if(ID == friends[i]) {
			doesExist = true;
			break;
		}
	}
	if(!doesExist) {
		friends.push_back(ID);
	}
}

void User::delete_friend(int ID) {
	int index = -1;
	for(int i =0; i < friends.size(); i++) {
		if(ID == friends[i]) {
			index = i;
			break;
		}
	}
	if(index != -1) {
		friends.erase(friends.begin() + index);
	}
}

/* ----------- GETTERS -------------- */
int User::get_id() {
	return id;
}

string User::get_name() {
	return name;
}

int User::get_year() {
	return year;
}

int User::get_zip() {
	return zip;
}

vector<int> User::get_friends() {
	return friends;
}

/* ----------- SETTERS -------------- */
void User::set_id(int i) {
	id = i;
}

void User::set_name(string n) {
	name = n;
}

void User::set_year(int yr) {
	year = yr;
}

void User::set_zip(int z) {
	zip = z;
}