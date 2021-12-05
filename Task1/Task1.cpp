#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    int x;
    Node* Next;
};

template <typename T>
class List
{
    Node* Head, * Tail; 
public:
    List() :Head(NULL), Tail(NULL) {}; 
    ~List(); 
    T Push(int x); 
    T Peek();
    T Pop();
    friend ostream& operator << (ostream& stream, const List& a); 
};

template <typename T>
List<T>::~List() 
{
    Node* temp = Head; 
    while (temp != 0) 
    {
        temp = Head->Next; 
        delete Head;  
        Head = temp; 
    }
}

void List<void>::Push(int x)
{
    Node* temp = new Node; 
    temp->x = x;
    temp->Next = NULL;

    if (Head != NULL)
    {
        Tail->Next = temp;
        Tail = temp;
    }
    else Head = Tail = temp;
}
ostream& operator << (ostream& stream, const List<void>& a)
{
    Node* temp = a.Head;
    while (temp != NULL)
    {
        stream << temp->x << "";
        temp = temp->Next;
    }
    return stream << endl;
}
void List<void>::Peek()
{
    cout << Head->x;
}
void List<void>::Pop()
{
    Head = Head->Next;
}
void main()
{
    List<void> lst;
    int size, count;
    cout << "Size = ";
    cin >> size;
    for (int i = 1; i <= size; i++)
    {
        cout << "Count " << i << "/" << size << " = ";
        cin >> count;
        lst.Push(count);
    }
    cout << lst;
    lst.Peek();
    lst.Pop();
    cout << endl;
    cout << lst;
}

