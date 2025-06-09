#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class for BST
class Node{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

class Solution{
  public:
    vector<int> arr, leaf; // arr stores inorder traversal, leaf stores leaf node values
    
    // Inorder traversal to fill arr and leaf vectors
    void inorder(Node* node){
        if(!node)
            return;
        
        inorder(node->left);
        arr.push_back(node->data); // Store current node's data
        if(!node->left && !node->right)
            leaf.push_back(node->data); // Store leaf node's data
        inorder(node->right);
    }
    
    // Function to check if the BST contains a dead end
    bool isDeadEnd(Node *root)
    {
        arr = {0}; // Add 0 to handle the case for node with value 1
        leaf = {};
        inorder(root); // Fill arr and leaf vectors
        
        int j = 0;
        // Check for each leaf if it is a dead end
        for(int i = 1; i < arr.size() && j < leaf.size(); ++i){
            if(arr[i] == leaf[j]){
                // If previous and next values are consecutive to leaf, it's a dead end
                if(arr[i-1] == leaf[j] - 1 && arr[i+1] == leaf[j] + 1)
                    return true;
                ++j;
            }
        }
        
        return false; // No dead end found
    }
};