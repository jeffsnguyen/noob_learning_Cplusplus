// FILENAME: dblstk.h
// PROGRAMMER: Ngoc Son Nguyen
// DATE: June 2, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: Stack_driver.cpp, dblstk.cpp
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

//Header file
class	DoubleStack
{
private:
	double* data;		// Pointer to dynamic stack area.
	size_t	stack_size;	// Capacity of stack.
	size_t	tos;		// Top of stack. tos==0 ==> empty stack.
public:
	DoubleStack(); //Default constructor
	DoubleStack(size_t	capacity); // Constructor.
	DoubleStack(const DoubleStack& rhs); // Copy Constructor.
	~DoubleStack(void); // Destructor.
	DoubleStack& operator=(DoubleStack& rhs); // Assignment operator=.
	int	push(double& item); // Add item to stack, making it the topmost item. Return value 1=success/0=failure.
	int	pop(double& item); // Remove top item from stack and return it in item. Return value 1=success/0=failure.
	int	empty(void); // Determine if the stack is empty. Return value 1=empty/0=non-empty.
	size_t	capacity(void); // Inquire the capacity of the stack.
	size_t	size(void); // Inquire the number of items on the stack.
	int	operator==(DoubleStack& rhs); // Compare 2 stacks to see if the contain the same data.
	void Show() const; //Displaying the stack
};
int menu(void); //Display User Menu
