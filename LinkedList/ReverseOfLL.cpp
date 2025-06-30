#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val) : data(val), next(nullptr) {}
};

auto printList = [](Node* head) {
  Node* curr = head;
  while (curr) {
    cout << curr->data << " ";
    curr = curr->next;
  }
  cout << endl;
};

// Reversing a LinkedList using Iteration
Node* reverseLLIter(Node* head);
// Reversing a LinkedList using Recursion
Node* reverseLLRec(Node* head);

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

Node* reverseLLIter(Node* head) {
  if (head == NULL) return head;
  Node* temp = head;
  Node* prev = nullptr;
  Node* front;
  while (temp) {
    front = temp->next;
    temp->next = prev;
    prev = temp;
    temp = front;
  }
  return prev;
}

Node* reverseLLRec(Node* head) {
  // Base case
  if (head == NULL || head->next == NULL) return head;
  // Get the new head
  Node* newHead = reverseLLRec(head->next);

  // It will return like this, So we just have to return
  // 3 -> 4 <- 5
  //      |
  //      X
  head->next->next = head;
  head->next = nullptr;

  // Return the new Head
  return newHead;
}
