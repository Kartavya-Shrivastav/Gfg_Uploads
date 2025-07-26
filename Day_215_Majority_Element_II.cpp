#include <bits/stdc++.h>
using namespace std;

// Problem: Find all elements in an array that appear more than n/3 times.
// Approach: Use a hash map to count occurrences of each element and then filter those that appear more than n/3 times.

// Steps:
// 1. Create a hash map to store the frequency of each element in the array.
// 2. Iterate through the array and populate the hash map with counts.
// 3. Iterate through the hash map and collect elements that have a count greater than n/3.
// 4. Sort the resulting list of elements before returning it.

// Time Complexity: O(n log n) due to sorting, O(n) for counting.
// Space Complexity: O(n) for the hash map.

class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        unordered_map<int, int> mp;
        for (int& it : arr){
            mp[it]++;
        }
        int n = arr.size();
        vector<int> ans;
        for (auto& it : mp){
            if (it.second > n/3) ans.push_back(it.first);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};