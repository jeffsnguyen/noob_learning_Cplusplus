// FILENAME: "hierarchy.h"
// PROGRAMMER: Ngoc Son Nguyen
// DATE: July 13, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: "hierarchy.cpp", "hierarchy_driver.cpp"
/* PURPOSE: Using derived classes, implement the following hierarchy 
						lvl 1	               person
						lvl 2  dependent					employee
						lvl 3					   manager				worker
								
			Provide the ability for the user to input and output all the information about each type of object. 
			Also provide public member functions for the user to 
				1) inquire the value of all the above items, and 
				2) change the ones that are reasonably changeable.
*/

//Header file
#include <iostream>   
#include <stdlib.h>
#include <string>

class person
{
protected:
	std::string name;
	std::string DOB;
	std::string gender;
	std::string master_SSN;
	std::string address1;
	std::string home_phone_number;

public:
	person(void); //Default constructor
	void print(void); //Print function
	friend std::istream& operator>>(std::istream& str, person& p); //overloaded input function
	person(std::string name, //Constructor
		std::string DOB,
		std::string gender,
		std::string master_SSN,
		std::string address1,
		std::string home_phone_number);
};

class employee : public person
{
protected:
	std::string hire_date;
	std::string salary;
	std::string location;
	std::string work_phone_number;

public:
	employee(void); //Default constructor
	void print(void); // Print function
	friend std::istream& operator>>(std::istream& str, employee& employ); //overloaded input function
	employee(std::string name, //Constructor
		std::string DOB,
		std::string gender,
		std::string master_SSN,
		std::string address1,
		std::string home_phone_address,
		std::string hire_date,
		std::string salary,
		std::string location,
		std::string work_phone_number);
};

class dependent : public person
{
protected:
	std::string master_SSN;
	std::string address2;

public:
	dependent(void); //Default constructor
	void print(void); //Print function
	friend std::istream& operator>>(std::istream& str, dependent& dep); //overloaded input function
	dependent(std::string name, //Constructor
		std::string DOB,
		std::string gender,
		std::string master_SSN, //SSN of the associated employee of the dependent, not the dependent's
		std::string address1,
		std::string home_phone_address,
		std::string address2);
};


class manager : public employee
{
protected:
	std::string title;

public:
	manager(void); //Default constructor
	void print(void); //Print function
	friend std::istream& operator>>(std::istream& str, manager& mgr); //overloaded input function
	manager(std::string name, //Constructor
		std::string DOB,
		std::string gender,
		std::string master_SSN,
		std::string address1,
		std::string home_phone_address,
		std::string hire_date,
		std::string salary,
		std::string location,
		std::string work_phone_number,
		std::string title);
};

class worker : public employee
{
protected:
	std::string work_project;

public:
	worker(void); //Default constructor
	void print(void); //Print function
	friend std::istream& operator>>(std::istream& str, worker& wkr); //overloaded input function
	worker(std::string name, //Constructor
		std::string DOB,
		std::string gender,
		std::string master_SSN,
		std::string address1,
		std::string home_phone_address,
		std::string hire_date,
		std::string salary,
		std::string location,
		std::string work_phone_number,
		std::string work_project);
};

