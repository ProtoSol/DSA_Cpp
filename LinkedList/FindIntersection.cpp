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

void printLL(Node* head) {
  Node* temp = head;
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

// Function to find the intersection point of the Linked Lists
Node* findInterLL(Node* head1, Node* head2);

int main() {
  // Creating two linked lists that intersect
  // List A: 1 -> 2 -> 3 \
  //                        -> 6 -> 7
  // List B:       4 -> 5 /

  // Shared part
  Node* intersect = new Node(6);
  intersect->next = new Node(7);

  // First list
  Node* headA = new Node(1);
  headA->next = new Node(2);
  headA->next->next = new Node(3);
  headA->next->next->next = intersect;

  // Second list
  Node* headB = new Node(4);
  headB->next = new Node(5);
  headB->next->next = intersect;

  // Print both lists
  cout << "List A: ";
  printLL(headA);
  cout << "List B: ";
  printLL(headB);

  return 0;
}

Node* findInterLL(Node* head1, Node* head2) {
  if (head1 == nullptr || head2 == nullptr) return nullptr;
  if (head1 == head2) return head1;

  // Find the length of the Linked List
  Node *t1 = head1, *t2 = head2;
  int len1 = 0, len2 = 0;
  while (t1) {
    ++len1;
    t1 = t1->next;
  }
  while (t2) {
    ++len2;
    t2 = t2->next;
  }

  // Move the bigger till diff  == 0
  int diff = len1 - len2;
  if (diff > 0) {
    while (diff--) t1 = t1->next;
  } else {
    while (diff++) t2 = t2->next;
  }

  // Return the Node
  t1 = head1;
  t2 = head2;
  while (t1 && t2) {
    if (t1 == t2) {
      return t1;
    }
    t1 = t1->next;
    t2 = t2->next;
  }

  // Nothing is Common
  return nullptr;
}