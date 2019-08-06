// FILENAME: Ngoc_Son_Nguyen_M7_Programing_Assignment_1.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: Aug 5, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: Ngoc_Son_Nguyen_M7_Programing_Assignment_1.cpp
/* PURPOSE: Write a program that implements the ADT vehicle (a class with at least one pure virtual function). 
			Information you may want to keep about a vehicle includes

				identification information
				empty weight
				maximum gross weight
				maximum range
				maximum speed
			The constructor should take all such information as arguments. 
			Include virtual functions (may be pure or impure) for interrogating each such attribute.
			Also include a pure virtual function for interrogating the transportation mode.

			Construct derived classes airplane, boat, and car each derived directly from vehicle. 
			Each derived class should provide an interrogation function for the transportation mode, which should indicate 
			by-air, by-land, or by-water (or something similar).

			Write a short program which instantiates at least one object of each derived type. 
			Verify all operations work correctly.

*/

//Header file
#include <iostream>   
#include <stdlib.h>
#include <string>

//ADT class
class vehicle
{
protected:
	std::string id_info; //identification information
	int empty_weight; //empty weight
	int max_weight; //maximum gross weight
	int max_range; //maximum range
	int max_speed; //maximum speed

public:
	//Virtual function initiation
	virtual void print_id_info(void) = 0;
	virtual void print_empty_weight(void) = 0;
	virtual void print_max_weight(void) = 0;
	virtual void print_max_range(void) = 0;
	virtual void print_max_speed(void) = 0;
	
	virtual std::string transport_mode() = 0;
	virtual void print_transport_mode(void) = 0;
};

//Derived class - Airplane
class airplane : public vehicle
{
public:
	airplane(std::string str = "Air Force One", //initiate default value
				int ew = 10000,
				int mw = 100000,
				int mr = 20000,
				int ms = 300)
	{
		id_info = str;
		empty_weight = ew;
		max_weight = mw;
		max_range = mr;
		max_speed = ms;
	}
	
	void print_id_info(void);
	void print_empty_weight(void);
	void print_max_weight(void);
	void print_max_range(void);
	void print_max_speed(void);

	std::string transport_mode()
	{
		return "by-air";
	}
	void print_transport_mode(void);
};

//Functions Implementation
void airplane::print_id_info() 
{
	std::cout << "Vehicle's id information = " << id_info << std::endl;
}

void airplane::print_empty_weight() 
{
	std::cout << "Vehicle's empty weight = "<< empty_weight << std::endl;
}

void airplane::print_max_weight()
{
	std::cout << "Vehicle's max weight = " << max_weight << std::endl;
}

void airplane::print_max_range()
{
	std::cout << "Vehicle's max range = " << max_range << std::endl;
}

void airplane::print_max_speed()
{
	std::cout << "Vehicle's max speed = " << max_speed << std::endl;
}

void airplane::print_transport_mode()
{
	this->transport_mode() = transport_mode();
	std::cout << "Vehicle's transport mode = " << transport_mode() << std::endl;
}

//Derived class - Boat
class boat : public vehicle
{
public:
	boat(std::string str = "Baby Shark Doo Doo Doo", //initiate default value
		int ew = 50000,
		int mw = 1000000,
		int mr = 200000,
		int ms = 50)
	{
		id_info = str;
		empty_weight = ew;
		max_weight = mw;
		max_range = mr;
		max_speed = ms;
	}

	void print_id_info(void);
	void print_empty_weight(void);
	void print_max_weight(void);
	void print_max_range(void);
	void print_max_speed(void);

	std::string transport_mode()
	{
		return "by-boat";
	}
	void print_transport_mode(void);
};

//Implementation
void boat::print_id_info()
{
	std::cout << "Vehicle's id information = " << id_info << std::endl;
}

void boat::print_empty_weight()
{
	std::cout << "Vehicle's empty weight = " << empty_weight << std::endl;
}

void boat::print_max_weight()
{
	std::cout << "Vehicle's max weight = " << max_weight << std::endl;
}

void boat::print_max_range()
{
	std::cout << "Vehicle's max range = " << max_range << std::endl;
}

void boat::print_max_speed()
{
	std::cout << "Vehicle's max speed = " << max_speed << std::endl;
}

void boat::print_transport_mode()
{
	this->transport_mode() = transport_mode();
	std::cout << "Vehicle's transport mode = " << transport_mode() << std::endl;
}

//Derived class - Car
class car : public vehicle
{
public:
	car(std::string str = "F1", //initiate default value
		int ew = 1500,
		int mw = 2000,
		int mr = 300,
		int ms = 250)
	{
		id_info = str;
		empty_weight = ew;
		max_weight = mw;
		max_range = mr;
		max_speed = ms;
	}

	void print_id_info(void);
	void print_empty_weight(void);
	void print_max_weight(void);
	void print_max_range(void);
	void print_max_speed(void);

	std::string transport_mode()
	{
		{
			return "by-car";
		}
	}
	void print_transport_mode(void);
};

//Implementation
void car::print_id_info()
{
	std::cout << "Vehicle's id information = " << id_info << std::endl;
}

void car::print_empty_weight()
{
	std::cout << "Vehicle's empty weight = " << empty_weight << std::endl;
}

void car::print_max_weight()
{
	std::cout << "Vehicle's max weight = " << max_weight << std::endl;
}

void car::print_max_range()
{
	std::cout << "Vehicle's max range = " << max_range << std::endl;
}

void car::print_max_speed()
{
	std::cout << "Vehicle's max speed = " << max_speed << std::endl;
}

void car::print_transport_mode()
{
	this->transport_mode() = transport_mode();
	std::cout << "Vehicle's transport mode = " << transport_mode() << std::endl;
}

int main()
{
	airplane p;
	p.print_id_info();
	p.print_empty_weight();
	p.print_max_weight();
	p.print_max_range();
	p.print_max_speed();
	p.print_transport_mode();
	
	std::cout << std::endl;

	boat b;
	b.print_id_info(); 
	b.print_empty_weight();
	b.print_max_weight();
	b.print_max_range();
	b.print_max_speed();
	b.print_transport_mode();

	std::cout << std::endl;

	car c;
	c.print_id_info();
	c.print_empty_weight();
	c.print_max_weight();
	c.print_max_range();
	c.print_max_speed();
	c.print_transport_mode();

	return 0;
}
