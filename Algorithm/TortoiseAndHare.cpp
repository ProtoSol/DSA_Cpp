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
Node *tortoiseAndHare(Node *head);

int main() {
  // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> 5
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);

  Node *middle = tortoiseAndHare(head);
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

// Tortoise And Hare
// Here we take two pointers one fast and other slow both pointing towards the
// head. the fast moves 2 steps (Hare) and the slow moves 1 step (Tortoise) both
// moves together when the fast ends the slow points towards the middle of the
// Linked List.
Node *tortoiseAndHare(Node *head) {
  Node *fast = head;
  Node *slow = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

// This algorithm can also be used to detect the loops in the Linked List data
// structure.
Node *loopInLL(Node *head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node *slow = head;
  Node *fast = head;
  while (fast && fast->next) {
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