/**
* BUFFER.CPP
* Member function definitions for the buffer class.  
*/
#include "buffer.h"
#include <iostream>
#include <string> 

// Default Constructor
buffer::buffer() {

	delim = ',';
	index = 0;
	buf = "";
	size = 0;
	maxsize = 1000;

}

//Specified Constructor w/ Defaults
buffer::buffer(char delim = ',', int maxsize = 1000) {

	index = 0;
	buf = "";
	size = 0;
}

//Read from buffer
bool buffer::read(ifstream& inFile){
	index = 0;
	buf = "";
	if (inFile.is_open() && !inFile.eof()) {	// execute only when the file is open and not at the end of the file
		getline(inFile,buf);					// pull everything up to the next newline
		size = buf.size();						// set size to the line length
		return true;
	}
	else
		return false;

}

bool buffer::unpack(string& field){
	if (index != size && size != 0) { // execute only when buffer is not empty

		while (index < size && buf[index] != delim) { // 
			field.push_back(buf[index++]);
		}
		if (buf[index] == delim)
			index++;
		return true;

	}
	return false;
}
