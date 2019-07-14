// FILENAME: Ngoc_Son_Nguyen_M5_Programing_Assignment_1.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: June 25, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: Ngoc_Son_Nguyen_M4_Programing_Assignment_1.cpp
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

//Implementation file

//Person Class
//Default constructor
person::person() 
{
	name = "";
	DOB = "";
	gender = "";
	master_SSN = "";
	address1 = "";
	home_phone_number = "";
}

//Constructor
person::person(std::string name_x, 
				std::string DOB_x,
				std::string gender_x,
				std::string master_SSN_x,
				std::string address1_x,
				std::string home_phone_number_x)
{
	name = name_x;
	DOB = DOB_x;
	gender = gender_x;
	master_SSN = master_SSN_x;
	address1 = address1_x;
	home_phone_number = home_phone_number_x;
}

//Print function
void person::print(void) 
{
	std::cout << "Lookup name is: " << name << std::endl;
	std::cout << "Lookup date of birth is: " << DOB << std::endl;
	std::cout << "Lookup gender is: " << gender << std::endl;
	std::cout << "Lookup master's social security number is: " << master_SSN << std::endl;
	std::cout << "Lookup address is (all on 1 line only): " << address1 << std::endl;
	std::cout << "Lookup home phone number is: " << home_phone_number << std::endl;
}

//overloaded input function
std::istream& operator>>(std::istream& str, person& p)
{
	//Initialize variables
	std::string name;
	std::string DOB;
	std::string gender;
	std::string master_SSN;
	std::string address1;
	std::string home_phone_number;

	//Input prompt
	std::cout << "Enter name (no space, example: Jeff_Nguyen): ";
	str >> name;
	p.name = name;

	std::cout << "Enter date of birth (no space, mm/dd/yyyy example: 07/12/1900): ";
	str >> DOB;
	p.DOB = DOB;

	std::cout << "Enter gender (Male/Female): ";
	str >> gender;
	p.gender = gender;

	std::cout << "Enter social security number (no space, example: 123456789): ";
	str >> master_SSN;
	p.master_SSN = master_SSN;

	std::cout << "Enter address (no space, example: 1500_Timbuktu_Seattle_WA): ";
	str >> address1;
	p.address1 = address1;

	std::cout << "Enter home phone number (no space, example: 778845698): ";
	str >> home_phone_number;
	p.home_phone_number = home_phone_number;

	return str;
}

//Employee Class
//Default constructor
employee::employee() :person()
{
	hire_date = "";
	salary = "";
	location = "";
	work_phone_number = "";
}

//Constructor
employee::employee(std::string name_x, 
					std::string DOB_x,
					std::string gender_x,
					std::string master_SSN_x,
					std::string address1_x,
					std::string home_phone_number_x,
					std::string hire_date_x,
					std::string salary_x,
					std::string location_x,
					std::string work_phone_number_x)
	: person(name_x,
		DOB_x,
		gender_x,
		master_SSN_x,
		address1_x,
		home_phone_number_x)
		{
			hire_date = hire_date_x;
			salary = salary_x;
			location = location_x;
			work_phone_number = work_phone_number_x;
		}

//Print function
void employee::print(void) 
{
	person::print();
	std::cout << "Lookup hire date is: " << hire_date << std::endl;
	std::cout << "Lookup salary is: " << salary << std::endl;
	std::cout << "Lookup location is: " << location << std::endl;
	std::cout << "Lookup work phone number is: " << work_phone_number << std::endl;
}

////overloaded input function
std::istream& operator>>(std::istream& str, employee& employ)
{
	//Initialize variables
	person* p_temp;
	p_temp = &employ;
	std::cin >> *p_temp;

	std::string hire_date;
	std::string salary;
	std::string location;
	std::string work_phone_number;
	
	//Input prompt
	std::cout << "Enter your hire date (no space, mm/dd/yyyy example: 07/12/1900): ";
	str >> hire_date;
	employ.hire_date = hire_date;

	std::cout << "Enter your salary (no space, example: $400,000): ";
	str >> salary;
	employ.salary = salary;

	std::cout << "Enter your location (no space, example: 1500_Timbuktu_Seattle_WA): ";
	str >> location;
	employ.location = location;

	std::cout << "Enter your work phone number (no space, example: 778845698): ";
	str >> work_phone_number;
	employ.work_phone_number = work_phone_number;

	return str;
}

//Dependent Class
//Default constructor
dependent::dependent() :person()
{
	address2 = "";
}

//Constructor
dependent::dependent(std::string name_x,
						std::string DOB_x,
						std::string gender_x,
						std::string master_SSN_x,
						std::string address1_x,
						std::string home_phone_number_x,
						std::string address2_x)
	: person(name_x,
		DOB_x,
		gender_x,
		master_SSN_x,
		address1_x,
		home_phone_number_x)
		{
			address2 = address2_x;
		}

//Print function
void dependent::print(void)
{
	person::print();
	std::cout << "Lookup dependent's address is: " << address2 << std::endl;
}

////overloaded input function
std::istream& operator>>(std::istream& str, dependent& dep)
{
	//Initialize variables
	person* p_temp;
	p_temp = &dep;
	std::cin >> *p_temp;

	std::string address2;
	
	//Input prompt
	std::cout << "Enter your address (if different from your sponsor, no space, example: 1500_Timbuktu_Seattle_WA): ";
	str >> address2;
	dep.address2 = address2;

	return str;
}

//Manager Class
//Default constructor
manager::manager() :employee()
{
	title = "";
}

