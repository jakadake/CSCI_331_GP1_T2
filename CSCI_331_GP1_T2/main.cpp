/**
Main program 
@brief reads zip codes in from a csv file, then prints a table organized by state
*/

#include "buffer.h"
#include "zip.h"
#include <vector>
using namespace std;

static const short numStates = 57; // number of possible states/regions


void printTable(vector<zip> states[]); // output data table

void readIn(ifstream& inFile, vector<zip>* states[]); // read and parse data

short stateChooser(string x);	// return index of state with given 2 letter code

short mostNorth(vector<zip> state); // searches a given state to find the most northern zipcode

short mostSouth(vector<zip> state); // searches a given state to find the most southern zipcode

short mostEast(vector<zip> state); // searches a given state to find the most eastern zipcode //moost steeast

short mostWest(vector<zip> state); // searches a given state to find the most western zipcode

void cleanup(vector<zip>* states[]); // deallocates memory reserved during runtime


int main() {
	ifstream inFile; // filestream object
	vector<zip> *states[numStates]; // array of state vectors
	for (int i = 0; i < numStates; i++) {
		states[i] = new vector<zip>; // initialize the array
	}
	readIn(inFile, states); // read and parse data
	printTable(*states); // pass the array of state vectors for output

	cleanup(states); // deallocate all reserved memory

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
void readIn(ifstream& inFile, vector<zip>* states[]){

	string line = ""; // record input storage
	zip temp; // temporary storage for parsed record
	string item; // stores one field at a time before it's added to temp
	inFile.open("us_postal_codes.csv"); // access the data file and associate to filestream object

	getline(inFile, line);
	getline(inFile, line);	//Lazy but it works! (clears the junk data at the start of the file)
	getline(inFile, line);

	buffer b(inFile); // create buffer object

	while(!inFile.eof()) { // loop until end of file

		line = b.read(); // pull next line

		int marker1 = 0, // what do these do??
			marker2 = 0, 
			tag = 0;

		for(int i = 0; i < line.size(); i++) {

			if(line[i] == ',') {

				while (marker2 < i){
					item[marker1++] = line[marker2++]; // how does this work??
				}

				marker1 = 0;
				switch(tag) {
					case 0: temp.setNum(stoi(item));	//If it is a zip code
					case 1: temp.setCity(item);			//If it is a city
					case 2: temp.setStateCode(item);	//If it is a state code
					case 3: temp.setCounty(item);		//if it is a county
					case 4: temp.setLat(stof(item));	//If it is a latitude
					case 5: temp.setLon(stof(item));	//If it is a longitude
				}
				tag++;
			}
		}
		states[stateChooser(temp.getStateCode())] -> push_back(new zip(temp));
		// new zip object with same values as temp is added to the end of the corresponding state vector
	}
	inFile.close();
}


/**
@brief Prints the state arrays zip code state code  
@pre Recieves the array of state objects 
*/
void printTable(vector<zip> states[]) {
	cout << "*************************" << endl;
	for (int i = 0; i < numStates; i++) {
		cout << states[i][0].getStateCode() << endl;
		cout << "Most East: " << states[i][mostEast(states[i])].getNum() 
			<< " Most West: " << states[i][mostWest(states[i])].getNum() // MoWestuth
			<< " Most North: " << states[i][mostNorth(states[i])].getNum() 
			<< " Most South: " << states[i][mostSouth(states[i])].getNum() << endl; // MosSouthst
	}
	cout << "*************************" << endl;
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
 * @brief Finds the most esta zipcode of a given state
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

/**
@brief cleanup function
@pre is passed the filled array of state vectors
@post each zip object and state vector has been deallocated
*/

void cleanup(vector<zip>* states[]) {

	for (int i = numStates - 1; i >= 0; i++) {
		for (int j = states[i] -> size() - 1; j >= 0; j--) {

			delete &states[i][j];

		}
		delete &states[i];
	}

}



/******************************************STOP SCROLLING FOR YOUR OWN GOOD******************************************/

// You've been warned!!

// Last chance to turn around!

// Point of 58 returns;

/**
@brief Chooses which state array index is correct
*with the use of a switch statement
@pre two character state code in a string is used as parameter
@post Returns the correct array index as an int
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