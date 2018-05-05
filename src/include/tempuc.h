//Ref: cplusplus.com/forum/articles/10627
#ifndef TEMPUC_H
#define TEMPUC_H

class Temp
{
private:
	float convert(Temp t);
	float getFreezingPointOfC(bool isC);//A bit urgly but easy to read :v

public:
	enum TempType
	{//Temperature Type
		TEMP_C,
		TEMP_F,
		TEMP_K
	};

	TempType type;
	float val;
	bool isInc; //true = Increment Convertion; false = Scale Conversion

	Temp(float v = 0, TempType t = TEMP_C, bool inc = false);

	float toC();
	float toK();
	float toF();

	bool operator > (Temp t);
	bool operator < (Temp t);
	bool operator >= (Temp t);
	bool operator <= (Temp t);
};

#endif
