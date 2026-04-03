#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary tree, find the size of the largest binary search tree (BST) that is a subtree of the given tree. A BST is defined as a binary tree in which for every node, the value of all nodes in its left subtree is less than the node's value, and the value of all nodes in its right subtree is greater than the node's value.
Approach: To solve this problem, we can use a depth-first search (DFS) approach. We will traverse the tree and for each node, we will check if the subtree rooted at that node is a BST. If it is a BST, we will calculate its size and keep track of the maximum size found so far.

Steps:
1. Perform a DFS traversal of the tree.
2. For each node, check if the subtree rooted at that node is a BST by comparing the values of the left and right subtrees with the current node's value.
3. If the subtree is a BST, calculate its size and update the maximum size found so far.
4. If the subtree is not a BST, return a size of 0 for that subtree.
5. Continue the traversal until all nodes have been visited.

Time Complexity: O(N) where N is the number of nodes in the tree, as we visit each node once during the DFS traversal.
Space Complexity: O(H) where H is the height of the tree, due to the recursive call stack during the DFS traversal. In the worst case (skewed tree), this can be O(N).
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

class Solution {
  public:
    vector<int>solve(Node* node){
        if(!node){
            return {0, 1e9, -1e9};
        }
        if(!node->left && !node->right){
            return {1, node->data, node->data};
        }
        
        vector<int>lft=solve(node->left);
        vector<int>rgt=solve(node->right);
        
        if(node->data>lft[2] && node->data<rgt[1]){
            return {lft[0]+rgt[0]+1, min(lft[1], node->data),
                max(node->data, rgt[2])};
        }else return {max(rgt[0], lft[0]), -1e9, 1e9};
    }
    
    int largestBst(Node *root) {
        // Your code here
        return solve(root)[0];
    }
};