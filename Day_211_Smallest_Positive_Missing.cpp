#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Find the smallest positive integer that is missing from the array `arr`.
// Approach: Use a hash set to track the presence of numbers and iterate from 1 upwards to find the first missing number.

// Steps:
// 1. Create a hash set to store the elements of the array.
// 2. Start from 1 and check if it exists in the set.
// 3. If a number is not found in the set, return it as the smallest positive missing number.

// Time Complexity: O(n) — where `n` is the size of the array `arr`.
// Space Complexity: O(n) — for the hash set to store the elements.

class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        // code here
        int n=arr.size();
        unordered_set<int>st(arr.begin(), arr.end());
        
        int i=1;
        while(true){
            if(st.find(i)==st.end()) return i;
            i++;
        }
        
        return -1;
    }
};