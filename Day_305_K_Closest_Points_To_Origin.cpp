#include <bits/stdc++.h>
using namespace std;

// Problem: Find the k closest points to the origin in a 2D plane.
// Approach: Use a max-heap (priority queue) to keep track of the k closest

// Steps:
// 1. Initialize a max-heap to store pairs of (distance, point).
// 2. For each point, calculate its Euclidean distance from the origin and push it into the max-heap.
// 3. If the size of the heap exceeds k, pop the farthest point.
// 4. After processing all points, extract the points from the max-heap to get the k closest points.
// 5. Return the list of k closest points.

// Time Complexity: O(n log k) where n is the number of points.
// Space Complexity: O(k) for the max-heap.
class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int,int>>>pq;
        for(auto it : points){
            pq.push({sqrt((it[0]*it[0])+(it[1] * it[1])), {it[0], it[1]}});
            while(pq.size() > k)pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.size()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};