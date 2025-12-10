#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers where each integer is in the range from 1 to n (n = size of array), find the missing and repeating integers.
// Approach: Frequency Counting

// Steps:
// 1. Create a frequency array `temp` of size n+1 initialized to zero.
// 2. Iterate through the input array and for each integer, increment its corresponding index in the frequency array.
// 3. After populating the frequency array, iterate through it to find the index (integer) that has a count of 2 (repeating) and the index that has a count of 0 (missing).
// 4. Return these two integers as a result.

// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
  public:
    vector<int> findTwoElement(vector<int>& arr) {
        int n = arr.size();
        int f = 0 , s = n;
        vector<int> temp (n+1 , 0);
        for(int it : arr) temp[it]++;
        for(int i = 1; i <= n ; i++){
            if(temp[i] == 2) f = i;
            if(temp[i] == 0) s = i;
        }
        return {f,s};
    }
};