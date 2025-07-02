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

void printLL(Node *head) {
  Node *temp = head;
  while (temp) {
    if (temp->next == nullptr) {
      cout << temp->data;
      break;
    }
    cout << temp->data << ", ";
    temp = temp->next;
  }
  cout << endl;
}

Node *oddThenEven(Node *head);

int main() {
  // Create a linked list with a loop: 1 -> 2 -> 3 -> 4
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  // Print Original
  cout << "Original Arrangement :" << endl;
  printLL(head);
  // Print Odd Then Even
  cout << "New Linked List Arrangement: " << endl;
  printLL(oddThenEven(head));

  return 0;
}

Node *oddThenEven(Node *head) {
  if (head == nullptr && head->next == nullptr) return nullptr;
  Node *odd = head;
  Node *evenHead = odd->next;
  Node *even = odd->next;
  while (even && even->next) {
    odd->next = odd->next->next;
    even->next = even->next->next;
    odd = odd->next;
    even = even->next;
  }
  odd->next = evenHead;
  return head;
}