#pragma once
#ifndef MEMBER_H
#define MEMBER_H
#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;

class Person {
private:
	

public:
	int code;
	string first_name;
	string last_name;
	string city;
	int age;

	Person(int cod, string first, string last, string cit, int ag) {
		code = cod;
		first_name = first;
		last_name = last;
		city = cit;
		age = ag;
	}
};

class Members {
private:
	
	

public:
	int code;
	string first_name;
	string last_name;
	string city;
	int age;
	string header;

	vector<Person> mem;
	Members() {

		ifstream readit("members.txt");
		getline(readit, header);
		while (readit >> code >> first_name >> last_name >> city >> age)
		{
			Person info(code, first_name, last_name, city, age);
			mem.push_back(info);
		}
		
	}
};



#endif // !

