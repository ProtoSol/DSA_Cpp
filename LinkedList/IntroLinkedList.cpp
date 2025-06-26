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

// Deletion
Node *deleteAtHead(Node *head);
Node *deleteAtTail(Node *head);
Node *deleteAtKth(Node *head, int k);
Node *deleteAtValue(Node *head, int value);

// Insertion
Node *insertAtHead(Node *head, int data);
Node *insertAtTail(Node *head, int data);
Node *insertAtKth(Node *head, int data, int k);
Node *InsertAtValue(Node *head, int data, int value);

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

Node *deleteAtTail(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *temp = head;
    while (temp->next->next)
    {
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node *deleteAtKth(Node *head, int k)
{
    if (head == NULL)
        return head;
    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *curr = head;
    for (int i = 1; curr != NULL && i < k - 1; i++)
    {
        curr = curr->next;
    }
    // Checks for out of bound.
    if (curr == NULL || curr->next == NULL)
        return head;
    Node *nodeToDelete = curr->next;
    curr->next = curr->next->next;
    delete nodeToDelete;
    return head;
}

Node *deleteAtValue(Node *head, int value)
{
    if (head == nullptr)
        return nullptr;

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node *prev = head;
    Node *temp = head->next;
    while (temp != nullptr)
    {
        if (temp->data == value)
        {
            prev->next = temp->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

Node *insertAtHead(Node *head, int data)
{
    Node *newHead = new Node(data);
    newHead->next = head;
    return newHead;
}

Node *insertAtTail(Node *head, int data)
{
    if (head == nullptr)
    {
        return new Node(data);
    }
    Node *newTail = new Node(data);
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = newTail;
    return head;
}
