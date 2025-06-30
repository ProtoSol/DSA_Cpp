#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node *next;

 public:
  Node(int data, Node *next) {
    this->data = data;
    this->next = next;
  }

 public:
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

// Find the Middle Node
Node *findMiddleBrut(Node *head);
Node *findMiddleOpt(Node *head);

int main() {
  // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  // Brutforce
  // Node *middle = findMiddleBrut(head);
  // if (middle) {
  //   cout << "Middle node data: " << middle->data << endl;
  // } else {
  //   cout << "List is empty." << endl;
  // }

  // Optimal
  Node *middle = findMiddleOpt(head);
  if (middle) {
    cout << "Middle node data: " << middle->data << endl;
  } else {
    cout << "List is empty." << endl;
  }

  // Garbage Collection
  Node *temp;
  while (head) {
    temp = head;
    head = head->next;
    delete temp;
  }

  return 0;
}

// Brute Force Method
Node *findMiddleBrut(Node *head) {
  if (!head) return nullptr;

  Node *temp = head;
  int cnt = 0;
  while (temp) {
    cnt++;
    temp = temp->next;
  }
  cout << "Length of the LinkedList is : " << cnt << endl;

  // Use the mathematic formula to find the middle
  int mid = (cnt / 2) + 1;
  temp = head;
  while (mid > 1) {
    mid--;
    temp = temp->next;
  }
  return temp;
}

// Refer to the tortoise and hare algorithm
Node *findMiddleOpt(Node *head) {
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}