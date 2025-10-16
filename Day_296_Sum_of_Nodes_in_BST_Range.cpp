#include <bits/stdc++.h>
using namespace std;

// Problem: Given a Binary Search Tree (BST) and a range [L, R], find the sum of all nodes' values within this range.
// Approach: Use a recursive function to traverse the tree. For each node, check if its value lies within the range [L, R].
//           If it does, add its value to the sum. If the node's value is
//           greater than L, traverse the left subtree. If it's less than R, traverse the right subtree.

// Steps:
// 1. Define a recursive function that takes the current node and the range [L, R] as parameters.
// 2. If the current node is null, return 0.
// 3. Initialize a variable to store the sum.
// 4. If the current node's value is within the range, add it to the sum.
// 5. If the current node's value is greater than L, recursively call the function on the left child.
// 6. If the current node's value is less than R, recursively call the function on the right child.
// 7. Return the total sum.

// Time Complexity: O(N) in the worst case, where N is the number of nodes in the tree (if the tree is skewed).
// Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
  public:
    int nodeSum(Node* root, int l, int r) {
        if(!root) return 0;
        int ans = 0;
        if(root -> data > l) ans += nodeSum(root -> left, l, r);
        if(r > root -> data) ans += nodeSum(root -> right, l, r);
        if(root -> data >= l && root -> data <= r) ans += root -> data;
        return ans;
    }
};