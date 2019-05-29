// FILENAME: Ngoc_Son_Nguyen_M3_Programing_Assignment_1.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: May 26, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: Ngoc_Son_Nguyen_M3_Programing_Assignment_1.cpp
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
#include <stdlib.h>
#include <string>

//Class Declaration
class EnglishWeight
{
	private:
		int pounds, ounces;
	public:
		EnglishWeight(void); //0-argument constructor
		EnglishWeight(int lbs, int oz); //Initialize
		EnglishWeight operator+(const EnglishWeight &w) const; //Sum function, overloaded
		EnglishWeight operator-(const EnglishWeight &w) const; //Subtract function, overloaded
		double Division(const EnglishWeight &w, int *check) const ; // Division of 2 weights, not overloaded because there's a check variable
		friend EnglishWeight operator*(EnglishWeight &factor, const int &s); //Scalar Product function with scalar behind
		friend EnglishWeight operator*(const int& s, EnglishWeight& factor); //Scalar Product function with scalar in front
		EnglishWeight ScalarDivision(const int &s, int *check) const; //Scalar Division function, not overloaded because there's a check variable
		friend std::istream& operator >> (std::istream& str, EnglishWeight& w_in); //Stream Extraction function, overloaded
		friend std::ostream& operator << (std::ostream& str, EnglishWeight& w_out); //Stream Insertion function, overloaded
		void ResetFlag(int* check); //Flag Reset Function
};

//Definition of 0-argument constructor
EnglishWeight::EnglishWeight(void)
{
	pounds = ounces = 0;
}

//Definition of initialize function
EnglishWeight::EnglishWeight(int lbs, int oz)
{
	pounds = lbs;
	ounces = oz;
}

//Definition of Sum function
EnglishWeight EnglishWeight::operator+(const EnglishWeight &w) const 
{
	EnglishWeight sum; //Declare variable
	sum.ounces = ounces + w.ounces; //For ounces, add #2 to #1, take care of the unit (1 pounds = 16 oz) later
	sum.pounds = pounds + w.pounds + w.ounces/16; //For pounds, add #2 to #1 PLUS the unit digit of the quotient of #2 / 16 to convert the extra ounces to lbs. Because they are int, the decimals are discarded.
	sum.ounces %= 16; //For ounces, do the conversion by ignoring the unit digit and only care about the remainder
	return sum;
}

//Definition of Subtraction function
EnglishWeight EnglishWeight::operator-(const EnglishWeight &w) const 
{
	EnglishWeight subtract; //Declare variable
	subtract.ounces = ounces - w.ounces % 16; //For ounces, subtract the remainder of #2 / 16 from #1, the unit digit does not matter.
	subtract.pounds = pounds - w.pounds - w.ounces / 16;//For pounds, subtract #2 and the unit digit of the quotient of #2 / 16 from #1
	subtract.ounces %= 16;//For ounces, similar to above, do the conversion by ignoring the unit digit and only care about the remainder
	return subtract;
}

//Definition of Division function
double EnglishWeight::Division(const EnglishWeight &w, int *check) const 
{
	double divide = 0; //Declare variable 
	double lbs1, lbs2;
	try 
	{
		if ((16 * w.pounds + w.ounces) == 0) //DIV/0 check;
		{
			throw 0;
		}
		else
		{
			lbs1 = (16 * pounds) + ounces; //Convert to ounces then do the division
			lbs2 = (16 * w.pounds) + w.ounces; //Convert to ounces then do the division
			divide = lbs1 / lbs2; 
		}
	}
	catch (int x)
	{
		*check = x;
	}
	return divide;
}

//Definition of Scalar Production function, scalar after
EnglishWeight operator*(EnglishWeight &factor, const int &s)  
{
	EnglishWeight scalar_multi; //Declare variable
	scalar_multi.ounces = factor.ounces * s; //For ounce, multiply with the scalar
	scalar_multi.pounds = factor.pounds * s + (scalar_multi.ounces / 16); //For pounds, multiply with the scalar and add to the quotient of the ounces multiple result above divided by 16
	scalar_multi.ounces %= 16; //For ounces, do the conversion by ignoring the unit digit and only care about the remainder
	return scalar_multi;
}

//Definition of Scalar Production function, scalar before
EnglishWeight operator*(const int& s, EnglishWeight& factor)  
{
	EnglishWeight scalar_multi; //Declare variable
	scalar_multi.ounces = factor.ounces * s; //For ounce, multiply with the scalar
	scalar_multi.pounds = factor.pounds * s + (scalar_multi.ounces / 16); //For pounds, multiply with the scalar and add to the quotient of the ounces multiple result above divided by 16
	scalar_multi.ounces %= 16; //For ounces, do the conversion by ignoring the unit digit and only care about the remainder
	return scalar_multi;
}

//Definition of Scalar Division function
EnglishWeight EnglishWeight::ScalarDivision(const int &s, int *check) const 
{
	EnglishWeight sdivide; //Declare variable 
	try
	{
		if (s == 0) //DIV/0 check
		{
			throw 0;
		}
		else
		{
			sdivide.ounces = (pounds * 16) + ounces;
			sdivide.pounds = sdivide.ounces / (16 * s);
			sdivide.ounces = sdivide.ounces % 16;
		}
	}
	catch(int x)
	{
		*check = x;
	}
	return sdivide;
}

//Definition of Stream Extraction function, overloaded
std::istream& operator >> (std::istream& str, EnglishWeight& w_in)
{
	str >> w_in.pounds;
	str >> w_in.ounces;
	return str;
}

//Definition of Stream Insertion function, overloaded
std::ostream& operator << (std::ostream& str, EnglishWeight &w_out) //Weight output function, overloaded
{
	str << w_out.pounds << " lbs, " << w_out.ounces << " ozs";
	return str;
}

//Definition of ResetFlag Function
void ResetFlag(int *check)
{
	*check = 1;
}

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