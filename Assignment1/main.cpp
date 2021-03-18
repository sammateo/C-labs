#include <iostream>
#include<vector>
#include <string>
#include <random>
#include <chrono>
#include <fstream>
#include<iomanip>
#include "green_monkey.h"
using namespace std;
#define troopsize 50

vector<GreenMonkey> create_troop(int size)
{

	//using namespace std::this_thread; // sleep_for, sleep_until
	//using namespace std::chrono; // nanoseconds, system_clock, seconds
	vector<GreenMonkey> troop;
	int i;
	for (i =0;i<size;i++)
	{
		GreenMonkey monkey;
		troop.push_back(monkey);
		//sleep_for(seconds(1));
	}
	return troop;
}

void age_troop(vector<GreenMonkey> *obj)
{
	vector<GreenMonkey>::iterator i;
	for (i = obj->begin();i != obj->end();i++)
	{
		(*i).age_me();
		
	}
}

void feed_troop(vector<GreenMonkey>* obj)
{
	vector<GreenMonkey>::iterator i;
	for (i = obj->begin();i != obj->end();i++)
	{
		if ((*i).get_alive()) // only monkeys that are alive can eat
			(*i).eat();
	}
}

void engage_troop(vector<GreenMonkey>* obj)
{
	default_random_engine randGen(time(NULL));
	uniform_int_distribution<int> randnum(1, obj->size());
	int first = randnum(randGen);
	int second = randnum(randGen);
	int firstage;
	int secondage;
	char firstgen;
	char secondgen;
	int count = 0;
	int fighter = 1;

	while (first == second)
	{
		first = randnum(randGen);
		second = randnum(randGen);
	}

	GreenMonkey monk1;
	GreenMonkey monk2;
	vector<GreenMonkey>::iterator i;
	
	for (i = obj->begin();i != obj->end();i++)
	{
		count++;
		if (count == first)
		{
			
			monk1.set_age((*i).get_age());
			monk1.set_gender((*i).get_gender());
			monk1.set_alive((*i).get_alive());
			monk1.set_ID((*i).get_ID());
			monk1.set_injured((*i).get_injured());
			monk1.set_mutant((*i).get_mutant());
			monk1.set_name((*i).get_name());
			monk1.set_next((*i).get_next());
			monk1.set_weight((*i).get_weight());
			firstgen = (*i).get_gender();
			firstage = (*i).get_age();
			
		}

		if (count == second)
		{
			
			monk2.set_age((*i).get_age());
			monk2.set_gender((*i).get_gender());
			monk2.set_alive((*i).get_alive());
			monk2.set_ID((*i).get_ID());
			monk2.set_injured((*i).get_injured());
			monk2.set_mutant((*i).get_mutant());
			monk2.set_name((*i).get_name());
			monk2.set_next((*i).get_next());
			monk2.set_weight((*i).get_weight());
			secondgen = (*i).get_gender();
			secondage = (*i).get_age();
			
		}
	}


	if (monk1.get_mutant() || monk2.get_mutant())//If one or both of the picked monkeys are a mutant then they will not mate nor will they fight.
		return;
	if (!monk1.get_alive() || !monk2.get_alive())//If dead then they cant fight or reproduce
		return;
	if (firstgen == secondgen)
	{
		if (firstage < secondage)
		{
			monk1.fight(monk2);
		}
		else if(firstage > secondage){
			monk2.fight(monk1);
		}
		else {
			uniform_int_distribution<int> randfight(1,50);
			fighter = randfight(randGen);
			if (fighter >25) //choosing who starts fight at random
			{
				monk1.fight(monk2);
			}
			else {
				monk2.fight(monk1);
			}
		}
		
	}
	else
	{
		GreenMonkey child;
		child.set_age(0);
		obj->push_back(child);
	}
	/*
	cout << endl << endl;
	cout << "Injured: "<< monk1.get_injured()<<endl;
	cout << "Name: " << monk1.get_name() << endl;
	cout << "Gender: " << monk1.get_gender() << endl;
	cout << endl << endl;
	cout << "Injured: " << monk2.get_injured() << endl;
	cout << "Name: " << monk2.get_name() << endl;
	cout << "Gender: " << monk2.get_gender() << endl;
	cout << endl << endl;
	*/
	
	//put for loop here but instead add the values that changed
	count = 0;
	for (i = obj->begin();i != obj->end();i++)
	{
		count++;
		if (count == first)
		{

			(*i).set_age(monk1.get_age());
			(*i).set_gender(monk1.get_gender());
			(*i).set_alive(monk1.get_alive());
			(*i).set_ID(monk1.get_ID());
			(*i).set_injured(monk1.get_injured());
			(*i).set_mutant(monk1.get_mutant());
			(*i).set_name(monk1.get_name());
			(*i).set_next(monk1.get_next());
			(*i).set_weight(monk1.get_weight());
			//firstgen = (*i).get_gender();
			//firstage = (*i).get_age();

		}

		if (count == second)
		{

			(*i).set_age(monk2.get_age());
			(*i).set_gender(monk2.get_gender());
			(*i).set_alive(monk2.get_alive());
			(*i).set_ID(monk2.get_ID());
			(*i).set_injured(monk2.get_injured());
			(*i).set_mutant(monk2.get_mutant());
			(*i).set_name(monk2.get_name());
			(*i).set_next(monk2.get_next());
			(*i).set_weight(monk2.get_weight());

		}
	}

}

