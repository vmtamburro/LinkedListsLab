#include <iostream>
#include "List.h"

using namespace std;

int main()
{
    LinkedList<int> newList;

    cout<<"Creating a Linked List: "<<endl;
    try
    {
        for(int i = 1; i <= 20; i++)
        {
            newList.appendNode(i);
            i = i + 1;
        }

        newList.displayList();
    }
    catch(...)
    {
        cout<<"Error Creating Linked List"<<endl;
    }


    cout<< "Inserting the number 4. "<<endl;

    try
    {
        newList.insertNode(4);
        newList.displayList();
    }
    catch(...)
    {
        cout<<"Error Inserting Node"<<endl;
    }


    try
    {
       cout<< "The number 5 appears at subscript "
        << newList.searchList(5)<<"." <<endl;

    }
    catch(...)
    {
        cout<<"Error in search function"<<endl;
    }

    cout<< "Testing reversal"<<endl;

    try
    {
        newList.reverseList();
        newList.displayList();
    }
    catch(...)
    {
        cout<< "Error in reverseList function"<<endl;
    }

    cout<<"Testing overloaded [] operator"<<endl;
    try
    {
        newList[0]=100;
        newList.displayList();
    }
    catch(...)
    {
        cout<<"Error in overloaded [] operator"<<endl;
    }

}
