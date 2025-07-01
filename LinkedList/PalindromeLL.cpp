#include <bits/stdc++.h>
using namespace std;

class Node {
 public:
  int data;
  Node* next;

 public:
  Node(int data, Node* next) {
    this->data = data;
    this->next = next;
  }

 public:
  Node(int data) {
    this->data = data;
    this->next = nullptr;
  }
};

bool palindromeLL(Node* head);

int main() {
  // Creating a palidrome Linked List and Non Palindrome Linked List
  Node* phead = new Node(1);
  phead->next = new Node(2);
  phead->next->next = new Node(3);
  phead->next->next->next = new Node(2);
  phead->next->next->next->next = new Node(1);

  Node* nphead = new Node(1);
  nphead->next = new Node(2);
  nphead->next->next = new Node(3);
  nphead->next->next->next = new Node(4);
  nphead->next->next->next->next = new Node(5);

  // Check if Palindromic or Not
  cout << "The First LL is : " << palindromeLL(phead) << endl;
  cout << "The Second LL is : " << palindromeLL(nphead) << endl;
  return 0;
}

bool palindromeLL(Node* head) { return false; }