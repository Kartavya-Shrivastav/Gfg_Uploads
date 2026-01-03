#include <bits/stdc++.h>
using namespace std;    

// Problem: Given a linked list where every node has two pointers: 'next' and 'bottom'. The 'next' pointer points to the next node in the list, and the 'bottom' pointer
// points to a linked list where each node is sorted in ascending order. The task is to flatten the linked list into a single sorted linked list using the 'bottom' pointers.

// Approach: Flattening a Linked List Using a Min-Heap (Priority Queue).

// Steps:
// 1. Create a min-heap (priority queue) to store the nodes based on their data values.
// 2. Initialize the min-heap with the head node of the main linked list.
// 3. While the min-heap is not empty, extract the minimum node from the heap.
// 4. If the extracted node has a 'next' pointer, push the 'next' node into the min-heap.
// 5. If the extracted node has a 'bottom' pointer, push the 'bottom' node into the min-heap.
// 6. Link the extracted nodes using their 'bottom' pointers to form the flattened linked list.

// Time Complexity: O(N log k), where N is the total number of nodes and k is the number of linked lists.
// Space Complexity: O(k) for the min-heap storing k nodes at any time.

class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

class Solution {
  public:
    struct Compare {
        bool operator()(Node* a, Node* b) {
            return a->data > b->data;
        }
    };
    
    Node *flatten(Node *root) {
        priority_queue<Node*, vector<Node*>, Compare> pq;\
        Node* temp=root;
        Node* ans=temp;
        pq.push(temp);
        while(!pq.empty())
        {
            Node* curr = pq.top();
            pq.pop();
            if(curr->next)
            pq.push(curr->next);
            if(curr->bottom)
            pq.push(curr->bottom);
            if(curr==root)continue;
            temp->bottom=curr;
            temp=temp->bottom;
            
            
            
        }
        return ans;
    }
};