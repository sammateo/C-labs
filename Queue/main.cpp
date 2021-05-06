#include<iostream>
#include<string>
#include<queue>
using namespace std;

void printDashes() {
    int dashsize = 50,i;
    for (i = 0;i < dashsize;i++) {
        cout << "=";
    }
    cout << endl;
}

void addTask(queue<string>& queue) {

    string newItem;
    cin.ignore();
    cout << "Task: ";
    getline(cin,newItem);
    cout << endl;
    queue.push(newItem);
    cout << newItem << " has been added to queue" << endl;
}

void removeTask(queue<string>& queue) {
    if (queue.size() < 1)
        cout << "Queue empty" << endl;
    else
    {
        cout << queue.front() << " has been removed from the queue" << endl;
        queue.pop();

        if (queue.size() < 1)
            cout << "You've finished all your tasks!" << endl;
    }
        
}

void printQueue(queue<string> queue) {
    int i = 1;
    while (!queue.empty())
    {
        cout<<i<<"\t"<<queue.front() <<endl;
        i++;
        queue.pop();
    }
    cout << endl;
}

void menu(queue<string> &queue) {
    int choice;
    int dashsize = 50,i ;
    cout << endl;
    printDashes();
    cout << "MENU" << endl;
    printDashes();
    cout << "If you would like to add a new item to the queue enter 1"<<endl;
    cout << "If you would like to dequeue press 2" << endl;
    cout << "If you would like to print the contents of the queue enter 3 " << endl;
    cout << "If you would like to quit enter 4 " << endl;
    cout << "Choice: ";
    cin >> choice;
    cout << endl;

    if (choice == 1) {

        addTask(queue);
        menu(queue);
    }
    else if (choice == 2) {
        removeTask(queue);
        menu(queue);
    }
    else if (choice == 3) {
        if (queue.size() == 0)
            cout << "No tasks exist" << endl;
        else {
            cout << "Current Tasks: " << endl;
            printQueue(queue);
        }
        menu(queue);
    }
    else if (choice == 4) {
        return;
    }

    else {
        cout << "Invalid choice" << endl;
        menu(queue);
    }
}

int main() {

    cout << "Daily Planner" << endl;
    cout << "Add tasks to a queue and perform them in the order you add them." << endl;
    cout << "When completed, remove it from the queue and you can move on to the next" << endl;
    queue<string> myQueue;
    menu(myQueue);
}