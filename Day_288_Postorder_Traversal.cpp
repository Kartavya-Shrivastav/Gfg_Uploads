#include <bits/stdc++.h>
using namespace std;

// Problem: Postorder Traversal of Binary Tree
// Approach: We can use a recursive approach to traverse the binary tree in postorder fashion (left, right, root).
//           We will define a helper function that takes the current node and a reference to the result vector.

// Steps:
// 1. If the current node is null, return.
// 2. Recursively call the helper function for the left child.
// 3. Recursively call the helper function for the right child. 
// 4. Add the current node's value to the result vector.
// 5. Finally, return the result vector containing the postorder traversal of the tree.

// Time Complexity: O(n) where n is the number of nodes in the tree (for traversing all nodes)
// Space Complexity: O(h) where h is the height of the tree (for the recursion stack)

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    void post(Node* root, vector<int>& ans){
        if (!root) return;
        post(root->left, ans);
        post(root->right, ans);
        ans.push_back(root->data);
    }
  public:
    vector<int> postOrder(Node* root) {
        vector<int> ans;
        post(root, ans);
        return ans;
    }
};