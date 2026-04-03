#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary search tree (BST) and a key, find the predecessor and successor of the key in the BST. The predecessor of a key is the largest value in the BST that is smaller than the key, and the successor of a key is the smallest value in the BST that is greater than the key.
Approach: To solve this problem, we can utilize the properties of a binary search tree. We will traverse the tree starting from the root and compare the key with the current node's value. If the current node's value is greater than the key, we will update the successor and move to the left child. If the current node's value is less than or equal to the key, we will update the predecessor and move to the right child. We will continue this process until we reach a null node.

Steps:
1. Initialize two pointers, one for the predecessor and one for the successor, and set them to null.
2. Start traversing the tree from the root node.
3. For each node, compare its value with the key:
    - If the node's value is greater than the key, update the successor pointer to the current node and move to the left child.
    - If the node's value is less than or equal to the key, update the predecessor pointer to the current node and move to the right child.
4. Continue this process until you reach a null node.
5. Return the predecessor and successor pointers.

Time Complexity: O(H) where H is the height of the tree, as we may need to traverse from the root to a leaf node in the worst case. In a balanced BST, this would be O(log N) where N is the number of nodes in the tree.
Space Complexity: O(1) for the pointers used to store the predecessor and successor, and O(H) for the recursive call stack in the worst case (skewed tree). In a balanced BST, this would be O(log N).
*/

class Solution {
  public:
    vector<Node*> findPreSuc(Node* root, int key) {
        // code here
        Node*ans1 = NULL;
        Node*ans2 = NULL;
        Node*temp = root;
        
        while(temp){
            if(temp->data > key)ans1=temp;
            if(temp->data <= key)temp = temp->right;
            else temp=temp->left;
        }
        
        
        temp=root;
        while(temp){
            if(temp->data < key)ans2=temp;
            if(temp->data < key)temp = temp->right;
            else temp=temp->left;
        }
        
        return {ans2,ans1};
    }
};