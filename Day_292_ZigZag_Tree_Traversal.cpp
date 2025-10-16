#include <bits/stdc++.h>
using namespace std;

// Problem: ZigZag Tree Traversal
// Approach: We can use a level-order traversal (BFS) to explore the tree level by level. We will use a queue to facilitate the traversal and a flag to determine the order of insertion (left to right or right to left) for each level.
//           For each level, we will store the node values in a temporary vector and reverse it if the flag indicates a right-to-left order.

// Steps:
// 1. Use a queue to perform level-order traversal of the tree.
// 2. For each level, use a temporary vector to store the node values.
// 3. If the current level is right-to-left, reverse the temporary vector before adding it to the result.
// 4. Continue the process until all levels are traversed.

// Time Complexity: O(n) where n is the number of nodes in the tree (for traversing all nodes)
// Space Complexity: O(n) for the queue and temporary vector used in the traversal

/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    vector<int> zigZagTraversal(Node* root) {
        vector<int> ans;
        queue<Node*> q;
        q.push(root);
        bool f = 0;
        while(!q.empty()){
            int size = q.size();
            vector<int> v;
            for(int i = 0;i<size;i++){
                Node* front = q.front(); q.pop();
                v.push_back(front->data);
                
                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(f) reverse(v.begin(), v.end());
            f =!f;
            ans.insert(ans.end(), v.begin(), v.end());
        }
        return ans;
    }
};