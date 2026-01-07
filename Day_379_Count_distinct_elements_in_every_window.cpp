#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Given an array of integers and an integer k, count the number of distinct elements in every window of size k.    
// Approach: Sliding Window with Hash Map

// Steps:
// 1. Use an unordered_map to keep track of the frequency of elements in the current window
// 2. Initialize the map with the first 'k' elements and store the count of distinct elements
// 3. Slide the window across the array by removing the element going out of the window and adding the new element coming into the window
// 4. Update the count of distinct elements after each slide and store it in the result

// Time Complexity: O(n) where n is the number of elements in the array
// Space Complexity: O(k) in the worst case when all elements in the window are distinct

class Solution {
  public:
    vector<int> countDistinct(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> freq;
        vector<int> ans;
        
        for (int i = 0; i < k; i++) {
            freq[arr[i]]++;
        }
        ans.push_back(freq.size());
        
        int j = 0;
        for (int i = k; i < n; i++) {
            freq[arr[j]]--;
            if (freq[arr[j]] == 0)
                freq.erase(arr[j]);
            j++;
            freq[arr[i]]++;
            ans.push_back(freq.size());
        }
        return ans;
    }
};