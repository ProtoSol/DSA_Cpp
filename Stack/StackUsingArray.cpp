#include <bits/stdc++.h>
using namespace std;

class CustomStack {
  int* Cstack;
  int top_idx;
  int capacity;

 public:
  CustomStack(int size) {
    capacity = size;
    Cstack = new int[capacity];
    top_idx = -1;
  }
  ~CustomStack() { delete[] Cstack; }

  void cpush(int item) {
    if (top_idx >= capacity - 1) {
      cout << "The Stack is full" << endl;
      return;
    }
    top_idx++;
    Cstack[top_idx] = item;
  }

  int ctop() {
    if (top_idx == -1) {
      return -1;
    }
    return Cstack[top_idx];
  }

  void cpop() {
    if (top_idx == -1) {
      cout << "The Stack is Empty" << endl;
      return;
    }
    top_idx--;
  }

  int csize() { return top_idx + 1; }
};

int main() {
  // Implementation of Stack using Array
  CustomStack st(10);
  st.cpop();
  st.cpush(1);
  st.cpush(2);
  st.cpop();
  cout << st.ctop() << endl;
  return 0;
}