#include <bits/stdc++.h>
using namespace std;

// Problem: Find the k-th smallest element in a BST
// Approach: Inorder Traversal of BST

// Steps:
// 1. Perform an inorder traversal of the BST to get the elements in sorted order.  
// 2. Store the elements in a vector during the traversal.
// 3. After the traversal, check if k is within the bounds of the vector size.
// 4. If k is valid, return the (k-1)th element from the vector (0-based index). Otherwise, return -1.

// Time Complexity: O(n) where n is the number of nodes in the BST.
// Space Complexity: O(n) for storing the elements in the vector and O(h) for the recursion stack where h is the height of the BST.

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
    void createArray(Node *root, vector<int>& temp){
        if(root == NULL){
            return;
        }
        
        createArray(root->left, temp);
        temp.push_back(root->data);
        createArray(root->right, temp);
        
        return;
    }
  public:
    int kthSmallest(Node *root, int k) {
        vector<int> temp;
        createArray(root, temp);        
        int n = temp.size();
        if(n < k){
            return -1;
        }
        return temp[k-1];
    }
};