/**



*/

#ifndef BUFFER_h
#define BUFFER_h

#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class buffer {
public:

	/**
	@brief Constructor for the buffer class
	@param inFile is the address of the givefilen 
	@pre 
	@post inFile, index and buf are all initialized
	*/
	buffer(ifstream& inFile);

	/**
	@brief reads from csv file and places on string
	@pre
	@post
	*/
	string read();


private:

	ifstream* iFile;
	int index;
	string buf;

};


#endif