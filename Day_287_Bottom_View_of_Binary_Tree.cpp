#include <bits/stdc++.h>
using namespace std;

// Problem: Bottom View of Binary Tree
// Approach: We can use a level-order traversal (BFS) to explore the tree while keeping track of the horizontal distance of each node from the root.
//           We will use a map to store the nodes at each horizontal distance, and for each horizontal distance, we will keep updating the node to ensure that the bottom-most node is stored.

// Steps:
// 1. Use a queue to perform level-order traversal of the tree.
// 2. For each node, calculate its horizontal distance from the root and store it in a map.
// 3. Update the map for each horizontal distance to ensure that the bottom-most node is stored.
// 4. Finally, extract the nodes from the map in order of their horizontal distances to get the bottom view.

// Time Complexity: O(n) where n is the number of nodes in the tree (for traversing all nodes)
// Space Complexity: O(n) for the queue and map used in the traversal


/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    vector<int> bottomView(Node *root) {
         unordered_map<Node*,int>omap;
        map<int,vector<Node*>>mapForOrder;
        
        queue<Node*>q;
        q.push(root);
        omap[root]=0;
        mapForOrder[0].push_back(root);
        
        while(!q.empty()) {
            int counter=q.size();
            for(int i=0;i<counter;i++) {
                Node* vertex=q.front();
                q.pop(); 
                int location=omap[vertex];
                if(vertex->left!=NULL) {
                    q.push(vertex->left);
                    omap[vertex->left]=location-1;
                    mapForOrder[location-1].push_back(vertex->left);
                }
                
                if(vertex->right!=NULL) {
                    q.push(vertex->right);
                    omap[vertex->right]=location+1;
                    mapForOrder[location+1].push_back(vertex->right);
                }
            }
           
        }
        
        
        vector<int>ans;
        
        for(auto i:mapForOrder) {
            ans.push_back(i.second[i.second.size()-1]->data);
        }
        return ans;
        
    }
};