#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary tree, return the vertical order traversal of its nodes values. 
Approach: We can use a breadth-first search (BFS) approach to traverse the tree level by level while keeping track of the horizontal distance of each node from the root. We can use a queue to perform the BFS and a map to store the nodes at each horizontal distance. Finally, we can iterate through the map and collect the nodes in vertical order.

Steps:
1. Initialize a queue to perform BFS and a map to store the nodes at each horizontal distance.
2. Start BFS by pushing the root node with a horizontal distance of 0 into the queue.
3. While the queue is not empty:
    a. Pop the front element from the queue, which gives us the current node and its horizontal distance.
    b. Add the current node's value to the map at the corresponding horizontal distance.
    c. If the current node has a left child, push it into the queue with a horizontal distance of (current distance - 1).
    d. If the current node has a right child, push it into the queue with a horizontal distance of (current distance + 1).
4. After the BFS is complete, iterate through the map in sorted order of keys (horizontal distances) and collect the nodes into the final answer vector.

Time Complexity: O(N log N) due to the sorting of the map keys, where N is the number of nodes in the tree.
Space Complexity: O(N) for the queue and the map to store the nodes at each horizontal distance.
*/

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

using pri = pair<int, Node*>;
using vi = vector<int>;

class Solution {
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vi> ans;
        
        if (!root)
            return ans;
        
        queue<pri> q;
        map<int, vi> m;
        
        q.push({0, root});
        
        while (!q.empty()) {
            auto d = q.front().first;
            auto node = q.front().second;
            
            q.pop();
            
            m[d].push_back(node->data);
            
            if (node->left)
                q.push({d -1 , node->left});
            if (node->right)
                q.push({d + 1, node->right});
        }
        
        for (auto& [k, t] : m)
            ans.push_back(t);
        
        return ans;
    }
};
