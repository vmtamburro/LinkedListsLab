#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <iostream>
using namespace std;

template <class T>
class ListNode
{
public:
    T value;
    ListNode<T> *next;
    ListNode(T NodeValue)
    {
        value = NodeValue;
        next = nullptr;
    }
};

template<class T>
class LinkedList
{
    ListNode<T> *head; //head pointer

public:
    LinkedList()
    { head = nullptr; }

    ~LinkedList();
\
    void appendNode(T);
    void insertNode(T);
    void deleteNode(T);
    void displayList() const;

    void reverseList();
    int searchList(T);
    T &operator[](const int &);
    void subscriptError();
};


template<class T>
void LinkedList<T>::appendNode(T newValue)
{
    ListNode<T> *newNode; //point to a new node
    ListNode<T> *nodePtr; //move through the list.

    //Allocate a new node and store newValue there.
    newNode = new ListNode<T>(newValue);

    if(!head)
        head = newNode;
    else
    {
        nodePtr = head;

        //find the last node in the list. Last one would point to null?
        while(nodePtr->next)
            nodePtr = nodePtr->next;

        nodePtr->next = newNode;
    }
}

template<class T>
void LinkedList<T>::displayList() const
{
    ListNode<T> *nodePtr;

    nodePtr = head;

    while(nodePtr)
    {
        cout<< nodePtr->value <<" ";
        nodePtr = nodePtr->next;
    }
    cout<<endl;
}

template<class T>
void LinkedList<T>::insertNode(T newValue)
{
    ListNode<T> *newNode;
    ListNode<T> *nodePtr; //to move through the node
    ListNode<T> *previousNode = nullptr;

    newNode = new ListNode<T>(newValue);

    if(!head)
    {
        head = newNode;
        newNode->next = nullptr;
    }
    else
    {
        nodePtr = head;
        previousNode = nullptr;

        while(nodePtr != nullptr && nodePtr->value < newValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
    }

    //If it is to be first on the list, insert it before all other nodes
    if(previousNode == nullptr)
    {
        head = newNode;
        newNode->next = nodePtr;
    }
    else
    {
        previousNode->next = newNode;
        newNode->next = nodePtr;
    }
}

template<class T>
void LinkedList<T>::deleteNode(T searchValue)
{
    ListNode<T> *nodePtr;
    ListNode<T> *previousNode;

    if(!head)
        return;

    if(head->value == searchValue)
    {
        nodePtr = head->next;
        delete head;
        head = nodePtr;
    }
    else
    {
        nodePtr = head;

        while(nodePtr != nullptr && nodePtr->value != searchValue)
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        if(nodePtr)
        {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }

}

template<class T>
void LinkedList<T>::reverseList()
{
    ListNode<T> *nodePtr;
    ListNode<T> *nextNode;
    ListNode<T> *previousNode = nullptr;

    nodePtr = head;

    while(nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        nodePtr->next = previousNode;
        previousNode = nodePtr;
        nodePtr = nextNode;
    }

    head = previousNode;

}

template<class T>
int LinkedList<T>::searchList(T searchVal)
{
    ListNode<T> *nodePtr;
    //Similar to delete node with a return value
    int index = 0;
    nodePtr = head;
    while(nodePtr != nullptr)
    {
        if(nodePtr->value == searchVal)
            return index;
        index++;
        nodePtr = nodePtr->next;
    }

    return -1;
}

template<class T>
T &LinkedList<T>::operator[](const int &sub)
{
    ListNode<T> *nodePtr;
    nodePtr = head;

    for(int i = 0; i < sub; i++)
    {
        if(nodePtr != nullptr)
            nodePtr = nodePtr->next;
        else
            subscriptError();
    }

    return nodePtr->value;
}

template<class T>
void LinkedList<T>::subscriptError()
{
    cout<< "Invalid Subscript. Out of Range."<<endl;
}


template<class T>
LinkedList<T>::~LinkedList()
{
    ListNode<T> *nodePtr;
    ListNode<T> *nextNode;

    nodePtr = head;

    while(nodePtr != nullptr)
    {
        nextNode = nodePtr->next;
        delete nodePtr;

        nodePtr = nextNode;
    }
}

#endif // LIST_H_INCLUDED
