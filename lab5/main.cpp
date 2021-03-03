#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
#include "member.h"
using namespace std;

int main() {
	int age;

	cout << "Enter an age : ";
	cin >> age;
	cout << endl;

	Members member;

	vector<Person>::iterator i;

	for (i = member.mem.begin(); i != member.mem.end();i++)
	{
		if ((*i).age > age) {
			cout <<left<<setw(15)<<(*i).code<<setw(15)<<(*i).first_name << setw(15) <<(*i).last_name << setw(15)<<(*i).city << setw(15) << (*i).age << endl;
		}

		
	}



	return 0;
}