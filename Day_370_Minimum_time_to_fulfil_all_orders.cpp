#include <bits/stdc++.h>
using namespace std;

// Problem: Minimum time to fulfil all orders
// Approach: Min-Heap (Priority Queue)

// Steps:
// 1. Use a min-heap to keep track of the next available time for each chef.
// 2. For each order, extract the chef who will be free the earliest.
// 3. Assign the order to that chef and update their next available time.
// 4. The maximum time taken by any chef to complete their orders is the answer.
// 5. Return the maximum time after all orders are assigned.

// Time Complexity: O(n log m) where m is the number of chefs and n is the number of orders
// Space Complexity: O(m) for the heap

class Solution {
  public:
    using p = pair<int,pair<int,int>>;
    int minTime(vector<int>& ranks, int n) {
        priority_queue<p,vector<p>,greater<p>> pq;
        int m = ranks.size(); // number of chefs
        for(int i=0;i<m;i++){
            pq.push({ranks[i],{2*ranks[i],i}});
        }
        int ans = 0;
        while(n--){
            p temp = pq.top();
            pq.pop();
            ans=max(ans,temp.first);
            pq.push({temp.first+temp.second.first,{temp.second.first+ranks[temp.second.second],temp.second.second}});
        }
        return ans;
    }
};