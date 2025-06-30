#include <bits/stdc++.h>
using namespace std;

// Define the Node structure
struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

// Function to print the linked list
auto printList = [](Node* head) {
  Node* curr = head;
  while (curr) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
};

int main() {
  // Create a simple linked list: 1 -> 2 -> 3 -> 4
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);

  // Print the linked list
  printList(head);

  return 0;
}