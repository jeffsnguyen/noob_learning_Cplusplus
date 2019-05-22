// FILENAME: hello_interface.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: May 22, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: hello_driver.cpp
//			 hello_interface.h
//			 hello_interface.cpp
// PURPOSE: This is the definition file for hello_driver.h


#include <iostream>   // Allows use of << and >> operators.
#define NAMELENGTH 50

void getname(char *out_name)
{
	char name[NAMELENGTH];
	int count;

	std::cout << "Enter your first name: "; //Prompt user input
	std::cin >> name; //Receive input
	
	//Return char array
	for (count = 0; count < NAMELENGTH; count++)
		out_name[count] = name[count];

}

void displayname(char *display_name)
{
	std::cout << "Your first name is: " << display_name << std::endl; //Output
}
