#include <bits/stdc++.h>
using namespace std;

// Problem: Given an array of integers where each integer is in the range from 1 to n (n = size of array), find all the integers that appear more than once.
// Approach: Frequency Counting

// Steps:
// 1. Create a frequency array `same` of size n+1 initialized to zero.
// 2. Iterate through the input array and for each integer, increment its corresponding index in the frequency array.
// 3. After populating the frequency array, iterate through it to find all indices (integers) that have a count of 2 or more.
// 4. Collect these integers into a result array and return it.
// Time Complexity: O(n)
// Space Complexity: O(n)

class Solution {
public:
    vector<int> findDuplicates(vector<int>& arr) {
        int n = arr.size();
        vector<int> same(n + 1, 0);
        vector<int> ans;
        
        for (int i = 0; i < n; i++) {
            same[arr[i]]++;
        }
        
        for (int i = 1; i <= n; i++) {
            if (same[i] >= 2) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};