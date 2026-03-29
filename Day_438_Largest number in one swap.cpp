#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a string representing a non-negative integer, determine if it is possible to obtain the largest possible integer by swapping at most one pair of digits. If it is possible, return the resulting largest integer as a string; otherwise, return the original string.
Approach: We can use a greedy approach to solve this problem. We will iterate through the string from right to left and keep track of the maximum digit we have seen so far. For each digit, we will check if it is smaller than the maximum digit we have seen. If it is, we can swap it with the maximum digit to get a larger number. We will also keep track of the index of the maximum digit to perform the swap correctly.

Steps:
1. Initialize a vector `maxi` of the same size as the input string to keep track of the index of the maximum digit from the right.
2. Iterate through the string from right to left:
   a. For each digit, compare it with the maximum digit seen so far.
   b. If the current digit is greater than the maximum digit, update the maximum digit and its index in the `maxi` vector.
   c. Otherwise, keep the index of the maximum digit in the `maxi` vector.
3. After processing the string, iterate through it from left to right:
    a. For each digit, check if it is smaller than the maximum digit at the corresponding index in the `maxi` vector.
    b. If it is, swap the current digit with the maximum digit and return the resulting string.
4. If no swap is performed after checking all digits, return the original string.

Time Complexity: O(n) for iterating through the string twice.
Space Complexity: O(n) for the `maxi` vector.
*/

class Solution {
  public:
    string largestSwap(string &s){
      int n=s.size();
      vector<int> maxi(n, 0);
      
      maxi[n-1]=n-1;
      for(int i=n-2; i>=0; i--){
        if(s[i]>s[maxi[i+1]]) maxi[i]=i;
        else maxi[i]=maxi[i+1];
      }
      
      for(int i=0; i<n; i++){
        if(i!=maxi[i] && s[i]!=s[maxi[i]]){
          swap(s[i], s[maxi[i]]);
          return s;
        }  
      }
      
      return s;
    }
};