#include "buffer.h"
#include <fstream>
#include <string.h> 

buffer::buffer(ifstream& inFile){
	iFile = inFile;
	index = 0;
	buf = " ";

}

string buffer::read(){
	
	getline(inFile, buf);
	return buf;

}
