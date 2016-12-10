#include "network.h"
#include "user.h"

int main(int argc, char *argv[])
{
	if(argc < 2) {
		cout << "Please enter a valid filename" << endl;
		return -1;
	}
	//Network initialized
	Network* network = new Network();
	network -> read_friends(argv[1]);

	//Denotes the users choice. Arbitrary initialization.
	int userChoice = 1;

	while(userChoice > 0 && userChoice < 10) {
		cout << "Please enter a choice: ";
		cin >> userChoice;
		if(userChoice <= 0 || userChoice >= 10) {
			break;
		}

		if(userChoice == 1) {
			cout << "Please enter 'name' 'birthYear' 'zip Code'" << endl << "> ";

			string fName;
			string lName;
			string userName;

			int bYear;
			int zCode;
			int ID = network -> get_network_size();
			//Implement logic to make this more secure
			cin >> fName >> lName >> bYear >> zCode;
			userName = fName + " " + lName;
			cout << bYear << " " << zCode << endl;

			User* user = new User(userName,ID,bYear,zCode);
			network -> add_user(user);
		}
		else if(userChoice == 2) {
			cout << "Please enter 'name' 'name'" << endl << "> ";

			string fName1;
			string lName1;
			string fName2;
			string lName2;
			string uName1;
			string uName2;

			cin >> fName1 >> lName1 >> fName2 >> lName2;

			uName1 = fName1 + " " + lName1;
			uName2 = fName2 + " " + lName2;

			network -> add_connection(uName1, uName2);
		}
		else if(userChoice == 3) {
			cout << "Please enter 'name' 'name'" << endl << "> ";

			string fName1;
			string lName1;
			string fName2;
			string lName2;
			string uName1;
			string uName2;

			cin >> fName1 >> lName1 >> fName2 >> lName2;

			uName1 = fName1 + " " + lName1;
			uName2 = fName2 + " " + lName2;

			network -> remove_connection(uName1, uName2);
		}
		else if(userChoice == 4) {
			network -> print_users();
		}
		else if(userChoice == 5) {
			cout << "Please enter 'name'" << endl << "> ";

			string fName;
			string lName;
			cin >> fName >> lName;

			string uName = fName + " " + lName;
			User* relUser = network -> get_user(uName);
			if(relUser == NULL) {
				cout << "Sorry, couldn't find user" << endl;
			}
			else {
				//Do printing things

				/* -------- setup top ----- */
				cout << left << setw(10) << "ID";
				cout << left << setw(30) << "Name";
				cout << left << setw(10) << "Year";
				cout << left << setw(10) << "Zip";
				cout << endl;
				for(int i = 0; i< 26 + 30; i++) {
					cout << "=";
				}
				cout << endl;

				/* -------- begin loops --------- */

				//relUser -> print_friends();
				vector<int> fs = relUser -> get_friends();
				for(int i=0; i < fs.size(); i++) {
					int ID = fs[i];
					User *usr = network -> get_user(ID);

					cout << left << setw(10) << usr -> get_id();
					cout << left << setw(30) << usr -> get_name();
					cout << left << setw(10) << usr -> get_year();
					cout << left << setw(10) << usr -> get_zip();
					cout << endl;

				}
				cout << endl;
			}
		}
		else if(userChoice == 6) {
			cout << "Please enter 'filename'" << endl << "> ";
			string filename;
			cin >> filename;
			network -> write_friends(filename.c_str());
		}
		else if(userChoice == 7) {
			cout << "Please enter 'name' and 'name'" << endl << "> ";

			//Implement logic to handle one word names ??

			string fName1;
			string lName1;
			string fName2;
			string lName2;

			cin >> fName1 >> lName1 >> fName2 >> lName2;

			string uName1 = fName1 + " " + lName1;
			string uName2 = fName2 + " " + lName2;
			//User1 = initial, User2 = dest
			User *user1 = network -> get_user(uName1);
			User *user2 = network -> get_user(uName2);

			if(user1 == NULL || user2 == NULL) {
				cout << "User not found!" << endl;
				continue;
			}

			int from = user1 -> get_id();
			int to = user2 -> get_id();

			vector<int> connections = network -> shortest_path(from,to);

			if(connections.size() == 0) {
				cout << "None" << endl;
			}
			else {
				cout << "Distance: " << connections.size()-1 << endl;
				for(int i=0; i < connections.size(); i++) {
					User *currUser = network -> get_user(connections[i]);
					if(currUser == NULL) {
						continue;
					}
					string usrName = currUser -> get_name();
					if(i != 0) {
						cout << " -> ";
					}
					cout << usrName;
				}
			cout << endl;
			}	
		}
		else if(userChoice == 8) {
			vector<vector<int> > groups = network -> groups();
			for(int i = 0; i < groups.size(); i++) {
				cout << "Set " << i+1 << " =>";
				for(int j=0; j<groups[i].size();j++) {
					int userId = groups[i][j];
					User *usr = network -> get_user(userId);
					cout << " " << usr->get_name() << ",";
				}
				cout << endl;
			}
		}
		else if(userChoice == 9) {
			cout << "Please enter a 'name'" << endl << "> ";

			string fName;
			string lName;
			cin >> fName >> lName;
			string uName = fName + " " + lName;

			//suggest_friends(int who, int& score)
			User* user = network -> get_user(uName);
			if(user == NULL) {
				cout << "User not found" << endl;
				continue;
			}
			else {
				int score = 0;
				vector<int> suggestions = network -> suggest_friends(user->get_id(),score);
				if(suggestions.size() == 0) {
					cout << "None" << endl;
					continue;
				}

				cout << "The suggested friends(s) is/are:" << endl;
				for(int i=0; i<suggestions.size();i++) {
					User *usr = network -> get_user(suggestions[i]);
					cout << left << setw(20) << usr->get_name();
					cout << "Score: " << score << endl;
					
				}
				cout << endl;
			}

		}

	}
	delete network;
  return 0;
}
