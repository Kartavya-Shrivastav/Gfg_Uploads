#include <bits/stdc++.h>
using namespace std;

// Problem: Interleave the First Half of the Queue with Second Half
// Given a queue of integers, rearrange the elements by interleaving the first half of the queue with the second half.
// Approach: Use two auxiliary queues to separate the first and second halves, then interleave them back into the original queue.

// Steps:
// 1. Determine the size of the original queue.
// 2. Create two auxiliary queues, q1 and q2.
// 3. Dequeue the first half of the elements from the original queue and enqueue them into q1.
// 4. Dequeue the remaining elements from the original queue and enqueue them into q2.
// 5. While both q1 and q2 are not empty, dequeue one element from q1 and one from q2, and enqueue them back into the original queue.
// 6. If there are any remaining elements in q1 (in case of odd number of elements), enqueue them back into the original queue.

// Time Complexity: O(N) where N is the number of elements in the queue, as each element is processed a constant number of times.
// Space Complexity: O(N) for the auxiliary queues used to store the two halves of the original queue.

class Solution {
  public:
    void rearrangeQueue(queue<int> &q) {
         queue<int> q1 , q2;
        int n = q.size();
        
        for(int i=0;i<(n+1)/2;i++){
            q1.push(q.front());
            q.pop();
        }
        
        while(!q.empty()){
            q2.push(q.front());
            q.pop();
        }
        
        while(!q1.empty() && !q2.empty()){
            q.push(q1.front());
            q.push(q2.front());
            q1.pop();
            q2.pop();
        }
    }
};