// FILENAME: Ngoc_Son_Nguyen_M3_Programing_Assignment_1.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: May 26, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: EW_Driver.cpp, EnglishWeight.cpp
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
