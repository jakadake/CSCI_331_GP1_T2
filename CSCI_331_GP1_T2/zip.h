/**
* ZIP.H
* Class encapsulating the zip code, city name, state code,
* county, latitude and longitude for every postal code.   
*/


#ifndef ZIP
#define ZIP

#include <iostream>
#include <string>
using namespace std;

/**
@brief class to store each zip code as an object
*/
class zip {
public:

	/**
	@brief default constructor
	@post initializes zip object to be empty 
	*/
	zip();

	/**
	@brief specified constructor
	@pre Takes in the zipcode, city of zipcode, 2 character string statecode,
	*string for the county, floating point of the latitude, and floating point of the longitude. 
	*/
	zip(int newNum, string newCity, string newStateCode, string newCounty, float newLat, float newLon);

	/**
	@brief copy constructor
	*/
	zip(zip* oldZip);

	/**
	@brief Inline setters and getters
	*/
	
	void setNum(int newNum) { num = newNum; };

	int getNum() { return num; };

	void setCity(string newCity) { city = newCity; };

	string getCity() { return city; };

	void setStateCode(string newStateCode) { stateCode = newStateCode; };

	string getStateCode() { return stateCode; };

	void setCounty(string newCounty) { county = newCounty; };

	string getCounty() { return county; };

	void setLat(float newLat) { lat = newLat; };

	float getLat() { return lat; };

	void setLon(float newLon) { lon = newLon; };
	
	float getLon() { return lon; };
 
private:
	int num;
	float lat;
	float lon;
	string stateCode;
	string city;
	string county;
};
#endif