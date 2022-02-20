/**
* BUFFER.H
* Class for reading in values from a specified file to a buffer.   
*/

#ifndef BUFFER_h
#define BUFFER_h

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/**
@brief class to store each record and parse each field
*/
class buffer {
public:

	/**
	@brief Constructor for the buffer class
	@pre Takes in the address to the us_postal_codes.csv file  
	@post inFile, index and buf are all initialized
	*/
	buffer();
	buffer(char, int);

	/**
	@brief reads from csv file and places on string
	@post returns the string of one line of us_postal_codes.csv 
	*/
	bool read(ifstream& inFile);

	/**
	@brief Seperates each field from the line on the buffer
	@pre Buffer must not be empty
	@post Makes parameter string equal to correct field in record
	*/
	bool unpack(string & field);


	/**
	@brief Gives the buffer string  
	@post Returns the buffer string  
	*/
	string getBuffer() { return buf; };




private:
	char delim;
	int size;
	int maxsize;
	int index;
	string buf;

};
#endif