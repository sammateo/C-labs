#include"Classes.h"

int GreenMonkey::getRandomNumber(int min, int max)
{
	chrono::system_clock::time_point tp = chrono::system_clock::now();
	default_random_engine randGen(tp.time_since_epoch().count());

	uniform_int_distribution<int> randnum(min, max);
	return randnum(randGen);
}

float GreenMonkey::getRandomNumber(float min, float max)
{
	chrono::system_clock::time_point tp = chrono::system_clock::now();
	default_random_engine randGen(tp.time_since_epoch().count());
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
	next = NULL;
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
	age = getRandomNumber(minAge, maxAge);//generates random age

}

void GreenMonkey::print()
{
	int tabspace = 15, precision = 4;
	string status = alive?"Alive":"Dead";
	string genes = mutant ? "Mutant" : "Normal";
	cout << left << setw(tabspace) << name << setw(tabspace) << age << setw(tabspace)<< setprecision(precision)<< weight << setw(tabspace) << gender << setw(tabspace) << status << setw(tabspace) << genes << setw(tabspace) << injured;

}

void GreenMonkey::eat()
{
	if (!alive)
		return;
	if (!mutant)
		weight += weight * (getRandomNumber(minIncrease, maxIncrease)/100); //increase monkey's weight by 0.1% to 1% of the monkey's weight
		
}

void GreenMonkey::age_me()
{
	if (!alive)
		return;
	age++;
	int mutChance = getRandomNumber(1, 100);
	if (mutChance <= 2)
	{
		mutant = true;
	}

	int deathChance = getRandomNumber(1, 100);

	if (deathChance <= trunc(weight) || injured > 3)
	{
		alive = false;
	}
}

