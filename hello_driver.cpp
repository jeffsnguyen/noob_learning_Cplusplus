// FILENAME: hello_driver.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: May 22, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: hello_driver.cpp
//			 hello_interface.h
//			 hello_interface.cpp
// PURPOSE: Your programming assignment for this module is to re-write your hello.cpp program from Module 1 to use functions for the user input and output.
//			Create two functions, the first prompts the user for their first nameand returns the name back to main().
//			The second function is passed the user's first name and displays it on the screen.
//			Create three separate modules with the following names : hello_driver.cpp, hello_interface.h, hello_interface.cpp

#include <iostream>   // Allows use of << and >> operators.
#include "hello_interface.h" //Header file
#include "hello_interface.cpp" //Definition file
#define NAMELENGTH 50

int main(void)
{
	char first_name[NAMELENGTH]; //Declare variable
	
	getname(first_name); //Get user input function
	displayname(first_name); //Display user input on screen	

	system("pause");  
	return 0;
}

