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

Node *convertArr2LL(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = mover->next;
    }
    return head;
}

void checkIfPresent(Node *head, int val)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->data == val)
        {
            cout << "Found the Element" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Not Found" << endl;
    return;
}

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        if (temp->next == nullptr)
        {
            cout << temp->data;
            break;
        }
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << endl;
}

// Deletion and Insertion
Node *deleteAtHead(Node *head);
Node *deleteAtTail(Node *head);

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

    vector<int> arr = {2, 5, 8, 7};
    Node *head = convertArr2LL(arr);
    printLL(head);
    checkIfPresent(head, 7);
    return 0;
}

Node *deleteAtHead(Node *head)
{
    if (head == NULL)
        return head;
    Node *temp = head;
    head = head->next;
    delete temp;
    return head;
}