#include <bits/stdc++.h>
using namespace std;

// Problem: Given a board of size n x m, and two arrays x and y representing the costs of cutting the board along vertical and horizontal lines respectively, find the minimum cost to cut the board into 1x1 squares.
// Approach: Use a greedy algorithm with a priority queue to always make the most expensive cut first, adjusting the cost based on the number of segments created by previous cuts.

// Steps:
// 1. Initialize a max-heap (priority queue) to store the costs of cuts along with their orientation (vertical or horizontal).
// 2. Push all costs from arrays x and y into the priority queue, marking vertical cuts with 0 and horizontal cuts with 1.
// 3. Initialize counters for the number of vertical and horizontal segments (v and h), starting at 1.
// 4. While the priority queue is not empty, pop the top element (the most expensive cut).
// 5. If the cut is vertical (axis == 0), add the cost multiplied by the current number of horizontal segments (h) to the total sum, and increment the vertical segment count (v).
// 6. If the cut is horizontal (axis == 1), add the cost multiplied by the current number of vertical segments (v) to the total sum, and increment the horizontal segment count (h).
// 7. Return the total sum as the minimum cost to cut the board into 1x1 squares.

// Time Complexity: O((n + m) log(n + m)), where n and m are the sizes of arrays x and y respectively, due to the priority queue operations.
// Space Complexity: O(n + m) for storing the costs in the priority queue.

class Solution {
  public:
    int minCost(int n, int m, vector<int>& x, vector<int>& y) {
        //  code here
        priority_queue<pair<int,int>>pq;
        for(auto it:x){
            pq.push({it,0});
        }
        for(auto it:y){
            pq.push({it,1});
        }
        int v=1,h=1;
        int sum=0;
        while(!pq.empty()){
            auto top=pq.top();
            pq.pop();
            int num=top.first;
            int axis=top.second;
            if(axis==0){
                sum+=(num*v);
                h++;
            }
            else{
                sum+=(num*h);
                v++;
            }
        }
        return sum;
        
    }
};
