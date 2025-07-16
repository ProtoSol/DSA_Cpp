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

// Function to remove the node from last place
Node* sortLL(Node* head);

int main() {
  // Our main objective is to remove the Nth node from the back
  Node* head = new Node(4);
  Node* second = new Node(3);
  Node* third = new Node(8);
  Node* fourth = new Node(-1);
  Node* fifth = new Node(2);
  Node* sixth = new Node(0);
  // Linking the Nodes
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;

  // Original Linked List
  printLL(head);
  // Sorting the LinkedList
  sortLL(head);
  printLL(head);

  return 0;
}

Node* merge(Node* L1, Node* L2) {
  Node dummy(-1);
  Node* temp = &dummy;
  while (L1 && L2) {
    if (L1->data < L2->data) {
      temp->next = L1;
      L1 = L1->next;
    } else {
      temp->next = L2;
      L2 = L2->next;
    }
    temp = temp->next;
  }
  temp->next = L1 ? L1 : L2;
  return dummy.next;
}

Node* sortLL(Node* head) {
  if (head == nullptr || head->next == nullptr) return head;
  // It is the Divide and Conquer Method
  // Or shall I say its just merge sort
  Node* slow = head;
  Node* fast = head;
  Node* prev = nullptr;

  while (fast && fast->next) {
    prev = slow;
    slow = slow->next;
    fast = fast->next->next;
  }
  prev->next = nullptr;

  Node* L1 = sortLL(head);
  Node* L2 = sortLL(slow);
  return merge(L1, L2);
}