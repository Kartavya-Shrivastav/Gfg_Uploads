#include <bits/stdc++.h>
using namespace std;

// Problem: Delete all nodes in a BST with values greater than or equal to k
// Approach: Recursively traverse the BST and prune nodes whose values are greater than or equal to k

// Steps:
// 1. If the root is NULL, return NULL (base case).
// 2. If the root's value is greater than or equal to k, recursively process the left subtree 
//    (since all nodes in the right subtree will also have values >= k).
// 3. Otherwise, set root->right to the result of recursively processing the right subtree.
// 4. Return the updated root.

// Time Complexity: O(n) — where n is the number of nodes in the BST, as each node is visited once.
// Space Complexity: O(h) — where h is the height of the BST, due to recursive call stack usage.


class Solution {
  public:
    Node* deleteNode(Node* root, int k) {
        if( root == NULL ) return NULL ;
        if( root ->data >= k ) return deleteNode( root ->left , k );
        root ->right = deleteNode( root ->right , k );
        return root ;
    }
};