//Constructor
manager::manager(std::string name_x,
					std::string DOB_x,
					std::string gender_x,
					std::string master_SSN_x,
					std::string address1_x,
					std::string home_phone_number_x,
					std::string hire_date_x,
					std::string salary_x,
					std::string location_x,
					std::string work_phone_number_x,
					std::string title_x)
	: employee(name_x,
		DOB_x,
		gender_x,
		master_SSN_x,
		address1_x,
		home_phone_number_x,
		hire_date_x,
		salary_x,
		location_x,
		work_phone_number_x)
		{
			title = title_x;
		}

//Print function
void manager::print(void)
{
	employee::print();
	std::cout << "Lookup title is: " << title << std::endl;
}

////overloaded input function
std::istream& operator>>(std::istream& str, manager& mgr)
{
	//Initialize variables
	employee* employ_temp;
	employ_temp = &mgr;
	std::cin >> *employ_temp;

	std::string title;

	//Input prompt
	std::cout << "Enter your title (no space, for example: CFO): ";
	str >> title;
	mgr.title = title;

	return str;
}

//Worker Class
//Default constructor
worker::worker(): employee()
{
	work_project = "";
}

//Constructor
worker::worker(std::string name_x,
				std::string DOB_x,
				std::string gender_x,
				std::string master_SSN_x,
				std::string address1_x,
				std::string home_phone_number_x,
				std::string hire_date_x,
				std::string salary_x,
				std::string location_x,
				std::string work_phone_number_x,
				std::string work_project_x)
	: employee(name_x,
		DOB_x,
		gender_x,
		master_SSN_x,
		address1_x,
		home_phone_number_x,
		hire_date_x,
		salary_x,
		location_x,
		work_phone_number_x)
		{
			work_project = work_project_x;
		}

//Print function
void worker::print(void)
{
	employee::print();
	std::cout << "Lookup work project is: " << work_project << std::endl;
}

////overloaded input function
std::istream& operator>>(std::istream& str, worker& wkr)
{
	//Initialize variables
	employee* employ_temp;
	employ_temp = &wkr;
	std::cin >> *employ_temp;

	std::string work_project;

	//Input prompt
	std::cout << "Enter your work project name: ";
	str >> work_project;
	wkr.work_project = work_project;

	return str;
}

//Main
int console(void);
int input(void);

int main(void)
{
	int role; //Role variable: people, dependents, employees, managers, workers
	int option; //Interactive option to display info
	int end_point_master = 1; //End point to quit
	int end_point; //End point to go back to menu

	//Initialize class variables
	person person_var;
	employee employee_var;
	dependent dependent_var;
	manager manager_var;
	worker worker_var;

	while (end_point_master)
	{
		role = console();
		switch (role) 
		{
			case 1: //Person option
			{
				end_point = 1;
				while (end_point)
				{
					option = input();
					switch (option)
					{
						case 1:
						{
							std::cin >> person_var;
							break;
						}
						case 2:
						{
							person_var.print();
							break;
						}
						case 3:
						{
							end_point = 0;
							break;
						}
					}
				}
				break;
			}
			
			case 2: //Employee option
			{
				end_point = 1;
				while (end_point)
				{
					option = input();
					switch (option)
					{
						case 1:
						{
							std::cin >> employee_var;
							break;
						}
						case 2:
						{
							employee_var.print();
							break;
						}
						case 3:
						{
							end_point = 0;
							break;
						}
					}
				}
				break;
			}
			
			case 3: //Dependent option
			{
				end_point = 1;
				while (end_point)
				{
					option = input();
					switch (option)
					{
						case 1:
						{
							std::cin >> dependent_var;
							break;
						}
						case 2:
						{
							dependent_var.print();
							break;
						}
						case 3:
						{
							end_point = 0;
							break;
						}
					}
				}
				break;
			}

			case 4: //Manager option
			{
				end_point = 1;
				while (end_point)
				{
					option = input();
					switch (option)
					{
						case 1:
						{
							std::cin >> manager_var;
							break;
						}
						case 2:
						{
							manager_var.print();
							break;
						}
						case 3:
						{
							end_point = 0;
							break;
						}
					}
				}
				break;
			}
			
			case 5: //Worker option
			{
				end_point = 1;
				while (end_point)
				{
					option = input();
					switch (option)
					{
						case 1:
						{
							std::cin >> worker_var;
							break;
						}
						case 2:
						{
							worker_var.print();
							break;
						}
						case 3:
						{
							end_point = 0;
							break;
						}
					}
				}
				break;
			}

			case 6: //Quit
			{
				std::cout << "Quitting" << std::endl;
				end_point_master = 0;
				break;
			}
		}
	}
	
	return 0;
	
}

//User role prompt
int console(void)
{
	int role; //Initialize role variable;

	//User prompt menu
	std::cout << "Role selection console" << std::endl;
	std::cout << "1. Person" << std::endl;
	std::cout << "2. Employee" << std::endl;
	std::cout << "3. Depedent" << std::endl;
	std::cout << "4. Manager" << std::endl;
	std::cout << "5. Worker" << std::endl;
	std::cout << "6. Quit" << std::endl;
	std::cout << "Select a role: ";
	std::cin >> role;

	return role;
	
}

//Action prompt
int input(void)
{
	int option; //Initialize action variable;

	//User prompt menu
	std::cout << "Select an action: " << std::endl;
	std::cout << "1. Data entry" << std::endl;
	std::cout << "2. Display info" << std::endl;
	std::cout << "3. Exit to previous" << std::endl;
	std::cout << "Select an action: ";
	std::cin >> option;

	return option;
}
