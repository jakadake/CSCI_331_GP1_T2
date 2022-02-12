/**






*/

#ifndef STATE_h
#define STATE_h

#include <iostream>
#include <string>
using namespace std;

class zip{};

/**


*/
class state {
public:

	typedef zip* zipPtr;

	/**
	@brief default constructor
	*/
	state();

	/**
	@brief adds a new zip object to the end of the list
	*/
	void addZip(zip& newZipNode);


	/**
	@brief return size of linked list
	@post returns size as an int
	*/
	int size() {return mySize;};

	/**
	
	*/
	void nextZip() { current = current.next; };

	/**
	@brief
	*/
	zip* getCurrent() { return current; };

	

	/**
	
	*/
	class zip {
	public:

		/**
		@brief default constructor
		@pre
		@post
		*/
		zip();

		/**
		@brief specified constructor
		@pre
		@post
		*/
		zip(int num, string city, string stateCode[2], string county, float lat, float lon);

		/**
		@brief copy constructor
		@pre
		@post
		*/
		zip(zip * old);

		


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



	private:
		int num;
		string city;
		string stateCode;
		string county;
		float lat;
		float lon;

		zip* prev = NULL;
		zip* next = NULL;
	};


private:

	int mySize = 0;

	zipPtr first = NULL;
	zipPtr current = first;
	
};


#endif