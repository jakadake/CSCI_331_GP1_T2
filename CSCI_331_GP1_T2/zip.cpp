/**
* ZIP.CPP
* Member function definitions for the zip class.  
*/

#include <iostream>
#include <string>
#include <new>
#include "zip.h"

using namespace std;

//Default Constructor
zip::zip()
{
	num = -1;
	city = "";
	stateCode = "";
	county = "";
	lat = 0;
	lon = 0;
}

//Specified Constructor
zip::zip(int newNum, string newCity, string newStateCode, string newCounty, float newLat, float newLon)
{
	num = newNum;
	city = newCity;
	stateCode = newStateCode;
	county = newCounty;
	lat = newLat;
	lon = newLon;
}

// copy constructor
zip::zip(zip* oldZip) 
{
	num = oldZip->getNum();
	city = oldZip->getCity();
	stateCode = oldZip->getStateCode();
	county = oldZip->getCounty();
	lat = oldZip->getLat();
	lon = oldZip->getLon();
}