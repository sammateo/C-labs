#ifndef DATE_H
#define DATE_H


class Date {
private:
	int month, day, year;

public:

	Date();

	Date(int mon, int dy, int yr);

	void setMonth(int mn);
	
	void setDay(int dy);
	
	void setYear(int yr);


	int getMonth();


	int getDay();

	int getYear();


	void printDate();


	bool sameMonth(Date obj);

};

#endif