/**
* BUFFER.CPP
* Member function definitions for the buffer class.  
*/
#include "buffer.h"
#include <iostream>
#include <string> 

//Specified Constructor
buffer::buffer(ifstream& inFile){
	iFile = &inFile;
	index = 0;
	buf = " ";

}

//Read from buffer
string buffer::read(){
	
	getline( *iFile, buf);
	return buf;

}
