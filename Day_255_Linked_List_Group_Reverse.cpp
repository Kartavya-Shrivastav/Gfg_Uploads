#include <bits/stdc++.h>
using namespace std;

// Problem: Reverse nodes of a linked list in groups of size k
// Approach: Use iterative method to reverse k nodes and recursion for the rest of the list

// Steps:
// 1. Initialize pointers for previous, current, and next nodes.
// 2. Reverse the first k nodes of the linked list.
// 3. Recursively call the function for the next part of the list.
// 4. Connect the reversed part with the rest of the list.
// 5. Return the new head of the reversed list.

// Time Complexity: O(N)
// Space Complexity: O(N/k) due to recursion stack


/*
  Node is defined as
    struct node
    {
        int data;
        struct Node* next;

        Node(int x){
            data = x;
            next = NULL;
        }

    }*head;
*/

class Solution {
  public:
    Node *reverseKGroup(Node *head, int k) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        int count = 0;
        while(curr != NULL && count < k){
            next = curr->next;
            curr->next = prev;
            
            prev = curr;
            curr = next;
            count++;
        }
        
        if(next != NULL){
            head->next = reverseKGroup(next, k);
        }
        
        return prev;
        
        
        
    }
};
