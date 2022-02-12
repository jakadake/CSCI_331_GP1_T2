/**



*/

#include "buffer.h"
#include "state.h"
using namespace std;

int searchStates(string code, state* states[]);

void printTable(state* states[]);

void readIn(fstream&, state states[]);

int stateChooser(string x[2]);

const int numStates = 57;

int main() {
	fstream inFile;
	state* states[numStates];




	return 1;
}

/**
@brief Read in data from the csv, place on buffer,
*and parse onto zip class data members;
@pre
@post
*/
void readIn(fstream& inFile, state states[]){

	string line = "";
	state::zip temp;
	string item;
	inFile.open("us_postal_codes.csv");
	buffer b(inFile);

	getline(inFile, line);
	getline(inFile, line);	//Lazy but it works!
	getline(inFile, line);

	while(!inFile.eof()) {
        temp = new zip;
		line = b.read();
		int marker1 = 0, marker2 = 0, tag = 0;
		for(int i = 0; i < line.size(); i++) {
			if(line[i] == ',') {
				while (marker2 < i){
					item[marker1++] = line[marker2++];
				}
				marker1 = 0;
				switch(tag) {
					case 0: temp.setNum(stoi(item));	//If it's a zip code
					case 1: temp.setCity(item);			//If it's a city
					case 2: temp.setStateCode(item);	//If it's a state code
					case 3: temp.setCounty(item);		//if its a county
					case 4: temp.setLat(stof(item));	//If it is a latitude
					case 5: temp.setLon(stof(item);		//If it is a longitude
				}
				tag++;
			}
		}
		states[stateChooser(temp.getStateCode())].addZip(new zip(temp));		//Copy constructor!
		states[stateChooser(temp.getStateCode())].nextZip();
	}
	inFile.close();
}
/**
@brief searches for the offset a specific state
@pre
@post
*/
int searchStates(string code, state* states[]) {

	for (int i = 0; i <= numStates; i++) {
		if (states[i] == NULL) {
			break;
		}




	}


}

/**

*/
void printTable(state* states[]) {
	cout << "*************************" << endl;
	for (int i = 0; i < numStates; i++) {
		cout << states[i].current.getStateCode() << endl;
		while (states[i].current != NULL) {
			cout << states[i].current.getNum;
			states[i].current = states[i].current.next;
		}
		cout << endl;
	}


}

/**
@brief Chooses which state array index is correct
*with the use of a switch statement
@pre two character state code is used as parameter
@post Returns the correct array index as an int
*/
int stateChooser(string x[2]) {
	switch (x) {
		case "AA": return 0; break;
		case "AK": return 1; break;
		case "AL": return 2; break;
		case "AP": return 3; break;
		case "AR": return 4; break;
		case "AZ": return 5; break;
		case "CA": return 6; break;
		case "CO": return 7; break;
		case "CT": return 8; break;
		case "DC": return 9; break;
		case "DE": return 10; break;
		case "FL": return 11; break;
		case "FM": return 12; break;
		case "GA": return 13; break;
		case "HI": return 14; break;
		case "IA": return 15; break;
		case "ID": return 16; break;
		case "IL": return 17; break;
		case "IN": return 18; break;
		case "KS": return 19; break;
		case "KY": return 20; break;
		case "LA": return 21; break;
		case "MA": return 22; break;
		case "MD": return 23; break;
		case "ME": return 24; break;
		case "MH": return 25; break;
		case "MI": return 26; break;
		case "MN": return 27; break;
		case "MO": return 28; break;
		case "MP": return 29; break;
		case "MS": return 30; break;
		case "MT": return 31; break;
		case "NC": return 32; break;
		case "ND": return 33; break;
		case "NE": return 34; break;
		case "NH": return 35; break;
		case "NJ": return 36; break;
		case "NM": return 37; break;
		case "NV": return 38; break;
		case "NY": return 39; break;
		case "OH": return 40; break;
		case "OK": return 41; break;
		case "OR": return 42; break;
		case "PA": return 43; break;
		case "PW": return 44; break;
		case "RI": return 45; break;
		case "SC": return 46; break;
		case "SD": return 47; break;
		case "TN": return 48; break;
		case "TX": return 49; break;
		case "UT": return 50; break;
		case "VA": return 51; break;
		case "VT": return 52; break;
		case "WA": return 53; break;
		case "WI": return 54; break;
		case "WV": return 55; break;
		case "WY": return 56; break;
		default: return -1; break;
	}
}