void statistics_on_troop(vector<GreenMonkey>* obj)
{
	int alivemales = 0;
	int alivefemales = 0;
	int mutants = 0;
	int babies = 0;
	int deadmales = 0;
	int deadfemales = 0;
	float avgage = 0;
	float avgweight = 0;
	vector<GreenMonkey>::iterator i;

	for (i = obj->begin();i != obj->end();i++)
	{
		if ((*i).get_gender() == 'M') //checking for male gender
		{
			if ((*i).get_alive()) //checking whether alive or dead
				alivemales++;
			else
				deadmales++;  
		}
		else if((*i).get_gender() == 'F') //checking for female gender
		{
			if ((*i).get_alive())
				alivefemales++;
			else
				deadfemales++;
		}
		if ((*i).get_mutant())
			mutants++;

		if ((*i).get_age() <= 3)
			babies++;

		avgage += (*i).get_age();
		avgweight += (*i).get_weight();

	}

	avgage = avgage / obj->size();
	avgweight = avgweight / obj->size();
	cout << "---------------------------------------------------------" << endl;
	cout << right << setw(30) << "STATISTICS" << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << left << setw(30) << "Alive males:" << alivemales << endl;
	cout << left << setw(30) << "Alive females:" << alivefemales << endl;
	cout << left << setw(30) << "Mutants: " << mutants << endl;
	cout << left << setw(30) << "Less than 4 years old: " <<babies<< endl;
	cout << left << setw(30) << "Dead males:" << deadmales << endl;
	cout << left << setw(30) << "Dead females:" << deadfemales << endl;
	cout << left << setw(30) << "Average Age: " << avgage << endl;
	cout << left << setw(30) << "Average Weight: " <<setprecision(3)<< avgweight << endl;
}

int main() {
	//int troopsize =50;

	vector<GreenMonkey> monkeys;
	monkeys = create_troop(troopsize);

	statistics_on_troop(&monkeys);

	for(int i=0;i<10;i++) //age the troop 10 times
		age_troop(&monkeys);

	for (int i = 0;i < 6;i++) //feed the troop 6 times
		feed_troop(&monkeys);
	
	for (int i = 0;i < 8;i++) //engage the troop 8 times
		engage_troop(&monkeys);
	cout << endl;
	cout << "---------------------------------------------------------" << endl;
	cout << "This troop of "<<troopsize<<" monkeys were \naged 10 times \nfed 6 times  \nengaged 8 times" << endl;
	cout << "---------------------------------------------------------" << endl; 
	cout << endl;
	statistics_on_troop(&monkeys);

	/*for (int i = 0;i < monkeys.size();i++)
		monkeys[i].print();*/

		
}