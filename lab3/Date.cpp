#include "Date.h"
#include <iostream>
using namespace std;




	Date::Date()
	{
		month = 1;
		day = 1;
		year = 1;
	}

	Date::Date(int mon, int dy, int yr)
	{
		if (mon < 13 && mon >0)
			month = mon;
		if (dy < 32 && dy >0)
			day = dy;
		if (yr < 9999 && yr  > 0)
			year = yr;
	}
	void Date::setMonth(int mn)
	{
		month = mn;
	}
	void Date::setDay(int dy)
	{
		day = dy;
	}
	void Date::setYear(int yr)
	{
		year = yr;
	}

	int Date::getMonth()
	{
		return month;
	}

	int Date::getDay()
	{
		return day;
	}
	int Date::getYear()
	{
		return year;
	}

	void Date::printDate()
	{
		cout << "The date is (M-D-Y): " << getMonth() << "-" << getDay() << "-" << getYear() << endl;
	}

	bool Date::sameMonth(Date obj)
	{
		if (obj.month == month)
			return true;
		else
			return false;

	}
