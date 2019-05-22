// FILENAME: Ngoc_Son_Nguyen_M2_Programing_Assignment_1.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: May 22, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: Ngoc_Son_Nguyen_M2_Programing_Assignment_1.cpp
// PURPOSE: Modify the hello program to display the user's name instead of "Hello World" using cin and cout. 


#include <iostream>   // Allows use of << and >> operators.
void getname(char *out_name);
void displayname(char* display_name);

int main(void)
{
	char first_name[50]; //Declare variable
	
	getname(first_name); //Get user input function
	displayname(first_name); //Display user input on screen	

	system("pause");  
	return 0;
}

void getname(char *out_name)
{
	char name[50];
	int count;

	std::cout << "Enter your first name: "; //Prompt user input
	std::cin >> name; //Receive input
	
	//Return char array
	for (count = 0; count < 50; count++)
		out_name[count] = name[count];

}

void displayname(char *display_name)
{
	std::cout << "Your first name is: " << display_name << std::endl; //Output
}
