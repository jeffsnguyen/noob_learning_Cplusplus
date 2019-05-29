// FILENAME: Ngoc_Son_Nguyen_M3_Programing_Assignment_1.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: May 26, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: EnglishWeight.cpp, EnglishWeight.h
/* PURPOSE: In the English system of weights, we have pounds and ounces, with 1 pound equal to 16 ounces.
			Write a class to implement English weights. The type name of the class must be called EnglishWeight.  A weight consists of both pounds and ounces.
/			Declare the class in a header file called EnglishWeight.hand implement the class in separate file called EnglishWeight.cpp.
			Include appropriate constructors.
			Include new versions of the stream insertionand stream extraction operators appropriate to this class.
			Provide the following operators :

			EnglishWeight1 + EnglishWeight2
			EnglishWeight1 - EnglishWeight2
			EnglishWeight1 / EnglishWeight2(this one takes some thought!)
			EnglishWeight1* number
			number* EnglishWeight1
			Englishweight1 / number
			Englishweight2 / number
			
			Write a small test program in a file called EW_Driver.cpp to allow a user to enter two separate weights
			(both weights must include poundsand ounces) and a number.The program will output the results of the six operations described above.
*/

#include <iostream>   
#include "EnglishWeight.h" //Header file
#include "EnglishWeight.cpp" //Definition file

//Main Driver
int main(void)
{
	EnglishWeight EnglishWeight1, EnglishWeight2; //Initialize input variables
	EnglishWeight total, diff, smulti1, smulti2, sdiv1, sdiv2; //Initialize results variables
	double divi; //Initialize result variable (weight/weight division)
	int number = 0; //Initialize scalar input variable
	int flag = 1; //Initialize DIV/0 flag check variable
	
	//User welcome message
	std::cout << "Enter 2 weights and a scalar. This program will perform basic operator function on them." << std::endl; 
	
	//Take user input of EnglishWeight1
	std::cout << "Weight 1 (example: enter 5 12 for 5 lbs 12 oz) = ";
	std::cin >> EnglishWeight1;
	std::cin.ignore();

	//Take user input of EnglishWeight2
	std::cout << "Weight 2 (example: enter 5 12 for 5 lbs 12 oz) = ";
	std::cin >> EnglishWeight2;
	std::cin.ignore();

	//Take user input of scalar
	std::cout << "Scalar (example: 2) = ";
	std::cin >> number;
	std::cin.ignore();
	
	//Display user inputs
	std::cout << std::endl;
	std::cout << "Your inputs are as below:" << std::endl;

	std::cout << "English Weight 1 = " << EnglishWeight1 << std::endl;
	std::cout << "English Weight 2 = " << EnglishWeight2 << std::endl;
	std::cout << "Scalar = " << number << std::endl;
	
	//Display result
	std::cout << std::endl;
	std::cout << "The result arithmetics are as below:" << std::endl;
	//Call Sum Function and display result
	total = EnglishWeight1 + EnglishWeight2;
	std::cout << "EnglishWeight1 + EnglishWeight2 = " << total << std::endl;
	
	//Call Subtract Function and display result
	diff = EnglishWeight1 - EnglishWeight2;
	std::cout << "EnglishWeight1 - EnglishWeight2 = " << diff << std::endl;
		
	//Call Division Function and display result
	divi = EnglishWeight1.Division(EnglishWeight2, &flag);
	if (flag == 0) //DIV/0 Check
		std::cout << "EnglishWeight1 / EnglishWeight2 = DIV/0" << std::endl; //Display DIV/0 Error handling message
	else
		std::cout << "EnglishWeight1 / EnglishWeight2 = " << divi << std::endl;
	ResetFlag(&flag); //Reset flag value

	//Call Scalar Product Function (scalar after) and display result
	smulti1 = EnglishWeight1 * number;
	std::cout << "EnglishWeight1 * number = " << smulti1 <<std::endl;
	
	//Call Scalar Product Function (scalar before) and display result
	smulti2 = number * EnglishWeight1;
	std::cout << "number * EnglishWeight1 = " << smulti2 << std::endl;
		
	//Call Scalar Division Function for EnglishWeight1 and display result
	sdiv1 = EnglishWeight1.ScalarDivision(number, &flag);
	if (flag == 0) //DIV/0 check
		std::cout << "EnglishWeight1 / number = DIV/0" << std::endl; //Display DIV/0 Error handling message
	else
		std::cout << "EnglishWeight1 / number = " << sdiv1 << std::endl;
	ResetFlag(&flag); //Reset flag value

	//Call Scalar Division Function for EnglishWeight 2 and display result
	sdiv2 = EnglishWeight2.ScalarDivision(number, &flag);
	if (flag == 0) //DIV/0 check
		std::cout << "EnglishWeight2 / number = DIV/0" << std::endl; //Display DIV/0 Error handling message
	else
		std::cout << "EnglishWeight2 / number = " << sdiv2 << std::endl;
	
	return 0;
}