#include <bits/stdc++.h>
using namespace std;

// Problem: Flattening a Linked List
// Approach: Using a priority queue to flatten the linked list

// Steps:
// 1. Use a priority queue to store the nodes of the linked list based on their data values.
// 2. Initialize a dummy node to help in constructing the flattened list.
// 3. Traverse the linked list and push each node into the priority queue.
// 4. Pop nodes from the priority queue and link them together in the flattened list.
// 5. If a node has a bottom pointer, push the bottom node into the priority queue.
// 6. Continue until all nodes are processed.

// Time Complexity: O(N log N) where N is the total number of nodes in the linked list
// Space Complexity: O(N) for the priority queue

struct Node{
    int data;
    struct Node * next;
    struct Node * bottom;

    Node(int x){
        data = x;
        next = NULL;
        bottom = NULL;
    }

};

class Solution {
    public:
        Node *flatten(Node *root){
                // Min-heap to store nodes based on their data values
                priority_queue<pair<int, Node*> , vector<pair<int, Node*>> , greater<pair<int, Node*>>> pq;
                
                // Push all nodes from the top-level linked list into the priority queue
                Node* temp = root;
                while(temp){
                        pq.push(make_pair(temp->data, temp));
                        temp = temp->next;
                }
                
                // Dummy node to help build the flattened list
                Node* dummy = new Node(-1);
                Node* tail = dummy;
                
                // Process nodes in sorted order
                while(!pq.empty()){
                        pair<int, Node*> temp = pq.top();
                        pq.pop();
                        Node* node = temp.second;
                        
                        // Link the current node to the flattened list
                        tail->bottom = node;
                        
                        // If the current node has a bottom node, push it into the priority queue
                        if(temp.second->bottom){
                                pq.push(make_pair(temp.second->bottom->data, temp.second->bottom));
                        }
                        
                        // Move the tail pointer
                        tail = node;
                }
                
                // Return the head of the flattened list
                return dummy->bottom;
        }
};