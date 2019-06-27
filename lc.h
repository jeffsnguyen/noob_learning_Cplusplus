// FILENAME: lc.h
// PROGRAMMER: Ngoc Son Nguyen
// DATE: June 25, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: lc_driver.cpp, lc.cpp
/* PURPOSE: A furlong is a module of distance equal to 220 yards (1/8 mile). Write two classes that implement distances in the following manner:
			The first class keeps track of distances as a whole number of furlongs, a whole number of yards, and a number of feet, 
				which may have a fractional component.
			The second class keeps track of distances as a whole number of kilometers, followed by a number of meters, which may have a fractional component.
			Implement conversions between the two classes, ensuring that conversion in both directions is possible.
			Allow the user to enter in the two types of distances and then display the conversions for each entry:

				Furlongs, yards and feet
				Kilometers and meters

			Note that the internal view of the data is entirely up to you, but the logical view must match the specifications above. 
			Also note that the emphasis of this assignment is on the use of conversions. Exhaustive implementations of these classes are therefore not required. The ability to declare, output, and convert constitute the essential elements. The program should still consist of at least three modules.
*/

//Header file
#include <iostream>   
#include <stdlib.h>

#define furlong_to_feet 660.001
#define yard_to_feet 3
#define feet_to_meter 0.3048

#define kilometer_to_meter 1000
#define meter_to_feet 3.28084

class Imperial;
class Metric;

class Imperial
{

public:
	//Initialize variables
	int furlongs, yards;
	double feet;

	Imperial(); //Default constructor
	Imperial(int a, int b, double c); // Constructor.
	Imperial(Metric& length); // Converter
	Imperial& operator=(Metric& length); //Assignment
	
	//Overloaded input and output
	friend std::istream& operator >> (std::istream& str, Imperial& length_in);
	friend std::ostream& operator << (std::ostream& str, Imperial& length_out);
};


class Metric
{
public:
	//Initialize variables
	int kilometers;
	double meters;

	Metric(); //Default constructor
	Metric(int x, double y); //Constructor
	Metric(Imperial& length); //Converter
	Metric& operator=(Imperial& length); //Assignment
	
	//Overloaded input and output
	friend std::istream& operator >> (std::istream& str, Metric& length_in);
	friend std::ostream& operator << (std::ostream& str, Metric& length_out);
};

