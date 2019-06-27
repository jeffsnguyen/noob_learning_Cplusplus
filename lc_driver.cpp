// FILENAME: lc_driver.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: June 25, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: lc.h, lc.cpp
/* PURPOSE: A furlong is a module of distance equal to 220 yards (1/8 mile). Write two classes that implement distances in the following manner:
			The first class keeps track of distances as a whole number of furlongs, a whole number of yards, and a number of feet, 
				which may have a fractional component.
			The second class keeps track of distances as a whole number of kilometers, followed by a number of meters, which may have a fractional component.
			Implement conversions between the two classes, ensuring that conversion in both directions is possible.
			Allow the user to enter in the two types of distances and then display the conversions for each entry:

				Furlongs, yards and feet
				Kilometers and meters

			Note that the internal view of the data is entirely up to you, but the logical view must match the specifications above. 
			Also note that the emphasis of this assignment is on the use of conversions. Exhaustive implementations of these classes are therefore not required. The ability to declare, output, and convert constitute the essential elements. The program should still consist of at least three modules.
*/
//Driver

#include "lc.h"
#include "lc.cpp"

int main(void)
{
	Imperial length_imperial, length_imperial_conv;
	Metric length_metric, length_metric_conv;

	//User input prompt - Imperial
	std::cout << "Enter distance in Imperial (for example, enter 5 12 14 for 5 furlongs 12 yards and 14 feet) = ";
	std::cin >> length_imperial;
	std::cin.ignore();
	std::cout << "You entered " << length_imperial << std::endl;

	//User input prompt - Metric
	std::cout << "Enter distance in Metric (for example, enter 5 12 for 5 kilometers 12 meters) = ";
	std::cin >> length_metric;
	std::cin.ignore();
	std::cout << "You entered " << length_metric << std::endl;

	std::cout << "Converting..." << std::endl;
	std::cout << std::endl;
	
	//Conversion & Assignment
	length_metric_conv = Metric(length_imperial);
	length_imperial_conv = Imperial(length_metric);

	//Output result
	std::cout << length_imperial << " = " << length_metric_conv;
	std::cout << std::endl;
	std::cout << length_metric << " = " << length_imperial_conv;
	std::cout << std::endl;
	
	return 0;
	
}