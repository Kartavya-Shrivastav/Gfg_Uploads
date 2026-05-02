#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given an array of 0s and 1s, segregate the 0s on the left side and the 1s on the right side of the array.  
Approach: We can count the number of 0s in the array and then fill the first part of the array with 0s and the remaining part with 1s.

Steps:
1. Initialize a variable countZero to 0.
2. Iterate through the array and count the number of 0s.
3. Iterate through the array again and fill the first countZero elements with 0s and the remaining elements with 1s.

Time Complexity: O(n) - We traverse the array twice, once for counting and once for filling.
Space Complexity: O(1) - We use only a constant amount of extra space for the countZero variable.

*/

class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int countZero = 0;
        for (auto i : arr) {
            if (!i) {
               countZero++; 
            }
        }
        
        for (int i = 0; i < arr.size(); i++) {
            if (countZero) {
                arr[i] = 0;
                countZero--;
            } else {
                arr[i] = 1;
            }
        }
    }
};