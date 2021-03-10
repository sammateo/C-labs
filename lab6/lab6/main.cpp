#include<iostream>
using namespace std;

int* findMax(int data[], int n)
{
	int* max = data;
	int i;
	for (i = 1;i < n; i++)
	{
		if (*max < *(max + i))
		{
			*max = *(max + i);
		}
	}
	return max;
}

void num1()
{
	const int n = 5;
	int i;
	int* large;
	int max;
	int array[n];
	cout << "Enter 5 integers: ";
	cout << endl;
	for (i = 0;i < n;i++)
	{
		cin >> array[i];
	}
	cout << endl;
	large = findMax(array, n);
	max = *large;
	cout << "Largest: " << *large << endl;
}

void num2()
{
	const int n = 5;
	int array[n];
	int i;
	int* ptr = array;
	cout << "Enter 5 integers: ";
	cout << endl;
	for (i = 0;i < n;i++)
	{

		cin >> *(ptr + i);
		cout << endl;
	}

	cout << endl;

	for (i = 0;i < n;i++)
	{
		cout << *(ptr + i);
	}
}

void num3()
{
	int num;
	int* ptr = &num;

	cout << "Enter number: ";
	cin >> *ptr;
	cout << endl;
	cout << *ptr;
}

void love_me() 
{

	/*
	Answer:
	I hate you
	I hate you 
	I love you tooo!
	*/
	char c;
	cout << endl << "Do you love me, answer y or n?: ";
	c = ' ';
	while (c != 'y' && c != 'n') {
		cin >> c;
		if (c != 'n' && c != 'y')
			cout << endl << "Invalid reply, try again: ";
	}
	if (c == 'n') {
		cout << endl << "I hate you ";
		love_me();
	}
	cout << endl << "I love you too!";
}


void num5()
{
	float sum = 0.0f;
	int n;
	cout << "Enter n: ";
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		sum += 1.0 / i;
	}
	cout << sum << endl;
}

char* shift_right(char vals[],char temps[],int sizes,int num)
{
	//abcdef
	//fabcde
	char* ptrs = vals;
	char* tempptr = temps;
	int i = 0;
	while (i < num)
	{
		for (int x = 0;x < sizes;x++)
		{
			*(tempptr+x)=*(ptrs + x);
		}
		*(ptrs) = *(tempptr + sizes-1);
		for (int x = 0;x < sizes;x++)
		{
			*(ptrs + x + 1) = *(tempptr + x);
		}

		i++;
	}
	
	return ptrs;
}

void num6()
{
	const int size = 6;
	char* ptr;
	char val[] = { 'a','b','c','d','e','f' };
	char temp[size];
	ptr = val;
	for (int i = 0; i < size; i++) {
		cout << *(ptr + i);
	}
	ptr = shift_right(val, temp, size, 2);
	cout << endl;
	for (int i = 0; i < size; i++) {
		cout << *(ptr + i);
	}
	return;
}

int main() {

	//num1();
	//num2();

	num5();


}