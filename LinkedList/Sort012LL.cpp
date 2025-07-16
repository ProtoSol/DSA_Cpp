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
Node* sort012LLBrute(Node* head);
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
  // sort012LLBrute(head);
  printLL(sort012LL(head));

  return 0;
}

Node* sort012LLBrute(Node* head) {
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

Node* sort012LL(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }

  // Dummy heads and tails for sublists
  Node zeroDummy(-1), oneDummy(-1), twoDummy(-1);
  Node* zeroTail = &zeroDummy;
  Node* oneTail = &oneDummy;
  Node* twoTail = &twoDummy;

  // Distribute nodes into 0s, 1s, and 2s
  Node* curr = head;
  while (curr) {
    if (curr->data == 0) {
      zeroTail->next = curr;
      zeroTail = curr;
    } else if (curr->data == 1) {
      oneTail->next = curr;
      oneTail = curr;
    } else {  // curr->data == 2
      twoTail->next = curr;
      twoTail = curr;
    }
    curr = curr->next;
  }

  // Stitch the lists together
  zeroTail->next = (oneDummy.next != nullptr) ? oneDummy.next : twoDummy.next;
  oneTail->next = twoDummy.next;
  twoTail->next = nullptr;

  // Return new head
  return zeroDummy.next;
}