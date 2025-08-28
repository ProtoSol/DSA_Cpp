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
Node* AddLL(Node* head1, Node* head2, int carry);

int main() {
  Node* l1 = new Node(2);
  l1->next = new Node(4);
  l1->next->next = new Node(7);

  Node* l2 = new Node(5);
  l2->next = new Node(6);
  l2->next->next = new Node(4);

  cout << "List 1: ";
  printList(l1);
  cout << "List 2: ";
  printList(l2);

  return 0;
}

// Add 2 numbers
Node* AddLL(Node* head1, Node* head2, int carry) {
  if (!head1 && !head2 && carry == 0) return nullptr;
  int val1 = head1 ? head1->data : 0;
  int val2 = head2 ? head2->data : 0;
  int sum = val1 + val2 + carry;
  Node* node = new Node(sum % 10);
  node->next = AddLL(head1 ? head1->next : nullptr,
                     head2 ? head2->next : nullptr, sum / 10);
  return node;
}