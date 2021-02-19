
 //This program draws a house by printing characters
 //to the screen.

 #include <iostream>

 using namespace std;
 
 // declare all function prototypes here
 void PrintParallel();
 void PrintIntersecting();
 void PrintHorizontal();
 void PrintCircle();

 int main1()
 {
     PrintIntersecting();      //draw the roof
     PrintHorizontal();        //draw the base of the roof
     PrintParallel();          //draw the sides of the house
     PrintHorizontal();        //draw the base of the house 



     PrintCircle();
     PrintHorizontal();        //draw the base of the roof
     PrintParallel();          //draw the sides of the house
     PrintHorizontal();        //draw the base of the house 
     PrintIntersecting();      //draw the roof
     return 0;
 }


 // function : PrintParallel()
 // Print out two parallel lines

 void PrintParallel()
 {
     cout << "|        |" << endl;
     cout << "|        |" << endl;
     cout << "|        |" << endl;
     cout << "|        |" << endl;
     cout << "|        |" << endl;
     return;
 }


 // function : PrintIntersecting()
 // Print out two intersecting lines

 void PrintIntersecting()
 {
     cout << "     $     " << endl;
     cout << "    $ $    " << endl;
     cout << "   $   $   " << endl;
     cout << "  $     $  " << endl;
     cout << " $       $ " << endl;
     return;
 }


 // function : PrintHorizontal()
 // Print out a horizontal line

void PrintHorizontal()
 {
     cout << "-----------" << endl;
     return;
 }

void PrintCircle()
{
    cout << "       *" << endl;
    cout << "   *      *" << endl;
    cout << "*             *" << endl;
    cout << "*             *" << endl;
    cout << "*             *" << endl;
    cout << "    *     *" << endl;
    cout << "       *" << endl;
}