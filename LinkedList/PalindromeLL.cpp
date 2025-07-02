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

Node* reverseLLIter(Node* head) {
  if (head == nullptr) return nullptr;

  Node* temp = head;
  Node* front;
  Node* prev = nullptr;
  while (temp) {
    front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

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

bool palindromeLL(Node* head) {
  if (head == nullptr || head->next == nullptr) return true;

  // First we find the middle
  Node* fast = head;
  Node* slow = head;
  while (fast->next && fast->next->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  // Now we get the middle part and will start to reverse the other half
  Node* newHead = reverseLLIter(slow->next);

  // Now we compare
  Node* first = head;
  Node* second = newHead;
  while (second) {
    if (first->data != second->data) {
      reverseLLIter(newHead);
      return false;
    }
    first = first->next;
    second = second->next;
  }
  reverseLLIter(newHead);
  return true;
}