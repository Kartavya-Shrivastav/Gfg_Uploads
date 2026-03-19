#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of integers and an integer K, find the maximum XOR of any subarray of size K.
Approach: We can use a sliding window approach to solve this problem. We maintain a window of size K and calculate the XOR of the elements in the window. As we slide the window from left to right, we can efficiently update the XOR value by removing the contribution of the element that is sliding out of the window and adding the contribution of the new element that is sliding into the window. We keep track of the maximum XOR value encountered during this process.

Steps:
1. Initialize a variable `answer` to store the maximum XOR value, and set it to `INT_MIN` to handle cases where all XOR values might be negative.
2. Initialize two pointers, `first` and `second`, to represent the start and end of the current window, and a variable `temp` to store the XOR value of the current window.
3. Iterate through the array using the `second` pointer:
    a. Update `temp` by XORing it with the current element at `second`.
    b. If the size of the current window (which is `second - first + 1`) is equal to K, we have a valid subarray:
        i. Update `answer` with the maximum of `temp` and `answer`.
        ii. Remove the contribution of the element at `first` from `temp` by XORing it again (since XORing twice cancels out).
        iii. Move the `first` pointer to the right to slide the window.
    c. Move the `second` pointer to the right to continue sliding the window.
4. After the loop, return the value of `answer` as the maximum XOR of any subarray of size K.

Time Complexity: O(n), where n is the number of elements in the input array. We traverse the array once with the `second` pointer, and the `first` pointer also moves at most n times.
Space Complexity: O(1), as we are using only a constant amount of extra space for variables to keep track of the XOR value and the maximum answer.
*/

class Solution {
  public:
    int maxSubarrayXOR(vector<int>& arr, int k) {
      int answer=INT_MIN;
      int first=0;
      int second=0;
      int temp=0;
      
      while(second<arr.size()){   
         temp= temp^arr[second];

         if(second-first+1 ==k){
            answer = max(temp,answer); 
             temp= temp^arr[first];
             first++;
         }
         second++;
          
          
      }
      return answer;
        
    }
};