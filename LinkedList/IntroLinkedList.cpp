#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }

public:
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
};

int main()
{
    Node *y = new Node(1, nullptr);
    cout << y << endl;
    cout << y->next << endl;
    cout << y->data << endl;
    Node *z = new Node(2);
    y->next = z;
    cout << y->next << endl;
    cout << z->data << endl;
    return 0;
}