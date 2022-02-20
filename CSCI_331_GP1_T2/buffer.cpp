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

/*
vector<string> buffer::headerData(ifstream& inFile, string& field) {
	vector<string> returnVector;
	for (int i = 0; i < 3; i++) {
		read(inFile);
		while (!inFile.eof()) {
			unpack(field);
			returnVector.push_back(field);
		}
	}
}
*/

/*
int headerLines(ifstream inFile) {
	int count = 0;
	read(inFile);
	while (((hex)buf[0]) <= 0x48) || (buf[0] >= 57)) {
		++count;
		read(inFile);
	}
	return count;
}
*/

int buffer::headerCount(ifstream & inFile) {
	int count = 1;
	for (int i = 0; i < 2; i++) {
		getline(inFile, buf);
		for (int i = 0; i < buf.size(); i++) {
			if (buf[i] == ',')
				++count;
		}
	}
	return count;
}
