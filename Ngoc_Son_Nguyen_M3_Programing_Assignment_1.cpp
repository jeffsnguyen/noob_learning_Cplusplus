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

class EnglishWeight
{
	private:
		int pounds, ounces;
	public:
		EnglishWeight(void); //0-argument constructor
		EnglishWeight(int lbs, int oz);
		void Addlbs(int lbs);
		void Addoz(int oz);
		void Reset(int lbs = 0, int oz = 0);
		EnglishWeight Sum(const EnglishWeight &w) const;
		EnglishWeight Subtract(const EnglishWeight &w) const;
		double Division(const EnglishWeight &w, int *check) const ;
		EnglishWeight ScalarProduct1(const int &s) const; //Scalar Product function
		EnglishWeight ScalarProduct2(const int &s) const; //Scalar Product function
		EnglishWeight ScalarDivision(const int &s, int *check) const; //Scalar Division function
		void Show() const;
};

EnglishWeight::EnglishWeight(void)
{
	pounds = ounces = 0;
}
EnglishWeight::EnglishWeight(int lbs, int oz)
{
	pounds = lbs;
	ounces = oz;
}

void EnglishWeight::Addoz(int oz)
{
	ounces += oz;
	pounds += ounces / 16;
	ounces %= 16;
}

void EnglishWeight::Addlbs(int lbs)
{
	pounds += lbs;
}

void EnglishWeight::Reset(int lbs, int oz)
{
	pounds = lbs;
	ounces = oz;
}

EnglishWeight EnglishWeight::Sum(const EnglishWeight &w) const //Sum function
{
	EnglishWeight sum; //Declare variable
	sum.ounces = ounces + w.ounces; //For ounces, add #2 to #1, take care of the unit (1 pounds = 16 oz) later
	sum.pounds = pounds + w.pounds + w.ounces/16; //For pounds, add #2 to #1 PLUS the unit digit of the quotient of #2 / 16 to convert the extra ounces to lbs. Because they are int, the decimals are discarded.
	sum.ounces %= 16; //For ounces, do the conversion by ignoring the unit digit and only care about the remainder
	return sum;
}

EnglishWeight EnglishWeight::Subtract(const EnglishWeight &w) const //Subtract function
{
	EnglishWeight subtract; //Declare variable
	subtract.ounces = ounces - w.ounces % 16; //For ounces, subtract the remainder of #2 / 16 from #1, the unit digit does not matter.
	subtract.pounds = pounds - w.pounds - w.ounces / 16;//For pounds, subtract #2 and the unit digit of the quotient of #2 / 16 from #1
	subtract.ounces %= 16;//For ounces, similar to above, do the conversion by ignoring the unit digit and only care about the remainder
	return subtract;
}

double EnglishWeight::Division(const EnglishWeight &w, int *check) const //Division function
{
	double divide; //Declare variable 
	try 
	{
		if ((16 * w.pounds + w.ounces) == 0) //DIV/0 check;
		{
			throw 0;
		}
		else
		{
			divide = ((16 * pounds) + ounces) / ((16 * w.pounds) + w.ounces); //Convert to ounces then do the division
		}
	}
	catch (int x)
	{
		*check = x;
	}
	return divide;
}

EnglishWeight EnglishWeight::ScalarProduct1(const int &s) const //Scalar Product function
{
	EnglishWeight scalar_multi1; //Declare variable
	scalar_multi1.ounces = ounces * s; //For ounce, multiply with the scalar
	scalar_multi1.pounds = pounds * s + (scalar_multi1.ounces / 16); //For pounds, multiply with the scalar and add to the quotient of the ounces multiple result above divided by 16
	scalar_multi1.ounces %= 16; //For ounces, do the conversion by ignoring the unit digit and only care about the remainder
	return scalar_multi1;
}

EnglishWeight EnglishWeight::ScalarProduct2(const int &s) const //Scalar Product function
{
	EnglishWeight scalar_multi2; //Declare variable
	scalar_multi2.ounces = s* ounces; //For ounce, multiply with the scalar
	scalar_multi2.pounds = s* pounds + (scalar_multi2.ounces / 16); //For pounds, multiply with the scalar and add to the quotient of the ounces multiple result above divided by 16
	scalar_multi2.ounces %= 16; //For ounces, do the conversion by ignoring the unit digit and only care about the remainder
	return scalar_multi2;
}

EnglishWeight EnglishWeight::ScalarDivision(const int &s, int *check) const //Scalar Division function
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

void EnglishWeight::Show() const
{
	std::cout << pounds << " pounds, " << ounces << " ounces";
}
int main(void)
{
	EnglishWeight EnglishWeight1(5, 12);
	EnglishWeight EnglishWeight2(3, 16);
	EnglishWeight total, diff, smulti1, smulti2, sdiv1, sdiv2;
	double divi;
	int number = 0;
	int flag = 1;

	std::cout << "English Weight 1 = ";
	EnglishWeight1.Show();
	std::cout << std::endl;

	std::cout << "English Weight 2 = ";
	EnglishWeight2.Show();
	std::cout << std::endl;

	total = EnglishWeight1.Sum(EnglishWeight2);
	std::cout << "EnglishWeight1 + EnglishWeight2 = ";
	total.Show();
	std::cout << std::endl;

	diff = EnglishWeight1.Subtract(EnglishWeight2);
	std::cout << "EnglishWeight1 - EnglishWeight2 = ";
	diff.Show();
	std::cout << std::endl;
	
	divi = EnglishWeight1.Division(EnglishWeight2, &flag);
	if (flag == 0)
		std::cout << "EnglishWeight1 / EnglishWeight2 = DIV/0" << std::endl;
	else
		std::cout << "EnglishWeight1 / EnglishWeight2 = " << divi << std::endl;
	flag = 1;

	smulti1 = EnglishWeight1.ScalarProduct1(number);
	std::cout << "EnglishWeight1 * number = ";
	smulti1.Show();
	std::cout << std::endl;

	smulti2 = EnglishWeight1.ScalarProduct2(number);
	std::cout << "number * EnglishWeight1 = ";
	smulti2.Show();
	std::cout << std::endl;
	
	sdiv1 = EnglishWeight1.ScalarDivision(number, &flag);
	if (flag == 0)
		std::cout << "EnglishWeight1 / number = DIV/0" << std::endl;
	else
	{
		std::cout << "EnglishWeight1 / number = ";
		sdiv1.Show();
		std::cout << std::endl;
	}
	flag = 1;

	sdiv2 = EnglishWeight2.ScalarDivision(number, &flag);
	if (flag == 0)
		std::cout << "EnglishWeight2 / number = DIV/0" << std::endl;
	else
	{
		std::cout << "EnglishWeight2 / number = ";
		sdiv2.Show();
		std::cout << std::endl;
	}
	
	return 0;
}