
#include "network.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector> 

int main() {

	Network* nw = new Network();
	nw->read_friends("users_small.txt");

	vector<int> connections = nw -> shortest_path(2,4);
	for(int i =0; i<connections.size();i++) {
		cout << connections[i] << " ";
	}
	cout << endl;

}