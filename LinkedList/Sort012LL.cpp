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
Node* sort012LL(Node* head);

int main() {
  // Our main objective is to remove the Nth node from the back
  Node* head = new Node(2);
  Node* second = new Node(1);
  Node* third = new Node(0);
  Node* fourth = new Node(0);
  Node* fifth = new Node(1);
  Node* sixth = new Node(2);
  // Linking the Nodes
  head->next = second;
  second->next = third;
  third->next = fourth;
  fourth->next = fifth;
  fifth->next = sixth;

  // Original Linked List
  printLL(head);
  // Sorting the LinkedList
  cout << "After Sorting:" << endl;
  sort012LL(head);
  printLL(head);

  return 0;
}

Node* sort012LL(Node* head) {
  if (!head || !head->next) return head;

  int count[3] = {0, 0, 0};
  Node* temp = head;

  while (temp) {
    count[temp->data]++;
    temp = temp->next;
  }

  temp = head;
  for (int i = 0; i < 3; ++i) {
    while (count[i]--) {
      temp->data = i;
      temp = temp->next;
    }
  }
  return head;
}