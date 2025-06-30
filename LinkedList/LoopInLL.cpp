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

auto printList = [](Node* head) {
  Node* curr = head;
  while (curr) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
};

Node* loopInLL(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node* slow = head;
  Node* fast = head;
  while (fast != nullptr && fast->next != nullptr) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      cout << "Loop Detected" << endl;
      return head;
    }
  }
  cout << "No Loop Detected" << endl;
  return head;
}

int main() {
  // Create a linked list with a loop: 1 -> 2 -> 3 -> 4 -> 2 (loop back to node
  // with data 2)
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  // Creating a loop: 4 -> 2
  head->next->next->next->next = head->next;

  // Detect the Loop
  loopInLL(head);
  // Print the linked list
  // printList(head);

  return 0;
}