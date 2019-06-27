// FILENAME: lc.cpp
// PROGRAMMER: Ngoc Son Nguyen
// DATE: June 25, 2019       
// COMPILER: Microsoft Visual Studio 2019 Community   
// REQUIRED: lc_driver.cpp, lc.h
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

//Implementation

//Imperial Class
//Default constructor
Imperial::Imperial()
{
	furlongs = 0;
	yards = 0;
	feet = 0;
}

//Constructor
Imperial::Imperial(int a, int b, double c)
{
	furlongs = a;
	yards = b;
	feet = c;
}

//Converter
Imperial::Imperial(Metric& length)
{
	double total_meters, total_feet;

	//Calculate and convert meters to feet
	total_meters = length.kilometers * kilometer_to_meter + length.meters;
	total_feet = total_meters * meter_to_feet;

	//Convert feet to furlongs, yards, feet
	furlongs = total_feet / furlong_to_feet;
	yards = (total_feet - furlong_to_feet * furlongs) / yard_to_feet;
	feet = total_feet - (furlong_to_feet * furlongs) - (yard_to_feet * yards);
}

//Assignment
Imperial& Imperial::operator=(Metric& length)
{
	Imperial length_imp;
	double total_meters, total_feet;
	
	//Calculate and convert meters to feet
	total_meters = length.kilometers * kilometer_to_meter + length.meters;
	total_feet = total_meters * meter_to_feet;
	
	//Convert feet to furlongs, yards, feet
	length_imp.furlongs = total_feet / furlong_to_feet;
	length_imp.yards = (total_feet - furlong_to_feet * length_imp.furlongs) / yard_to_feet;
	length_imp.feet = total_feet - (furlong_to_feet * length_imp.furlongs) - (yard_to_feet * length_imp.yards);
	
	return length_imp;
}

//Definition of Stream Extraction function, overloaded
std::istream& operator >> (std::istream& str, Imperial& length_in)
{
	str >> length_in.furlongs;
	str >> length_in.yards;
	str >> length_in.feet;
	return str;
}

//Definition of Stream Insertion function, overloaded
std::ostream& operator << (std::ostream& str, Imperial& length_out)
{
	str << length_out.furlongs << " furlongs, " << length_out.yards << " yards, " << length_out.feet << " feet";
	return str;
}

//**************************************************************************************
//Metric Class
//Default constructor
Metric::Metric()
{
	kilometers = 0;
	meters = 0;
}

//Constructor
Metric::Metric(int x, double y)
{
	kilometers = x;
	meters = y;
}

//Converter
Metric::Metric(Imperial& length)
{
	double total_meters, total_feet;

	//Calculate and convert feet to meters
	total_feet = (length.furlongs * furlong_to_feet) + (length.yards * yard_to_feet) + length.feet;
	total_meters = total_feet / meter_to_feet;

	//Convert meters to kilometers and meters
	kilometers = total_meters / kilometer_to_meter;
	meters = total_meters - (kilometers * kilometer_to_meter);

}

//Assignment
Metric& Metric::operator=(Imperial& length)
{
	Metric length_met;
	double total_meters, total_feet;
	
	//Calculate and convert feet to meters
	total_feet = length.furlongs * furlong_to_feet + (length.yards * yard_to_feet) + length.feet;
	total_meters = total_feet / meter_to_feet;
	
	//Convert meters to kilometers and meters
	length_met.kilometers = total_meters / kilometer_to_meter;
	length_met.meters = total_meters - (length_met.kilometers * kilometer_to_meter);

	return length_met;
}

//Definition of Stream Extraction function, overloaded
std::istream& operator >> (std::istream& str, Metric& length_in)
{
	str >> length_in.kilometers;
	str >> length_in.meters;
	return str;
}

//Definition of Stream Insertion function, overloaded
std::ostream& operator << (std::ostream& str, Metric& length_out)
{
	str << length_out.kilometers << " kilometers, " << length_out.meters << " meters";
	return str;
}

