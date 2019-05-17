// FILENAME: Ngoc_Son_Nguyen_M1_Programing_Assignment_1.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: May 17, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: Ngoc_Son_Nguyen_M1_Programing_Assignment_1.cpp
// PURPOSE: Modify the hello program to display the user's name instead of "Hello World" using cin and cout. 


#include <iostream>   // Allows use of << and >> operators.

int main(void)
{
	char first_name[50]; //Declare variable
	
	std::cout << "Enter your first name: "; //Prompt user input
	std::cin >> first_name; //Receive input
	std::cout << "Your first name is: " << first_name << std::endl; //Output

	system("pause");  // required by some compilers to keep output window open.
	return 0;
}
