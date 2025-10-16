#include <bits/stdc++.h>
using namespace std;

// Problem: Remove BST keys outside given range
// Approach: 

// Steps:
// 1. If the current node's value is within the range [l, r], recursively process its left and right children.
// 2. If the current node's value is less than l, discard the left subtree and recursively process the right child.
// 3. If the current node's value is greater than r, discard the right subtree and recursively process the left child.
// 4. Return the modified tree.

// Time Complexity: O(n) where n is the number of nodes in the BST.
// Space Complexity: O(h) where h is the height of the BST due to recursion stack

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
    Node* solve(Node*root,int l,int r){
        if(!root) return NULL;
        
        if(root->data >= l && root->data <= r){
            root->left = solve(root->left,l,r);
            root->right = solve(root->right,l,r);
            return root;
        }
        else if(root->data > r ){
            return solve(root->left,l,r);
        }else return solve(root->right,l,r);
    }
  public:
    Node* removekeys(Node* root, int l, int r) {
        // code here
        return solve(root,l,r);
    }
};