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
Node* removeNthNodeBack(Node* head);

int main() {
  // Our main objective is to remove the Nth node from the back
  Node* head = new Node(1);
  Node* second = new Node(2);
  Node* third = new Node(3);
  Node* fourth = new Node(4);
  Node* fifth = new Node(5);
  Node* sixth = new Node(6);
  // Linking the Nodes
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;

  // Original Linked List
  printLL(head);
  // Which Node to Remove from the last?
  removeNthNodeBack(head, 4);
  printLL(head);
  return 0;
}

Node* reverseLL(Node* head) {
  if (head == nullptr) return head;
  Node* prev = nullptr;
  Node* temp = head;
  Node* front;
  while (temp) {
    front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

Node* removeNthNodeBack(Node* head, int Nth) {
  // Ok so What can I think of the Solution
  // Reverse the linked list
  // Remove the nth node
  // Re-Reverse the linked list and send the head;

  Node* newHead = reverseLL(head);

  Node* dummy = new Node(0, newHead);
  Node* prev = dummy;
  Node* curr = newHead;
  int index = 1;
  while (curr) {
    if (index == Nth) {
      prev->next = curr->next;
      delete curr;
      break;
    }
    prev = curr;
    curr = curr->next;
    index++;
  }
  return reverseLL(newHead);
}