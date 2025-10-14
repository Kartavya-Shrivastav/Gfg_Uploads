#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary tree, find the maximum path sum. The path may start and end at any node in the tree.
// Approach: Use a recursive function to calculate the maximum path sum at each node, considering both left and right subtrees. 
//           Update the global maximum path sum whenever a higher sum is found.

// Steps:
// 1. Define a helper function that returns the maximum path sum for each node.
// 2. At each node, calculate the maximum path sum including the current node.
// 3. Update the global maximum path sum if the current path sum is greater.
// 4. Return the maximum path sum for the current node to its parent.

// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

/*
class Node {
public:
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
    int findMaxSum(Node *root) {
        int maxSum = INT_MIN;
        solve(root, maxSum);
        return maxSum;
    }

    private:
        int solve(Node *root, int &maxSum) {
            if (root == nullptr) {
                return 0;
            }
    
            int left = max(0, solve(root->left, maxSum));
            int right = max(0, solve(root->right, maxSum));
    
            maxSum = max(maxSum, left + right + root->data);
    
            return root->data + max(left, right);
        }
};