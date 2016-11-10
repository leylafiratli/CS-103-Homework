
/* ---- imports ------ */
#include <iostream>
#include <fstream>

using namespace std;


int main(int argc, char** argv) {

	if(argc < 2) {
		cout << "No args given" << endl;
		return 1;
	}


	ofstream writeStream(argv[1]);
	writeStream << "Changing it up to check behavior" << endl;



	return 0;
}