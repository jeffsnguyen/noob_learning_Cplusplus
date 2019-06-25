// FILENAME: Stack_driver.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: June 2, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: DoubleStack.cpp, DoubleStack.h
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
#include "dblstk.h" //Header file
#include "dblstk.cpp" //Implementation file


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
			if (!(std::cin >> push_val))
			{
				std::cin.clear();
				std::cin.ignore();
				std::cout << "Incorrect entry." << std::endl;
			}
			else
			{
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
			}
			std::cout << "Done" << std::endl;
			std::cout << std::endl;
			break;

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
	}
	return 0;
	
}