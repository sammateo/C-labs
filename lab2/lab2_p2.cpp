// This program prints a series of triangles.
// Both the height and the character used to draw each 
// triangle are supplied by the user.

#include <iostream>

using namespace std;


// declare the function prototype for "DrawTriangle" here
void DrawTriangle(int h, char c);

int main2()
{
    //local variables
    int height;          //the height of the triangle
    char character;      //the character used in drawing the triangle
    int stop = 1;
   /* cout << "Enter the height of the triangle. ";
    cout << "Enter the end-of-file character to quit. " << endl;
    cin >> height;
    cout << "Enter the character used to draw the triangle. ";
    cout << "Enter the end-of-file character to quit. " << endl;
    cin >> character;
    DrawTriangle(height, character);
    //loop to continue processing triangles until the user
    //type the end-of-file character.*/
    while ( stop > 0 )
    {
        cout << endl << endl;


        //fill in the activation statement for DrawTriangle here



        cout << "Enter the height of the triangle. ";
        cout << "Enter the end-of-file character to quit. " << endl;
        cin >> height;
        cout << "Enter the character used to draw the triangle. ";
        cout << "Enter the end-of-file character to quit. " << endl;
        cin >> character;
        cout << endl << endl;
        DrawTriangle(height, character);
        cout << "Should we draw a next one? Negative number to stop. Positive number to contnue. "<< endl;
        cin >> stop;
            
    }   //end of while loop
    return 0;
}

//fill in the function definition here 
//Hint:  Use a nested loop to draw the triangle
void DrawTriangle(int h, char c)
{
    int i,x;
    for (i = 0;i < h;i++)
    {
        for (x = 0;x <= i;x++)
        {
            cout << c;
        }
        cout << endl;
    }

}