#include <bits/stdc++.h>
using namespace std;

// Problem: Reverse a given queue using stack data structure.
// Approach: Use a stack to reverse the order of elements in the queue.

// Steps:
// 1. Initialize an empty stack
// 2. While the queue is not empty, push the front element of the queue onto the stack and pop it from the queue
// 3. While the stack is not empty, push the top element of the stack back into the queue and pop it from the stack
// 4. Return the modified queue

// Time Complexity: O(n) where n is the number of elements in the queue
// Space Complexity: O(n) for the stack used to reverse the queue

class Solution {
  public:
    queue<int> reverseQueue(queue<int> &q) {

        stack<int> st;
    
        while(!q.empty())
        {
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty())
        {
            q.push(st.top());
            st.pop();
        }
        
        return q;
    }
};