void GreenMonkey::fight(GreenMonkey* other)
{
	float ratio = (weight / other->get_weight()) * 50;
	float check = getRandomNumber(1, 100);
	if (check > ratio)
		injured++;
	else
		other->set_injured(other->get_injured() + 1);
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

GreenMonkey_LinkedList::GreenMonkey_LinkedList()
{
	head = NULL;
	idCount = 0;
}

void GreenMonkey_LinkedList::printList()
{
	GreenMonkey* node = head;
	while (node != NULL)
	{
		node->print();
		cout << endl;
		node = node->get_next();
	}
}

void GreenMonkey_LinkedList::insert_at_start()
{
	GreenMonkey* new_node = new GreenMonkey;
	new_node->set_next(head);
	head = new_node;
	set_idCount();
	new_node->set_ID(idCount);
	//update_id();
}

void GreenMonkey_LinkedList::deleteNode(int pos)
{
	GreenMonkey* temp = head;
	GreenMonkey* prev = NULL;

	if (temp->get_ID() == pos && temp != NULL) {
		head = temp->get_next();
		delete(temp);
		update_id();
		return;
	}
	while (temp->get_next() != NULL && temp->get_ID()!= pos)
	{
		prev = temp;
		temp = temp->get_next();
	}

	if (temp == NULL)
	{
		cout << "Not present in list\n";
		return;
	}

	prev->set_next(temp->get_next());
	delete temp;
	update_id();

}

void GreenMonkey_LinkedList::set_idCount()
{
	idCount++;
}

int GreenMonkey_LinkedList::get_idCount()
{
	return idCount;
}

void GreenMonkey_LinkedList::update_id()
{
	int i = 0;
	GreenMonkey* node = head; 
	while (node != NULL) 
	{
		i++;
		node->set_ID(i); //sets ID to value of i starting from 1
		node = node->get_next();
		
	}
	idCount = i;
}

GreenMonkey* GreenMonkey_LinkedList::get_Head()
{
	return head;
}

GreenMonkey* GreenMonkey_LinkedList::get_Node(int ID)
{
	GreenMonkey* node = head; //start node pointing to head
	while (node != NULL)
	{
		if (node->get_ID() == ID)  //checks for ID
			return node;
		node = node->get_next();
	}
}

vector<string> Habitat::getEmptyCells()
{
	int y,x;
	string xpos,ypos;
	vector<string> location;
	for (x = 0;x < RowCol;x++)
	{
		for (y = 0;y < RowCol;y++) {
			if (this->grid[x][y].get_Head() != NULL) //if not empty move to next iteration
				continue;
			stringstream ss, si;
			si << x; //x position
			si >> xpos;
			ss << y; // position
			ss >> ypos;
			location.push_back(xpos + " : " + ypos);
		}
	}

	/*vector<string>::iterator i;
	for (i = location.begin();i != location.end();i++)
		cout << (*i)<<endl;*/
		
	return location;
}

void Habitat::intialization(int num)//needs to be done for only available squares
{
	int x, y,xcheck,ycheck, found = 0, count = 0;
	string xAvailable, yAvailable,colon;
	vector<string> available = getEmptyCells(); // generate new list of empty cells

	if (num > 100)
		num = 100;
	for (int i = 0;i < num;i++)
	{
		GreenMonkey temp;
		
		found = 0;
		while (found == 0 && count < available.size()) {
			vector<string> available = getEmptyCells(); // generate new list of empty cells
			x = temp.getRandomNumber(0, RowCol - 1); //generate random position
			y = temp.getRandomNumber(0, RowCol - 1); // for linked list
			for (int j = 0;j < available.size();j++) // go through vector of available
			{	
				stringstream ss(available.at(j)), sx, sy;
				while (ss >> xAvailable >> colon >> yAvailable) //read in x and y pos
				{
					sx << xAvailable;
					sx >> xcheck;
					sy << yAvailable;
					sy >> ycheck;
					if (xcheck == x && ycheck == y) {
						grid[x][y].insert_at_start(); // insert new node into grid
						//cout << x << " : " << y;
						count++;
						//cout << count << endl;
						found = 1;
						//cout << "Found\n";
						
					}
				}
			}
		}
		
		
		
	}
}

void Habitat::showGrid()
{
	int x, y;
	int gridspace = 5;
	string display;
	cout << left << setw(gridspace+1)<<"";
	for (int j = 0;j < RowCol;j++) // first row of numbers
		cout << left <<setw(gridspace)<< j;
	cout << endl;
	for (x = 0;x < RowCol;x++) //iterate through x positions
	{
		cout <<left<< setw(gridspace) << x; //first column of numbers
		for (y = 0;y < RowCol;y++) { //iterate through y positions
			if (grid[x][y].get_Head() != NULL) //check if not empty
			{
				cout << left  << '[' << grid[x][y].get_Head()->get_gender() << setw(gridspace-2) << ']'; // print gender of head
			}
				
			else
				cout <<left<< setw(gridspace) << "[ ]";
		}
		cout << endl;
	}
}

void Habitat::invasion(int num)
{
	int x, y, xcheck, ycheck, found = 0;
	string xAvailable, yAvailable, colon;

	for (int i = 0;i < num;i++)
	{
		GreenMonkey temp;
		//cout << i << endl;
		found = 0;
			vector<string> available = getEmptyCells(); // generate new list of empty cells
			x = temp.getRandomNumber(0, RowCol - 1); //generate random position
			y = temp.getRandomNumber(0, RowCol - 1); // for linked list
			for (int j = 0;j < available.size();j++) // go through vector of available
			{
				stringstream ss(available.at(j)), sx, sy;
				ss >> xAvailable >> colon >> yAvailable; //read in x and y pos
				//cout << xAvailable << ":" << yAvailable<<"---->"<<x<<":"<<y << endl;
				sx << xAvailable;
				sx >> xcheck;
				sy << yAvailable;
				sy >> ycheck;

				if (xcheck == x && ycheck == y) { // checks if grid position is empty
					grid[x][y].insert_at_start(); // insert new node into grid
					found = 1; // indicates that position is empty
					//cout << found<< endl;
					break;
				}

				
				
			}
			if (found == 0) { //if position is not empty then impact function  is called
				grid[x][y].insert_at_start();
				//cout << found << endl;
				impact(grid[x][y], grid[x][y].get_Head());
			}



	}
}

void Habitat::impact(GreenMonkey_LinkedList& list, GreenMonkey* obj)
{
	int pos = obj->getRandomNumber(1, list.get_idCount()); //random GreenMonkey in linked list
	if (!list.get_Node(pos)->get_alive()) //if dead then do nothing
		return;

	if (list.get_Node(pos)->get_gender() == obj->get_gender()) //check genders
		obj->fight(list.get_Node(pos));
	else
		list.insert_at_start();

	//if (list.get_Node(pos)->get_gender() == obj->get_gender()) //check genders
	//	cout << list.get_Node(pos)->get_injured() << " " << obj->get_injured()<<endl;
	//else
	//	cout << list.get_Head()->get_age()<<endl;

}

void Habitat::ageAll()
{
	int x, y,i;
	for (x = 0;x < RowCol;x++)
	{
		for (y = 0;y < RowCol;y++)
		{
			if (grid[x][y].get_Head() == NULL) //skips empty cells
				continue;
			else {
				//grid[x][y].update_id();
				for (i = 0;i < grid[x][y].get_idCount();i++)
				{
					grid[x][y].get_Node(i+1)->age_me(); // getNode searches for idnumbers which start at 1 and not 0
				}
			}
			
		}
	}
}

void Habitat::feedAll()
{
	int x, y, i;
	for (x = 0;x < RowCol;x++)
	{
		for (y = 0;y < RowCol;y++)
		{
			if (grid[x][y].get_Head() == NULL) //skips empty cells
				continue;
			else {
				//grid[x][y].update_id();
				for (i = 0;i < grid[x][y].get_idCount();i++)
				{
					grid[x][y].get_Node(i + 1)->eat(); // getNode searches for idnumbers which start at 1 and not 0
				}
			}

		}
	}
}

void Habitat::printAll()
{
	int x, y;
	int tabspace = 15, precision = 4;
	for (x = 0;x < RowCol;x++)
	{
		for (y = 0;y < RowCol;y++)
		{
			if (grid[x][y].get_Head() == NULL) //checks for empty cells
				continue;
			cout << "Cell->" << x << ":" << y<<" has "<<grid[x][y].get_idCount()<<"  monkeys"<<endl;
			
			cout << left << setw(tabspace) <<"Name"<< setw(tabspace) << "Age"<< setw(tabspace)<< "Weight" << setw(tabspace) << "Gender" << setw(tabspace) << "Status" << setw(tabspace) << "Genes" << setw(tabspace) << "Injured"<<endl;
			
			for (int i = 0;i < 100;i++)
				cout << "=";
			
			cout << endl;
			
			grid[x][y].printList();
			
			cout << endl;
		}
	}
}

void Habitat::getStatistics()
{
	int space = 80, precision =3;
	int x, y, i;
	
	int total = 0, mTotal = 0, fTotal = 0, aTotal = 0,dTotal = 0;
	int muttotal = 0, normtotal = 0;
	float avgWeight = 0, avgAge = 0, avgInjury = 0;

	
	for (x = 0;x < RowCol;x++)
	{
		for (y = 0;y < RowCol;y++)
		{
			if (grid[x][y].get_Head() == NULL) 
				continue; //if cell is empty, skip to next cell
			else {
				grid[x][y].update_id();
				for (i = 1;i <= grid[x][y].get_idCount();i++)//loop start at one so you can get IDs
				{
					total++;
					if (grid[x][y].get_Node(i)->get_gender() == 'M') // check gender of each monkey
						mTotal++;
					else
						fTotal++;

					if (grid[x][y].get_Node(i)->get_alive()) // check if monkey is alive
					{
						avgWeight += grid[x][y].get_Node(i)->get_weight();
						avgAge += grid[x][y].get_Node(i)->get_age();
						avgInjury += grid[x][y].get_Node(i)->get_injured();
						aTotal++;
					}
					else
						dTotal++;

					if (grid[x][y].get_Node(i)->get_mutant()) // check if monkey is mutant
						muttotal++;
					else
						normtotal++;



				}
			}
			
			


		}
	}

	avgWeight = avgWeight / aTotal;
	avgAge = avgAge / aTotal;
	avgInjury = avgInjury / aTotal;

	for (i = 0;i < 100;i++)
		cout << "=";
	cout << endl;
	cout << left << setw(space) << "Description" << setw(space) << "Value" << endl;
	for (i = 0;i < 100;i++)
		cout << "=";
	cout << endl;

	cout << left << setw(space) << "Total monkeys in the habitat" << total << endl;
	cout << left << setw(space) << "Total male monkeys in the habitat" << mTotal << endl;
	cout << left << setw(space) << "Total female monkeys in the habitat" << fTotal << endl;
	cout << left << setw(space) << "Total alive monkeys in the habitat" << aTotal << endl;
	cout << left << setw(space) << "Total dead monkeys in the habitat" << dTotal << endl;
	cout << left << setw(space) << "Total mutant monkeys in the habitat" << muttotal << endl;
	cout << left << setw(space) << "Total normal monkeys in the habitat" << normtotal << endl;
	cout << left << setw(space) << setprecision(precision) << "Average weight of all alive monkeys in the habitat" << avgWeight << endl;
	cout << left << setw(space) << setprecision(precision) << "Average age of all alive monkeys in the habitat" << avgAge << endl;
	cout << left << setw(space) << setprecision(precision) << "Average injuries of all alive monkeys in the habitat" << avgInjury << endl;

	for (i = 0;i < 100;i++)
		cout << "=";
	cout << endl;


}
