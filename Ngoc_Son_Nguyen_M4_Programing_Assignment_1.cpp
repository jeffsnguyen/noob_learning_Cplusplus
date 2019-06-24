// FILENAME: Ngoc_Son_Nguyen_M4_Programing_Assignment_1.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: June 2, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: Ngoc_Son_Nguyen_M4_Programing_Assignment_1.cpp
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
//Main
int main(void)
{
	int option = 1;
	DoubleStack Stack1(10);
	DoubleStack Stack2(10);

	while (option != 8)
	{
		option = menu();
		switch (option)
		{
			case 1:
			{
				std::cout << "Your option is: " << option << std::endl;
				std::cout << "Displaying stack 1" << std::endl;
				Stack1.Show();
				std::cout << std::endl;
				break;
			}

			case 2:
			{
				double push_val;
				std::cout << "Your option is: " << option << std::endl;
				std::cout << "Placing a double value onto the top stack 1" << std::endl;
				std::cout << "Enter a double value to push" << std::endl;
				std::cin >> push_val;
				try
				{
					Stack1.push(push_val);
					if (Stack1.size() > Stack1.capacity())
					{
						throw 1;
					}
				}
				catch (int x)
				{
					std::cout << "Stack overflow" << std::endl;
					exit(1);
				}
				std::cout << "Done" << std::endl;
				std::cout << std::endl;
				break;
			}

			case 3:
			{
				double pop_val;
				std::cout << "Your option is: " << option << std::endl;
				std::cout << "Remove a value from the top of stack 1" << std::endl;
				try 
				{
					Stack1.pop(pop_val);
					if (Stack1.size() > 10) 
					{
						throw 2;
					}
				}
				catch (int x) 
				{
					std::cout << "Stack underflow" << std::endl;
					exit(2);
				}
				std::cout << "Done!" << std::endl;
				std::cout << std::endl;
				break;
			}

			case 4:
			{
				std::cout << "Your option is: " << option << std::endl;
				std::cout << "Check the total capacity stack 1" << std::endl;
				std::cout << "Stack 1's capacity = " << Stack1.capacity() << std::endl;
				std::cout << std::endl;
				break;
			}

			case 5:
			{
				std::cout << "Your option is: " << option << std::endl;
				std::cout << "Check the current number of items on stack 1" << std::endl;
				std::cout << "Stack 1's current number = " << Stack1.size() << std::endl;
				std::cout << std::endl;
				break;
			}

			case 6:
			{
				std::cout << "Your option is: " << option << std::endl;
				std::cout << "Copy stack 1 to stack 2" << std::endl;
				Stack2 = Stack1;
				std::cout << std::endl;
				break;
			}

			case 7:
			{
				std::cout << "Your option is: " << option << std::endl;
				std::cout << "Check to see if two stacks are equal" << std::endl;
				if (Stack2 == Stack1)
				{
					std::cout << "Equal" << std::endl;
				}
				else 
					std::cout << "Not Equal" << std::endl;
				std::cout << std::endl;
				break;
			}

			case 8:
			{
				std::cout << "Your option is: " << option << std::endl;
				std::cout << "Quitting" << std::endl;
				std::cout << std::endl;
				break;
			}
		}
		
			
	}
	
	return 0;
}