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
	@brief
	@pre
	@post
	*/
	bool unpack(string & field);

	//int headerLines(ifstream inFile);

	int headerCount(ifstream & inFile);

	/**
	@brief
	@pre
	@post
	*/
	//vector<string> headerData(ifstream & inFile, string& field);
	string getBuffer() { return buf; };




private:
	char delim;
	int size;
	int maxsize;
	int index;
	string buf;

};
#endif