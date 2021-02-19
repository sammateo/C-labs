// This program computes the average, the highest, and
// the lowest scores of a test for a class.
// All the scores are stored in a data file (one score per line)
// called "lab2_p3.dat".


#include < iostream >
#include < fstream >

using namespace std;


// declare function "ProcessTests" here

void ProcessTests(ifstream &file, float& high, float& low, float& avg);

int main()
{
    float     highest,         //the highest score in the file 
        lowest,          //the lowest score in the file
        average;         //the average score in the file
    ifstream  datafile;        //an input file stream object

    //open the data file
    datafile.open("lab2_p3.txt");

    // fill in the activation statement for function "ProcessTests" here

    ProcessTests(datafile,highest,lowest,average);

   cout << "The highest score is " << highest << endl;
    cout << "The lowest score is " << lowest << endl;
    cout << "The average score is " << average << endl;

    datafile.close();
    return 0;
}


// define the function here

// ProcessTests
// This function finds the highest, lowest, and
// the average test score

void ProcessTests(ifstream &file,float& high,float& low, float& avg)
{
    float num,max=-1,min=1000,sum=0;
    int i=0;

    int count = 0;
    while (file.eof() == 0)
    {
        file >> num;
        sum += num;
        count++;
        if (num > max)
        {
            max = num;
        }

        if (num < min)
        {
            min = num;
        }
        //cout << num << endl;
    }
    avg = sum / count;
    high = max;
    low = min;
 //  file.close();

}