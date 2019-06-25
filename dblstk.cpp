// FILENAME: dblstk.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: June 2, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: Stack_driver.cpp, dblstk.h
/* PURPOSE: Develop a test program in a file called Stack_driver.cpp for your stack implementation.
			This driver should define a stack to hold ten values and allow the user to specify, via a menu, the following operations.
			Allow the user to enter in the values to be pushed to the top of the stack 1 via menu option 2.
			Do not initialize stack 1 with any values, all values are to be entered by the user. The user menu should appear exactly as shown:

			1. Display stack 1
			2. Place a double value onto the top of stack 1
			3. Remove a value from the top of stack 1
			4. Check the total capacity stack 1
			5. Check current number of items on stack 1
			6. Copy stack 1 to stack 2
			7. Check to see if the two stacks are equal
			8. Quit
			Enter menu selection:

			Finally, obtain a copy of the instructor's program postfix.cpp; it should be in the downloadable sample source code,
				as described in Module 1. This program evaluates postfix arithmetic expressions using your stack implementation.
				Replace your driver module with the postfix.cpp module.
				The program should run without modification, assuming you have implemented the stack correctly.
*/

#include <iostream>   
#include <stdlib.h>
#include <string>

//Implementation

//Default constructor
DoubleStack::DoubleStack()
{
	stack_size = 10;
	tos = 0;
}

//Definition of initialize function
DoubleStack::DoubleStack(size_t capacity)
{
	stack_size = capacity;
	data = new double[capacity]();
	tos = 0;
}

//Copy constructor
DoubleStack::DoubleStack(const DoubleStack& rhs) {
	std::cout << "Copying." << std::endl;
	stack_size = rhs.stack_size;
	tos = rhs.tos;
	data = new double[rhs.stack_size];

	for (int i = 0; i < stack_size; i++) {
		data[i] = rhs.data[i];
	}
}

//Destructor
DoubleStack::~DoubleStack(void)
{
	std::cout << "Exiting." << std::endl;
	delete[] data;
}

// Assignment operator=.
DoubleStack& DoubleStack::operator=(DoubleStack& rhs) 
{
	stack_size = rhs.stack_size;
	tos = rhs.tos;

	for (int i = 0; i < stack_size; i++) 
	{
		data[i] = rhs.data[i];
	}
	return *this;
}

//Display content of stack
void DoubleStack::Show() const
{
	for (int i = 0; i < 10; i++)
	{
		std::cout << data[i] << std::endl;
	}
}

// Add item to stack, making it the topmost item. Return value 1=success/0=failure.
int	DoubleStack::push(double& item) 
{
	data[tos] = item;
	tos++;
	return 0;
}

// Remove top item from stack and return it in item. Return value 1=success/0=failure.
int DoubleStack::pop(double& item) 
{
	if (tos == 0)
	{
		return 0;
	}
	tos--;
	return data[tos];
}

// Inquire the capacity of the stack.
size_t DoubleStack::capacity(void) 
{
	return stack_size;
}

// Inquire the number of items on the stack.
size_t DoubleStack::size(void) 
{
	return tos;
}

// Compare 2 stacks to see if the contain the same data.
int DoubleStack::operator==(DoubleStack& rhs) 
{
	if (stack_size == rhs.stack_size) 
	{
		for (int i = 0; i < stack_size; i++) 
		{
			if (data[i] != rhs.data[i]) 
			{
				return 0;
			}
		}
		return 1;
	}
	return 0;
}

int menu(void)
{
	int flag = 1;
	//User welcome message
	std::cout << "Use number 1-8 and press enter to navigate the menu below" << std::endl;
	std::cout << "1. Display stack 1" << std::endl;
	std::cout << "2. Place a double value onto the top of stack 1" << std::endl;
	std::cout << "3. Remove a value from the top of stack 1" << std::endl;
	std::cout << "4. Check the total capacity stack 1" << std::endl;
	std::cout << "5. Check current number of items on stack 1" << std::endl;
	std::cout << "6. Copy stack 1 to stack 2" << std::endl;
	std::cout << "7. Check to see if the two stacks are equal" << std::endl;
	std::cout << "8. Quit" << std::endl;

	//Display choice input
	std::cout << "Enter your action: ";
	std::cin >> flag;
	std::cout << std::endl;
	return flag;
}
