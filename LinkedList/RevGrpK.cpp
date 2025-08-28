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

// Reverse the Group of K in the Element
Node* RevGrpK(Node* head1, int k);

int main() {
  Node* head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(6);
  head->next->next->next->next->next->next = new Node(7);

  cout << "Original List: ";
  printList(head);

  int k = 3;
  Node* reversedHead = RevGrpK(head, k);

  cout << "Reversed in groups of " << k << ": ";
  printList(reversedHead);

  return 0;
}

Node* reverseLLRec(Node* head) {
  if (head == nullptr || head->next == nullptr) {
    return head;
  }
  Node* newHead = reverseLLRec(head->next);
  head->next->next = head;
  head->next = nullptr;
  return newHead;
}

Node* FindKthNode(Node* head, int k) {
  k -= 1;
  Node* temp = head;
  while (temp && k > 0) {
    k--;
    temp = temp->next;
  }
  return temp;
}

Node* RevGrpK(Node* head, int k) {
  if (head == nullptr || head->next == nullptr) return head;
  Node* prevNode = nullptr;
  Node* temp = head;
  while (temp) {
    Node* KNode = FindKthNode(temp, k);
    if (KNode == nullptr) {
      if (prevNode) {
        prevNode->next = temp;
      }
      break;
    }
    Node* nextNode = KNode->next;
    KNode->next = nullptr;
    reverseLLRec(temp);
    if (temp == head) {
      head = KNode;
    } else {
      prevNode->next = KNode;
    }
    prevNode = temp;
    temp = nextNode;
  }
  return head;
}