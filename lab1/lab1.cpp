#include<iostream>
using namespace std;
//
const char world[13] = { 'H','e','l','l','o',',',' ','W','o','r','l','d','!' };
const char* hi = world;
void num1() {
	//	
	cout << hi;
}
void num2() {
	int n;
	cout << "Enter the number of times to print Hello World \n";
	cin >> n;
	int i;
	cout << "for loop\n";
	for(i=0;i<n;i++)
	{
		num1();
		cout<<endl;
	}
	i = 0;
	cout << "while loop\n";
	while (i < n)
	{
		num1();
		cout << endl;
		i++;
	}
	cout << "do while loop\n";
	i=0;
	do{
		num1();
		cout<<endl;
		i++;
	}while(i<n);
}

//num3 - error - conflicting declaration error  - did not compile
/*#include <iostream >
using namespace std;
int main()
{
 int arg1;
 arg1 = -1;
 int x, y, z;
 char myDouble = '5';
 char arg1 = 'A';
 cout << arg1 << endl;
 return 0;
}*/

//num4 - the program compiled and output -1 as the char is inside its own instance
/*#include <iostream >
using namespace std;
int main()
{
	int arg1;
	arg1 = -1;
	{
		char arg1 = 'A';
	}
	cout << arg1 << endl;
	return 0;
}*/

//num5- the char declaration is used 
/*
int main()
{
	int arg1;
	arg1 = -1;
	{
		char arg1 = 'A';
		cout << arg1 << endl;
	}
	return 0;
}

*/

//num6 - by moving the finall line to the top of the program, it will compile

void num7() {
	int n,i;
	double numbers;
	double sum = 0,max=0,min=10000000000;
	double mean,range;
	cout << "Enter the number of integers: ";
	cin >> n;

	for (i = 0;i < n;i++)
	{
		cout << "Enter number " << i + 1 << " out of " << n<<": ";
		cin >> numbers;
		sum += numbers;
		if (numbers > max)
		{
			max = numbers;
		}
		if (numbers < min)
		{
			min = numbers;
		}
	}
	mean = sum / n;
	range = max - min;
	cout << "Mean: "<<mean<<endl;
	cout << "Max: " << max << endl;
	cout << "Min: " << min << endl;
	cout << "Range: " << range << endl;
}

void num8() {
	int N,i=0;
	
	int found = 0;
	int primes[100];
	int x =2,z=0;
	cout << "Enter number of primes you want to print: ";
	cin >> N;
	//i is the number of values
	while (z <= N)
	{
		found = 0;
		
		for (i = 2;i < x;i++)
		{
			if (x % i == 0)
			{
				found = 1;
			}

		}
		if (found == 0)
		{
			primes[z]=x;
			z++;
			
		}
		x++;
	}

	for (x = 0;x < N;x++)
	{
		cout << primes[x]<<endl;
	}
	
}


void num9() {
	int found = 0,N;
	do {
		cout << "Enter integer: ";
		cin >> N;
		N > 0 && N % 5 == 0 ? cout << N / 5 << endl : cout << -1 << endl;
	} while (found!=1);
}

void num10() {
	int found = 0, N;
	do {
		cout << "Enter integer: ";
		cin >> N;
		if (N > 0 && N % 5 == 0)
		{
			cout << N / 5 << endl;
		}
		else
		{
			continue;
		}
	} while (found != 1);
}

void num11() {
	int found = 0, N;
	do {
		cout << "Enter -1 or any negative number to exit\n";
		cout << "Enter integer: ";

		cin >> N;
		if (N > 0 && N % 5 == 0)
		{
			cout << N / 5 << endl;
		}
		else if(N<0)
		{
			break;
		}
		else
		{
			continue;
		}
	} while (found != 1);
}

int main()
{
	//num1();
	//num2();
	//num7();
	num8(); 
	//num9();
	//num10();
	//num11();
}




