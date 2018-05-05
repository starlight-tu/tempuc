//Command Interface
//Ref-: cplusplus.com/articles/DEN36Up4
#include <iostream>
#include <temp.h>
using namespace std;


/* OPTIONS - FLAGS
	<Set unint for input> -TempType float
	-c	Celsius
	-f	Fahrenheit
	-k	Kelvin

	<Convert to C / F / K> -to C/K/F(toC/toK/toF) [-isInc]
	-to		a type of temperature (or all)
	-inc	as Increment Conversion (default, not add flag, is Scale Conversion)
*/


void help()
{//Manual for users
	//should I use txt file?
}

int main(int argc, char* argv[])
{
	Tempuc input;

	if (argc == 5)//Check parameters
	{// appName -flag value -flag value
		for (int i = 1; i < 5; i++)
		{
			switch (argv[i])
			{
				case "-c":
				case "-C":
					input = new Tempuc(argv[i+1]);
					break;

				case "-f":
				case "-F":
					input = new Tempuc(argv[i+1], Tempuc::TEMP_K);
					break;

				case "-k":
				case "-K":
					input = new Tempuc(argv[i+1], Tempuc::TEMP_F);
					break;

				case "-k":
				case "-K":
					input = new Tempuc(argv[i+1], Tempuc::TEMP_F);
					break;

				case "-to":
					input = new Tempuc(argv[i+1], Tempuc::TEMP_F);
					break;

				default:
					break;
			}
		}
	}
	else if (argc == 6)
	{// appName -flag value -flag value -flagOnly
		
	}
	else
	{
		help();
	}
}