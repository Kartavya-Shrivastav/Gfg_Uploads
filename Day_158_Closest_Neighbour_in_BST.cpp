#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node.
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to find the maximum value in a binary search tree that is less than or equal to k

class Solution {
  public:
  int ans=-1;
  void Solve(Node* root,int k){
      if(root==NULL)
      return;
      if(root->data<=k){
          ans=root->data;
          Solve(root->right,k);
      }
      else
      Solve(root->left,k);
  }
    int findMaxFork(Node* root, int k) {
        
        Solve(root,k);
        return ans;
    }
};