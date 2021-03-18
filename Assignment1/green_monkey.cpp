#include"green_monkey.h"

int GreenMonkey::getRandomNumber(int min, int max)
{
	chrono::system_clock::time_point tp = chrono::system_clock::now();
	default_random_engine randGen(tp.time_since_epoch().count());
	//default_random_engine randGen(time(NULL));

	uniform_int_distribution<int> randnum(min, max);
	return randnum(randGen);
}

float GreenMonkey::getRandomNumber(float min, float max)
{
	chrono::system_clock::time_point tp = chrono::system_clock::now();
	default_random_engine randGen(tp.time_since_epoch().count());
	//default_random_engine randGen(time(NULL));
	uniform_real_distribution<float> randnum(min, max);
	return randnum(randGen);
}

GreenMonkey::GreenMonkey()
{
	int filelines = 0, linecount = 0;
	int i = 0;
	gender = 'M';
	ifstream namefile;
	name;
	weight;
	alive = true;
	mutant = false;
	injured = 0;
	GreenMonkey* next = NULL;
	int countlines = 0;

	if (getRandomNumber(1, 100) > 50) // 50% chance of male or female
		gender = 'M';
	else
		gender = 'F';

	if (gender == 'M') //opens the file for calculation of number of lines
		namefile.open("M_names.txt");
	else
		namefile.open("F_names.txt");

	if (!namefile.is_open())
	{
		cerr << "Error opening name file" << endl;
		exit(1);
	}
	
	while (getline(namefile, name))//counts the number of lines in the file
	{
		countlines++;
	}
	
	namefile.close(); //closes the file for reopening

	if (gender == 'M')//opens the file to get random name
		namefile.open("M_names.txt");
	else
		namefile.open("F_names.txt");

	if (!namefile.is_open())
	{
		cerr << "Error opening name file" << endl;
		exit(1);
	}
	//
	linecount = getRandomNumber(1, countlines);//generate number between 1 and 51 and store randomly generated number

	while (!namefile.eof() && filelines != linecount) //checks for end of file or if the randomly generated line number has been reached
	{
		namefile >> name; //reads the names from the file
		filelines++; //increments to keep track of current line
	}
	namefile.close(); // close the names file

	 //generates random weight between min and max weight
	weight = getRandomNumber(minWeight, maxWeight); //stores in weight variable
	age= getRandomNumber(minAge, maxAge);//generates random age
	
}

void GreenMonkey::print()
{
	//cout <<left<<setw(20)<< "ID:"<<ID << endl;
	cout << left << setw(20) << "Name: " << name << endl;
	cout << left << setw(20) << "Gender: " << gender << endl;
	cout << left << setw(20) << "Age: " << age << endl;
	cout << left << setw(20) << "Weight: " << weight << endl;
	if(alive)
		cout << left << setw(20) << "Alive" << endl;
	else
		cout << left << setw(20) << "Dead" << endl;
	if(mutant)
		cout << left << setw(20) << "Mutant" << endl;
	else
		cout << left << setw(20) << "Normal"<< endl;
	
	cout << left << setw(20) << "Injured: " << injured << endl;

}

void GreenMonkey::eat()
{
	if (!mutant)
		weight += weight*getRandomNumber(minIncrease, maxIncrease);
}

void GreenMonkey::age_me()
{
	age++;
	int mutChance = getRandomNumber(1, 100);
	if (mutChance <= 2)
	{
		mutant = true;
	}

	int deathChance = getRandomNumber(1, 100);
	
	if (deathChance <= trunc(weight)||injured>3)
	{
		alive = false;
	}
}

void GreenMonkey::fight(GreenMonkey &other)
{
	float ratio = (weight / other.get_weight())*50;
	float check = getRandomNumber(1, 100);
	if (check > ratio)
		injured++;
	else
		other.set_injured(other.get_injured() + 1);
}

float GreenMonkey::get_weight()
{
	return weight;
}

short int GreenMonkey::get_injured()
{
	return injured;
}

void GreenMonkey::set_injured(short int inj)
{
	injured = inj;
}

void GreenMonkey::set_weight(float wei)
{
	weight = wei;
}

void GreenMonkey::set_age(short int old)
{
	age = old;
}
void GreenMonkey::set_name(string nam)
{
	name = nam;
}

void GreenMonkey::set_gender(char gen)
{
	gender = gen;
}

void GreenMonkey::set_alive(bool al)
{
	alive = al;
}

void GreenMonkey::set_mutant(bool mut)
{
	mutant = mut;
}

void GreenMonkey::set_ID(int i)
{
	ID = i;
}

short int GreenMonkey::get_age()
{
	return age;
}

string GreenMonkey::get_name()
{
	return name;
}

char GreenMonkey::get_gender()
{
	return gender;
}

bool GreenMonkey::get_alive()
{
	return alive;
}

bool GreenMonkey::get_mutant()
{
	return mutant;
}

int GreenMonkey::get_ID()
{
	return ID;
}

void GreenMonkey::set_next(GreenMonkey* another)
{
	next = another;
}

GreenMonkey* GreenMonkey::get_next()
{
	return next;
}

