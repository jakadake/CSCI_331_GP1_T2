/**
Main program 
@brief reads zip codes in from a csv file, then prints a table organized by state with most east, west, north, and south zips
@author Jake Haapoja, Ken Stearns, Nathan O'Connor, Zach Sawicki
*/

#include "buffer.h"
#include "zip.h"
#include <vector>
using namespace std;

static const short numStates = 57; // number of possible states/regions


string printTable(vector<vector<zip>>); // output data table

void readIn(ifstream& inFile, vector<vector<zip>>&); // read and parse data

short stateChooser(string x);	// return index of state with given 2 letter code

short mostNorth(vector<zip>); // searches a given state to find the most northern zipcode

short mostSouth(vector<zip>); // searches a given state to find the most southern zipcode

short mostEast(vector<zip>); // searches a given state to find the most eastern zipcode //moost steeast

short mostWest(vector<zip>); // searches a given state to find the most western zipcode

void cleanup(vector<vector<zip>>&); // deallocates memory reserved during runtime


int main() {
	ifstream inFile; // filestream object
	ofstream outFile;
	string filename;
	vector<vector<zip>> states; // array of state vectors
	states.resize(57); // initialize states vector
	
	
	cout << "Filename: ";
	cin >> filename;
	inFile.open(filename); // access the data file and associate to filestream object
	outFile.open("output.txt");
	
	string header, temp;
	header.append("Data File : ");
	header.append(filename);
	header.append("\nColumn Headers In the Data File: \n");
	for (int i = 0; i < 3; i++) {
		getline(inFile, temp);
		header.append(temp);
	}
	header.append("\n");

	readIn(inFile, states);

	outFile << header << printTable(states); // read data and pass the array of state vectors for output
	cout << "Hello World" << endl;

	outFile.close();
	inFile.close();
	return 1;
}

/**
@brief Read in data from the csv, place on buffer,
*and parse onto zip class data members;
@pre Recieves address of the file stream,
*recieves a pointer to an array of state vectors.  
@post zip code records have been read into zip objects,
*zip objects have been sorted to their respective state vectors.
*/
void readIn(ifstream& inFile, vector<vector<zip>>& states) {

	zip temp; // temporary storage for parsed record
	string item; // stores one field at a time before it's added to temp
	string headerData;

	buffer b; // create buffer object

	int tag = 0;

	while (b.read(inFile)) { // loop until end of file


		while (b.unpack(item)) {

			//cout << "Unpack " << item << endl;

			switch (tag) {
			case 0: temp.setNum(stoi(item));	//If it is a zip code
				break;
			case 1: temp.setCity(item);			//If it is a city
				break;
			case 2: temp.setStateCode(item);	//If it is a state code
				break;
			case 3: temp.setCounty(item);		//if it is a county
				break;
			case 4: temp.setLat(stof(item));	//If it is a latitude
				break;
			default: temp.setLon(stof(item));	//If it is a longitude
				tag = -1; break;
			}
			item = ""; //ittemm
			++tag;
		}
		states[stateChooser(temp.getStateCode())].push_back(zip(temp));
		// new zip object with same values as temp is added to the end of the corresponding state vector
	}
}





/**
@brief Prints the state arrays zip code state code  
@pre Receives the array of state objects 
@post prints a table of the most north, south, east,
* and west zip codes of each state
*/
string printTable(vector<vector<zip>> states) {

	string output;

	output.append("*****************************************************\n");
	output.append("*State\t|East\t\t|West\t\t|North\t\t|South\t*\n");
	output.append("*****************************************************\n");

	for (int i = 0; i < numStates; i++) {
		output.append("*");
		output.append(states[i][0].getStateCode());
		output.append("\t\t|");
		output.append(to_string(states[i][mostEast(states[i])].getNum())); 
		output.append("\t\t|");
		output.append(to_string(states[i][mostWest(states[i])].getNum()));					// MoWestuth
		output.append("\t\t|");
		output.append(to_string(states[i][mostNorth(states[i])].getNum()));
		output.append("\t\t|");
		output.append(to_string(states[i][mostSouth(states[i])].getNum()));					// MosSouthst
		output.append("\t*\n");																
	}
	output.append("*****************************************************\n");
	output.append("*State\t|East\t\t|West\t\t|North\t\t|South\t*\n");
	output.append("*****************************************************");

	return output;
}



