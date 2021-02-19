#include<iostream>
#include "Date.h"
using namespace std;



int main()
{
	Date date1;
	int month, day, year;
	
	cout << "Testing the default constructor and the getters.\n";
	cout << "The initialized date is (M-D-Y): " << date1.getMonth() << "-" << date1.getDay() << "-" << date1.getYear()<<endl;
	cout << endl;

	cout << "Please enter a date: (Month Day Year): ";
	cin >> month;
	date1.setMonth(month);
	cin >> day;
	date1.setDay(day);
	cin >> year;
	date1.setYear(year);
	cout << endl;

	cout << "Please enter a second date: (Month Day Year): ";
	cin >> month;
	cin >> day;
	cin >> year;

	Date date2(month, day, year);

	cout << "Printing the two days: \n";
	cout << "The date is  (M-D-Y): ";
	date1.printDate();
	cout << endl;
	cout << "The date is  (M-D-Y): ";
	date2.printDate();
	cout <<endl;

	if (date2.sameMonth(date1)==true)
	{
		cout << "The months are the same";

	}
	else
	{
		cout << "The months are different";
	}
	cout << endl;
}