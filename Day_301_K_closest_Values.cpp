#include <bits/stdc++.h>
using namespace std;

// Problem: Find k closest values to a target in a binary tree.
// Approach: Perform an inorder traversal to get sorted values, then use a max-heap to keep track of the k closest values.

// Steps:
// 1. Perform inorder traversal of the binary tree to get sorted values.
// 2. Use a max-heap (priority queue) to store pairs of (absolute difference, value).
// 3. For each value, push it into the max-heap. If the size exceeds k, pop the largest difference.
// 4. Extract values from the max-heap to get the k closest values.
// 5. Return the list of k closest values.

// Time Complexity: O(n log k) where n is the number of nodes in the tree.
// Space Complexity: O(n) for storing inorder traversal and O(k) for the max-heap.

class Solution {
  public:
    void getInorder(vector<int> &inorder,Node* root){
        if(root==NULL) return;
        getInorder(inorder,root->left);
        inorder.push_back(root->data);
        getInorder(inorder,root->right);
    }
    vector<int> getKClosest(Node* root, int target, int k) {
        vector<int> inorder;
        getInorder(inorder,root);
        int n=inorder.size();
        priority_queue<pair<int,int>> pq;
        for(int i=0;i<n;i++){
            pq.push({abs(inorder[i]-target),inorder[i]});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
        
    }
};