/**
 * @brief Finds the most north zipcode of a given state
 * @pre Takes an element of the state array.  
 * @post returns the index of the most north zipcode.
 */
short mostNorth(vector<zip> state) {
	short x = 0;
	for (int i = 1; i < state.size(); i++) {
		if (state[i].getLat() > state[i-1].getLat())
			x = i;
	}
	return x;
}

/**
 * @brief Finds the most south zipcode of a given state
 * @pre Takes an element of the state array.  
 * @post returns the index of the most south zipcode.
 */
short mostSouth(vector<zip> state) {
	short x = 0;
	for (int i = 1; i < state.size(); i++) {
		if (state[i].getLat() < state[i-1].getLat())
			x = i;
	}
	return x;
}

/**
 * @brief Finds the most "esta" zipcode of a given state
 * @pre Takes an element of the state array.  
 * @post returns the index of the most east zipcode.
 */
short mostEast(vector<zip> state) {
	short x = 0;
	for (int i = 1; i < state.size(); i++) {
		if (state[i].getLon() < state[i-1].getLon())
			x = i;
	}
	return x;
}

/**
 * @brief Finds the most west zipcode of a given state
 * @pre Takes an element of the state array.  
 * @post returns the index of the most west zipcode.
 */
short mostWest(vector<zip> state) {
	short x = 0;
	for (int i = 1; i < state.size(); i++) {
		if (state[i].getLon() > state[i-1].getLon())
			x = i;
	}
	return x;
}



/******************************************STOP SCROLLING FOR YOUR OWN GOOD******************************************/

// You've been warned!!

// Last chance to turn around!

// Point of 58 returns;

/**
* @brief Chooses which state array index is correct
* with the use of a switch statement
* @pre two character state code in a string is used as parameter
* @post Returns the correct array index as an int
*/
short stateChooser(string x) {

		 if (x == "AA")	return 0;	//C++ doesn't like strings and switch statements together ;(. Amenrican Airlines?	
	else if (x == "AK") return 1;
	else if (x == "AL") return 2;
	else if (x == "AP") return 3;
	else if (x == "AR") return 4;
	else if (x == "AZ") return 5;
	else if (x == "CA") return 6;
	else if (x == "CO") return 7;
	else if (x == "CT") return 8;
	else if (x == "DC") return 9;
	else if (x == "DE") return 10;
	else if (x == "FL") return 11;
	else if (x == "FM") return 12;
	else if (x == "GA") return 13;
	else if (x == "HI") return 14;
	else if (x == "IA") return 15;
	else if (x == "ID") return 16;
	else if (x == "IL") return 17;
	else if (x == "IN") return 18;
	else if (x == "KS") return 19;
	else if (x == "KY") return 20;
	else if (x == "LA") return 21;
	else if (x == "MA") return 22;
	else if (x == "MD") return 23;
	else if (x == "ME") return 24;
	else if (x == "MH") return 25;
	else if (x == "MI") return 26;
	else if (x == "MN") return 27;
	else if (x == "MO") return 28;
	else if (x == "MP") return 29;
	else if (x == "MS") return 30;
	else if (x == "MT") return 31;
	else if (x == "NC") return 32;
	else if (x == "ND") return 33;
	else if (x == "NE") return 34;
	else if (x == "NH") return 35;
	else if (x == "NJ") return 36;
	else if (x == "NM") return 37;
	else if (x == "NV") return 38;
	else if (x == "NY") return 39;
	else if (x == "OH") return 40;
	else if (x == "OK") return 41;
	else if (x == "OR") return 42;
	else if (x == "PA") return 43;
	else if (x == "PW") return 44;
	else if (x == "RI") return 45;
	else if (x == "SC") return 46;
	else if (x == "SD") return 47;
	else if (x == "TN") return 48;
	else if (x == "TX") return 49;
	else if (x == "UT") return 50;
	else if (x == "VA") return 51;
	else if (x == "VT") return 52;
	else if (x == "WA") return 53;
	else if (x == "WI") return 54;
	else if (x == "WV") return 55;
	else if (x == "WY") return 56;
	else /****HELP****/ return -1;

}