
#include "network.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

int main() {

	Network* nw = new Network();
	int z = nw->read_friends("users_small.txt");
	if(z == -1) {
		cout << "Something went to shit" << endl;
	}
	else {
		cout << "It worked!" << endl;
	}

	nw->write_friends("output.txt");

	int a = nw->read_friends("output.txt");

	nw->print_users();

	if(a != -1) {
		cout << "It did it!" << endl;
	}


}