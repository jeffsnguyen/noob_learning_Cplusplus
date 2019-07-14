// FILENAME: "hierarchy_driver.cpp"
// PROGRAMMER: Ngoc Son Nguyen
// DATE: July 13, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: "hierarchy.h", "hierarchy.cpp"
/* PURPOSE: Using derived classes, implement the following hierarchy 
						lvl 1	               person
						lvl 2  dependent					employee
						lvl 3					   manager				worker
								
			Provide the ability for the user to input and output all the information about each type of object. 
			Also provide public member functions for the user to 
				1) inquire the value of all the above items, and 
				2) change the ones that are reasonably changeable.
*/

//Driver file
#include "hierarchy.h"
#include "hierarchy.cpp"



//Main Driver
int console(void); //User role prompt
int input(void); //Action prompt

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
