#include <bits/stdc++.h>
using namespace std;

/*
Problem: Given a binary tree and a target node, find the minimum time required to burn the entire tree if the fire starts from the target node. The fire spreads to adjacent nodes (parent and children) every minute.
Approach: To solve this problem, we can use a breadth-first search (BFS) approach. We will first find the target node in the tree and then perform a BFS starting from that node to simulate the burning process. We will keep track of the time taken to burn all nodes using a queue.

Steps:
1. Traverse the tree to find the target node and also keep track of the parent nodes for each node in a map.
2. Once we have the target node, we will perform a BFS starting from that node. 
3. We will use a queue to keep track of the nodes that are currently burning and a map to keep track of the nodes that have already been burned.
4. For each node that is burning, we will add its adjacent nodes (left child, right child, and parent) to the queue if they have not been burned yet.
5. We will keep track of the time taken to burn all nodes by counting the levels of BFS.

Time Complexity: O(N) where N is the number of nodes in the tree, as we visit each node once to find the target and once to simulate the burning process.       
Space Complexity: O(N) in the worst case for the queue and the map to store parent nodes and burned nodes.
*/  

class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

class Solution {
  public:
    int minTime(Node* root, int target) {
        // code here
         map<Node*, Node*>parents;
        queue<Node*>q1;
        q1.push(root);
        Node* targetnode = NULL;
        while(!q1.empty())
        {
            int s = q1.size();
            for(int i=0;i<s;i++)
            {
                
                Node* node = q1.front();
                q1.pop();
                
                // get here target node by using target value
                if(node->data == target)targetnode = node;
                
                if(node->left)
                {
                    parents[node->left] = node;
                    q1.push(node->left);
                }
                if(node->right)
                {
                    parents[node->right] = node;
                    q1.push(node->right);
                }
                
            }
            
        }
            
        map<Node*, bool>burned;
        queue<Node*>q2;
        q2.push(targetnode);
        burned[targetnode] = true;
        int required_sec = -1;
            
        while(!q2.empty())
        {
            int s = q2.size();
            required_sec++;
            for(int i=0;i<s;i++)
            {
                Node* current = q2.front();
                q2.pop();
                
                if(!burned[current->left]&&current->left)
                {
                    q2.push(current->left);
                    burned[current->left] = true;
                }
                
                if(!burned[current->right]&&current->right)
                {
                    q2.push(current->right);
                    burned[current->right] = true;
                }
                
                if(!burned[parents[current]]&&parents[current])
                {
                    q2.push(parents[current]);
                    burned[parents[current]] = true;
                }
            }
        }
                
        return required_sec;  
    }
};