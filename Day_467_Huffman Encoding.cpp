#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a string s and a vector of frequencies f, where f[i] is the frequency of the character s[i], generate the Huffman codes for each character in s based on their frequencies.
Approach: We can use a priority queue (min-heap) to build the Huffman tree. We start by creating a node for each character and its frequency and push them into the priority queue. Then, we repeatedly combine the two nodes with the smallest frequencies until only one node (the root of the Huffman tree) remains. During this process, we create new parent nodes with the combined frequency and keep track of the indices to ensure that we can generate the correct codes. Finally, we perform a depth-first search (DFS) on the Huffman tree to generate the binary codes for each character.

Steps:
1. Create a priority queue to store the nodes of the Huffman tree, where each node contains the frequency, index, and pointers to left and right children.  
2. Push a node for each character and its frequency into the priority queue.
3. While there are more than one node in the priority queue:
    a. Pop the two nodes with the smallest frequencies.
    b. Create a new parent node with the combined frequency and the minimum index of the two nodes.
    c. Set the left child of the parent node to the first popped node and the right child to the second popped node.
    d. Push the parent node back into the priority queue.
4. After the loop, the remaining node in the priority queue is the root of the Huffman tree.
5. Perform a DFS on the Huffman tree to generate the binary codes for each character.

Time Complexity: O(n log n) for building the Huffman tree, where n is the number of characters. The DFS traversal takes O(n) time, so the overall time complexity is O(n log n).
Space Complexity: O(n) for storing the nodes of the Huffman tree and the resulting codes.
*/


class Solution {
  public:
  
    class Node{
      public:
        int f;
        int idx;
        Node *left, *right;
        
        Node(int f, int idx){
            this->f = f;
            this->idx = idx;
            left = right = NULL;
        }
    };
    
    struct cmp{
        bool operator()(Node* a, Node* b){
            if(a->f == b->f)
                return a->idx > b->idx;
            return a->f > b->f;
        }
    };
    
    void dfs(Node* root, string s, vector<string> &ans){
        
        if(!root) return;
        
        if(!root->left && !root->right){
            ans.push_back(s);
            return;
        }
        
        dfs(root->left, s + "0", ans);
        dfs(root->right, s + "1", ans);
    }

    vector<string> huffmanCodes(string &s, vector<int> f) {
        
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        int n = s.size();
        
        for(int i = 0; i < n; i++){
            pq.push(new Node(f[i], i));
        }
        
        if(n == 1) return {"0"};
        
        while(pq.size() > 1){
            
            Node* l = pq.top();
            pq.pop();
            
            Node* r = pq.top();
            pq.pop();
            
            Node* parent = new Node(l->f + r->f, min(l->idx, r->idx));
            parent->left = l;
            parent->right = r;
            
            pq.push(parent);
        }
        
        vector<string> ans;
        dfs(pq.top(), "", ans);
        
        return ans;
    }
};