/*
Samuel Resendez
CSCI 103 - Programming Assignment 5
saresend@usc.edu
Cheers!
*/

/* ---- imports ---- */
#include "network.h"

using namespace std;

///////////////////////

Network::Network() {
 //Empty on purpose. 
}

Network::~Network() {

	for(int i =0; i < users.size(); i++) {
		delete users[i];
	}

}

int Network::read_friends(const char *filename) {

	users.clear();
	ifstream iFile(filename);

	if(iFile.fail()) {
		cout << "Invalid filename" << endl;
		return -1;
	}

	string strCount; 

	getline(iFile,strCount);
	int x = atoi(strCount.c_str());


/*  -------- old stuff but good stuff ------ */
	for(int i = 0; i < x; i++) {

		int id;

		string userName;
		string firstName;
		string lastName;

		int birthYear;
		int zipCode;

		vector<int> friends;

		for(int j = 0; j < 5; j++) {
			string line;
			getline(iFile,line);
			if(line == "") {
				continue;
			}
			//cout << j << " : " << line << endl;

			if(j == 0) {
				id = atoi(line.c_str());
			}
			else if(j == 1) {
				stringstream ss(line);
				ss >> firstName;
				ss >> lastName;
				userName = firstName + " " + lastName;
			}
			else if(j == 2) {
				birthYear = atoi(line.c_str());
			}
			else if(j==3) {
				zipCode = atoi(line.c_str());
			}
			else if(j==4) {
				//Create friends vector from string.
				string parsed;
				stringstream ss(line);
				int counter = 0;
				while(ss >> parsed) {
					int a = atoi(parsed.c_str());
					friends.push_back(a);
					counter++;
				}
			}
		}
		//Creating objects goes here
		User* user = new User(userName,id,birthYear,zipCode);
		for(int k = 0; k < friends.size(); k++) {
			user -> add_friend(friends[k]);
		}
		users.push_back(user);
			

		/*
		cout << "id: " << id << endl;
		cout << "birthYear: " << birthYear << endl;
		cout << "zipCode: " << zipCode << endl;
		cout << "userName: " << userName << endl;
		cout << "friends: ";
		for(int k = 0; k<friends.size();k++) {
			cout << friends[k] << " ";
		}
		cout << endl;
		*/
			
	}
	//checking all vals got read
	if(users.size() == x) {
		return 0;
	}
	return -1;

}

int Network::write_friends(const char *filename) {

	ofstream writeStream(filename);

	if(writeStream.fail()) {
		cout << "The filename is invalid" << endl;
		return -1;
	}

	writeStream << users.size();
	writeStream << "\n";

	for(int i = 0; i < users.size(); i++) { //Loops for each user!
		User currUser = *users[i];
		writeStream << currUser.get_id() << "\n";
		writeStream << "\t" << currUser.get_name() << "\n";
		writeStream << "\t" << currUser.get_year() << "\n";
		writeStream << "\t" << currUser.get_zip() << "\n";
		writeStream << "\t";
		for(int j=0; j<currUser.get_friends().size();j++) {
			int id = currUser.get_friends()[j]; //This is sketchy
			writeStream << id << " ";
		}
		writeStream << "\n";
	}

	return 0;
}

void Network::add_user(User* user) {
	for(int i = 0; i < users.size(); i++) {
		if(users[i] -> get_id() == user -> get_id()){
			cout << "This user is already in the network!" << endl;
			return;
		}
	}
	users.push_back(user);
}

int Network::add_connection(std::string name1, std::string name2) {
	User* user1 = NULL;
	User* user2 = NULL;

	for(int i = 0; i < users.size(); i++) {
		string name = users[i] -> get_name();
		if(name1 == name) {
			user1 = users[i];
		}
		if(name2 == name) {
			user2 = users[i];
		}
	}
	if(user1 == NULL || user2 == NULL) {
		cout << "Invalid username(s)" << endl;
		return -1;
	}
	else if(user1 != user2) {
		user1 -> add_friend(user2->get_id());
		user2 -> add_friend(user1 ->get_id());
	}
	return 0;
}

int Network::remove_connection(std::string name1, std::string name2) {
	User* user1 = NULL;
	User* user2 = NULL;

	for(int i =0; i < users.size(); i++) {
		string name = users[i] -> get_name();
		if(name1 == name) {
			user1 = users[i];
		}
		if(name2==name) {
			user2 = users[i];
		}
	}
	if(user1 == NULL || user2 == NULL) {
		cout << "Users not found" << endl;
		return -1;
	}
	else {
		user1 -> delete_friend(user2 -> get_id());
		user2 -> delete_friend(user1 -> get_id());
		return 0;
	}
}

