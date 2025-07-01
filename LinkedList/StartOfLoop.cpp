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

// Starting Point of the LL Loop
Node* startOfLoopLL(Node* head);

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
  cout << "The Starting point of the Loop is: " << startOfLoopLL(head)->data
       << endl;
  // Print the linked list
  // printList(head);

  return 0;
}

// Helper function of the Main
Node* detectLoopLL(Node* head) {
  if (head == nullptr || head->next == nullptr) return nullptr;

  Node* fast = head;
  Node* slow = head;

  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (fast == slow) {
      return slow;
    }
  }
  return nullptr;
}

// First we have to check if there is any loop to proceed.
Node* startOfLoopLL(Node* head) {
  // Base Case
  if (head == nullptr || head->next == nullptr) return nullptr;

  // Check for loop
  Node* meetingPoint = detectLoopLL(head);
  if (!meetingPoint) return nullptr;

  // Move the pointer from head and fast pointer one step simulatneously Till
  // they reach
  Node* ptr1 = head;
  Node* ptr2 = meetingPoint;
  while (ptr1 != ptr2) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return ptr1;
}