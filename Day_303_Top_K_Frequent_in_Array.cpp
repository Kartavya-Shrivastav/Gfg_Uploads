#include <bits/stdc++.h>
using namespace std;

// Problem: Find the top K frequent elements in an array.
// Approach: Use a hash map to count frequencies and a max-heap to extract the top K elements.

// Steps:
// 1. Use an unordered_map to count the frequency of each element in the array. 
// 2. Use a max-heap (priority queue) to store pairs of (frequency, element).
// 3. Push all elements from the frequency map into the max-heap.   
// 4. Pop the top K elements from the max-heap and store their values in the answer array.
// 5. Return the answer array containing the top K frequent elements.

// Time Complexity: O(n log n) due to heap operations.
// Space Complexity: O(n) for the frequency map and the heap.

class Solution {
  public:
    vector<int> topKFreq(vector<int> &arr, int k) {
        unordered_map<int,int> mp;
        for(int it : arr) mp[it]++;
        priority_queue<pair<int,int>> pq;
        for(auto it : mp) pq.push({it.second,it.first});
        vector<int> ans;
        int i = k;
        while(!pq.empty()){
            if(i==0) break;
            int value = pq.top().second;
            ans.push_back(value);
            pq.pop();
            i--;
        }
        return ans ;
    }
};