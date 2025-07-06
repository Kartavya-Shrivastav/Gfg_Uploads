#include <bits/stdc++.h>
using namespace std;

// Problem: Find the top k sum pairs from two arrays.
// Approach: Use a max heap to keep track of the top k sums. Iterate through the first k elements of both arrays, calculate the sums, and maintain the heap size to k. If the sum is less than the smallest in the heap, break early to optimize performance.

// Steps:
// 1. Sort both arrays in descending order.
// 2. Use a priority queue (min-heap) to store the top k sums.
// 3. Iterate through the first k elements of both arrays, calculate the sum of each pair, and push it into the heap.
// 4. If the heap size exceeds k, pop the smallest element.
// 5. After processing all pairs, extract the elements from the heap and reverse them to get the top k sums in descending order.

// Time Complexity: O(k^2 log k), where k is the number of pairs considered.
// Space Complexity: O(k), for the priority queue storing the top k sums.

class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n=a.size(), m=b.size();
        sort(a.begin(), a.end(), greater<int>());
        sort(b.begin(), b.end(), greater<int>());
        
        priority_queue<int, vector<int>, greater<int>>pq;
        
        for(int i=0; i<k; i++){
            for(int j=0; j<k; j++){
                int sum=a[i]+b[j];
                if(pq.size()==k && sum<pq.top()) break;
                pq.push(a[i]+b[j]);
                if(pq.size()>k) pq.pop();
            }
        }
        
        vector<int>ans;
        while(!pq.empty()){
            ans.push_back(pq.top());
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};