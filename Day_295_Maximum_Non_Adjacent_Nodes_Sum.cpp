#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary tree, find the maximum sum of non-adjacent nodes. Two nodes are considered adjacent if they are directly connected.
// Approach: Use a recursive function that returns two values for each node: the maximum sum including the node and the maximum sum excluding the node.
//           For each node, the maximum sum including the node is the node's value plus the sums of excluding its children.

// Steps:
// 1. Define a helper function that returns a pair of integers for each node: (include, exclude).
// 2. For each node, calculate the include sum as the node's value plus the exclude sums of its children.
// 3. Calculate the exclude sum as the maximum of include and exclude sums of its children.
// 4. Return the maximum of include and exclude sums for the root node.

// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

/*
struct Node
{
    int data;
    Node* left;
    Node* right;
};
*/

class Solution{
  public:
    pair<int,int> a(Node *root)
    {
        if(root == NULL)
        {
            return {0,0};
        }
        
        pair<int,int> l = a(root->left);
        pair<int,int> r = a(root->right);
        
        int in = root->data + l.second + r.second;
        int ex = max(l.first,l.second) + max(r.first,r.second);
        
        return {in,ex};
        
    }
    int getMaxSum(Node *root) 
    {
        pair<int,int> akshu = a(root);
        return max(akshu.first,akshu.second);
    }
};