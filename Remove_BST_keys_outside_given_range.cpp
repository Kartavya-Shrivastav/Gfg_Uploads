#include <bits/stdc++.h>
using namespace std;

// Problem: Remove keys from a Binary Search Tree (BST) that are outside a given range [l, r]
// Approach: Recursively traverse the BST and remove nodes that are outside the range [l, r].

// Steps:
// 1. If the current node is NULL, return NULL.
// 2. If the current node's value is greater than r, recursively call the function on the left subtree.
// 3. If the current node's value is less than l, recursively call the function on the right subtree.
// 4. If the current node's value is within the range [l, r], recursively call the function on both left and right subtrees.
// 5. Return the current node after processing its children.

// Time Complexity: O(N) where N is the number of nodes in the BST.
// Space Complexity: O(H) where H is the height of the tree (due to recursion stack).

class Solution {
    public:
    
    struct Node{
        int data;
        Node* left;
        Node* right;
    };
    
    // Function to remove all nodes from the BST whose values are outside the range [l, r]
    Node* removekeys(Node* root, int l, int r) {
        // Base case: If the current node is NULL, return NULL
        if (!root) {
            return root;
        }
        // If current node's value is greater than r, discard the right subtree
        // and process the left subtree
        if (root->data > r) {
            Node *remainingPart = root->left;
            root->left = NULL; // Disconnect the left child
            return removekeys(remainingPart, l, r);
        }
        // If current node's value is less than l, discard the left subtree
        // and process the right subtree
        else if (root->data < l) {
            Node *remainingPart = root->right;
            root->right = NULL; // Disconnect the right child
            return removekeys(remainingPart, l, r);
        }
        // If current node's value is within [l, r], process both subtrees
        else {
            root->left = removekeys(root->left, l, r);
            root->right = removekeys(root->right, l, r);
            return root;
        }
    }
};