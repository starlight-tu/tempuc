// Temperature Unit Convertor
// Credit to Mr.Le Quoc Huy for fixing rounding error!
#include <cmath>
#include "temp.h"


//Constructors
Tempuc::Tempuc(float v, TempType t, bool inc)
: val(v), type(t), isInc(inc) {}


//Private Methods
float Tempuc::getFreezingPointOfC(bool isC)
{//Freezing Point
	if (isInc)
		return 0;
	else
		return (isC == true) ? 32 : 273.15;
}

float Tempuc::convert(Temp t)
{
	switch(type)
	{
		case TEMP_C:
			return t.toC();
			break;

		case TEMP_F:
			return t.toF();
			break;

		case TEMP_K:
			return t.toK();
			break;
	}
}


// Public Methods
float Tempuc::toC()
{
	switch (type)
	{
		case TEMP_F:
			return ((val - getFreezingPointOfC(true)) * (5.0f/9.0f));
			break;

		case TEMP_K:
			return val - getFreezingPointOfC(false);
			break;

		default:
		case TEMP_C:
			return val;
			break;
	}
}
	
float Tempuc::toK()
{
	switch (type)
	{
		case TEMP_F:
			return toC() + getFreezingPointOfC(false);
			break;

		case TEMP_C:
			return val + getFreezingPointOfC(false);
			break;

		default:
		case TEMP_K:
			return val;
			break;
	}
}
	
float Tempuc::toF()
{
	switch (type)
	{
		case TEMP_C:
			return val * (9.0f/5.0f) + getFreezingPointOfC(true);
			break;

		case TEMP_K:
			return (toC() * (9.0f/5.0f)) + getFreezingPointOfC(true);
			break;

		default:
		case TEMP_F:
			return val;
			break;
	}
}


// Operators
bool Tempuc::operator <= (Temp t)
{//Due to rounding error, we can only do approximate comparition!
	if (type == t.type)
		return val <= t.val;
	else //rounding error avoid by using |a-b| <= 10e-n (e = epsilon | n = natural number)
		return fabs(val - convert(t)) <= 10e-5; //approximate comparition
}

bool Tempuc::operator >= (Temp t)
{
	if (type == t.type)
		return val >= t.val;
	else
		return fabs(val - convert(t)) >= 10e-5;
}

bool Tempuc::operator < (Temp t)
{
	if (type == t.type)
		return val < t.val;
	else
		return val < convert(t);
}

bool Tempuc::operator > (Temp t)
{
	if (type == t.type)
		return val > t.val;
	else
		return val > convert(t);
}
