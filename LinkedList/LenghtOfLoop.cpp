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

// Length of the Loop in LL
int lengthOfLoopLL1(Node* head);
int lengthOfLoopLL2(Node* head);

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
  cout << "The Length of the Loop is: " << lengthOfLoopLL2(head) << endl;
  // Print the linked list
  // printList(head);

  return 0;
}

// Uses the Hashing and has TC -> O(n) and SC-> O(n);
int lengthOfLoopLL1(Node* head) {
  map<Node*, int> mpp;
  Node* temp = head;
  int cnt = 1;

  while (temp) {
    // If current node already visited, we found the loop
    if (mpp.find(temp) != mpp.end()) {
      return cnt - mpp[temp];
    }
    mpp[temp] = cnt;
    cnt++;
    temp = temp->next;
  }

  return 0;  // No loop found
}

// For the Optimized version
int lengthOfLoopLL2(Node* head) {
  if (head == nullptr || head->next == nullptr) return 0;
  Node* slow = head;
  Node* fast = head;
  while (fast && fast->next) {
    slow = slow->next;
    fast = fast->next->next;
    if (slow == fast) {
      // Loop detected, now count the length
      int cnt = 1;
      Node* temp = slow->next;
      while (temp != slow) {
        cnt++;
        temp = temp->next;
      }
      return cnt;
    }
  }
  return 0;
}