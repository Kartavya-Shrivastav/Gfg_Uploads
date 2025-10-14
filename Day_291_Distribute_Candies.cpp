#include <bits/stdc++.h>
using namespace std;

// Problem: Given a binary tree where each node represents a house with a certain number of candies,
//          distribute candies such that each house has exactly one candy. Return the minimum number of candies required.
// Approach: Use a post-order traversal to calculate the excess or deficit of candies at each node.
//           For each node, the number of moves required is the sum of absolute values of excess candies from its left and right children.

// Steps:
// 1. Define a helper function that returns the net candies at each node (candies at node - 1).
// 2. At each node, calculate the moves required as the sum of absolute values of excess candies from its children.
// 3. Accumulate the moves in a global variable.
// 4. Return the total moves after traversing the entire tree.

// Time Complexity: O(N), where N is the number of nodes in the tree.
// Space Complexity: O(H), where H is the height of the tree (due to recursion stack).

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = nullptr;
    }
};
*/

class Solution {
  public:
  int solve(int& ans,Node*root){
      if(root==NULL){
          return 0;
      }
      int left=solve(ans,root->left);
      int right=solve(ans,root->right);
      ans+=abs(left)+abs(right);
      return left+right+root->data-1;
  }
    int distCandy(Node* root) {
        int ans=0;
        solve(ans,root);
        return ans;
    }
};