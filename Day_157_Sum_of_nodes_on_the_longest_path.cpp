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

// Function to find the sum of nodes on the longest path from root to leaf in a binary tree
class Solution {
  public:
  int longroot=0;
  void Solve(int &ans,Node* root,int sum,int idx){
      if(root==NULL){
          if(idx==longroot)
          ans=max(ans,sum);
          else if(idx>longroot)
          ans=sum,longroot=idx;
        return;  
      }
      Solve(ans,root->left,sum+root->data,idx+1);
      Solve(ans,root->right,sum+root->data,idx+1);
  }
    int sumOfLongRootToLeafPath(Node *root) {
       
       int ans=0;
       Solve(ans,root,0,0);
       return ans;
    }
};