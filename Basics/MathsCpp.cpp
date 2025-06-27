#include<bits/stdc++.h>
using namespace std;

void countDigits(int);
void printingFactors(int);
void checkForPrime(int);

class Solution {
public:
    int reverse(int x) {
        int reverse = 0;
        int temp = x;
        while(temp != 0){
            if (reverse > INT_MAX/10 || (reverse == INT_MAX/10 && temp%10 > 7)) {
                return 0;
            }
            if (reverse < INT_MIN/10 || (reverse == INT_MIN/10 && temp%10 < -8)) {
                return 0;
            }
            reverse = reverse * 10 + temp%10;
            temp = temp / 10;
        }
        return reverse;
    }
};

int main(){

  int digit = 5820;

  //To count the number of digits we can use
  countDigits(digit);

  // To Reverse the Number
  Solution sol;
  cout << "Reverse of 123: " << sol.reverse(123) << endl;
  cout << "Reverse of -123: " << sol.reverse(-123) << endl;
  cout << "Reverse of 1534236469: " << sol.reverse(1534236469) << endl; // This should return 0 due to overflow

  // To Print the Factor of the Digits
  cout << "Factor of the Number 15: " << endl;
  printingFactors(15); 

  // To check for the Prime
  cout << "Is 19 Prime or not: " << endl;
  checkForPrime(19);
  cout << "Is 1 Prime or not: " << endl;
  checkForPrime(1);

  return 0;
}

void countDigits(int digit){
  cout << "Counting: " << endl;
  int temp = digit;
  while(temp != 0){
    cout << temp % 10 << " ";
    temp = temp / 10;
  }
  cout << endl;
  cout << "Completed the process." << endl;
}

void printingFactors(int digit){
  cout << "Printing the factors: " << endl;
  for(int i = 1; i*i < digit; i++){
    if(digit % i == 0){
      cout << i << ", ";
      if((digit / i) != i) 
        cout << digit/i << ", ";
    }
  }
  cout << endl;
}

void checkForPrime(int digit){
  cout << "Checking for Prime Number: " << endl;
  if (digit < 2) {
    cout << "Not Prime." << endl;
    return;
  }
  int count = 0;
  for(int i = 1; i*i <= digit; i++){
    if(digit % i == 0){
      count++;
      if((digit / i) != i) 
        count++;
    }
  }
  if(count == 2)
    cout << "Is a Prime Number." << endl;
  else
    cout << "Not Prime." << endl;
}