int Network::get_id(std::string username) {
	for(int i = 0; i < users.size(); i++) {
		if(users[i]->get_name() == username) {
			return users[i] -> get_id();
		}
	}
	return -1;
}
void Network::print_users() {
	int maxNameSize = 25; //Get set to the largest number of name chars
	for(int i = 0; i<users.size();i++) {
		string name = users[i] -> get_name();
		if(name.size() > maxNameSize) {
			maxNameSize = name.size();
		}
	}
	/* ------ sets up top border ---- */
	cout << left << setw(10) << "ID";
	cout << left << setw(maxNameSize) << "Name";
	cout << left << setw(10) << "Year";
	cout << left << setw(10) << "Zip";
	cout << endl;
	for(int i = 0; i< 26 + maxNameSize; i++) {
		cout << "=";
	}
	cout << endl;
	/* ---------- begin loop prints ---- */

	for(int i=0;i<users.size();i++) {
		User user = *users[i];
		
		cout << left << setw(10) << user.get_id();
		cout << left << setw(maxNameSize) << user.get_name();
		cout << left << setw(10) << user.get_year();
		cout << left << setw(10) << user.get_zip();
		cout << endl;
		
	}
	cout << endl;

}

int Network::get_network_size() {
	return users.size();
}

void Network::bfs(User* to_search) {
	int currUserId = to_search -> get_id();
	int currDepth = to_search -> depth;
	if(((to_search -> get_friends()).size() == 0)) {
		cout << "Please we get here" << endl;
		return;
	}
	vector<int> friends = to_search -> get_friends();
	for(int i = 0; i < friends.size(); i ++) {
		User* usr = get_user(friends[i]);
		bool isEnd = false;
		if(usr->depth > currDepth + 1 || usr->depth < 0) {
			usr -> predecessor = currUserId;
			usr -> depth = currDepth + 1;
			isEnd = true;
		}
		if(isEnd) {
			bfs(usr);
		}
		
	}
}

vector<vector<int> > Network::groups() {
	vector<vector<int> > groups;
	for(int i = 0; i < users.size(); i++) { // initial seeds for bfs
		if(users[i]->depth == -1) {
			bfs(users[i]);
			vector<int> groupUsers;
			for(int j = 0; j<users.size(); j++) { //appends relevant users

				if(users[j]->depth >= 0) {
					groupUsers.push_back(users[j] -> get_id());
					users[j] -> depth = -2;
				}
			}
			groups.push_back(groupUsers);
		}
	}
	return groups;
}

vector<int> Network::suggest_friends(int who, int& score) {


	User* user = get_user(who);
	int bestScore = 0;
	vector<int> suggestions;

	//prepare for search
	for(int i =0; i<users.size();i++) {
		users[i] -> depth = -1;
	}

	user -> depth = 0;
	bfs(user);

	for(int k = 0; k < users.size();k++) {
		User *currUser = users[k];
		if(currUser->depth == 2) {
			int currScore = 0;

			//suggestions.push_back(currUser->get_id());

			vector<int> userFriends = user -> get_friends();
			vector<int> currFriends = currUser -> get_friends();

			


			/* ------ check how many values match ---- */

			for(int i = 0; i < userFriends.size(); i++) {
				for(int j = 0; j < currFriends.size(); j++) {
					int valToCheck = userFriends[i];
					if(currFriends[j] == valToCheck) {
						currScore++;
					}
				}
			}


			/* ----- doesn't work
			for(int i = 0; i < userFriends.size(); i++) {
				if(i >= currFriends.size()) {
					break;
				}
				if(userFriends[i] == currFriends[i]) {
					currScore++;
				}
			}
			*/

			if(currScore == bestScore) {
				suggestions.push_back(currUser->get_id());
			}
			else if(currScore >= bestScore) {
				suggestions.clear();
				suggestions.push_back(currUser->get_id());
				bestScore = currScore;
			}

		}


	}

	/* ------ filter suggestions --- */


	score = bestScore;
	return suggestions;
}

vector<int> Network::shortest_path(int from, int to) {
	vector<int> connections;
	int finalDestination = to;
	//sets up the depths and predecessors
	User *initUser = get_user(from);
	User *finalUser = get_user(to);

	initUser -> depth = 0;

	if(initUser == NULL || finalUser == NULL) {
		cout << "User not in the network" << endl;
		return connections;
	}

	bfs(initUser);

	if(finalUser -> predecessor == -1) {
		return connections;
	}
	else {
		while(to != from) {
			if(to == -1) {
				break;
			}
			connections.push_back(finalUser->predecessor);
			to = finalUser->predecessor;
			finalUser = get_user(finalUser->predecessor);
		}
	}
	vector<int> polishedConnections;
	for(int i = connections.size()-1; i >= 0; i--) {
		polishedConnections.push_back(connections[i]);
		}
	polishedConnections.push_back(finalDestination);
	return polishedConnections;
}



User* Network::get_user(string userName) {

	for(int i = 0; i < users.size(); i++) {
		if(users[i] -> get_name() == userName) {
			return users[i];
		}
	}
	return NULL;
}

 User* Network::get_user(int id) {
 	for(int i = 0; i<users.size(); i++) {
 		if(users[i] -> get_id() == id) {
 			return users[i];
 		}
 	}
 	return NULL;
 }