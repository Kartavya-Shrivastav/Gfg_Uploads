#include <bits/stdc++.h>
using namespace std;

// Problem: Reverse a Doubly Linked List
// Approach: We will swap the next and prev pointers for each node in the list.
// Finally, we need to return the new head of the reversed list.

// Steps:

// 1. Initialize a pointer to the current node (temp) as the head.
// 2. Traverse the list and for each node:
//    a. Swap the next and prev pointers.
//    b. Move to the next node (which is now the prev pointer).
// 3. Finally, return the new head (which is the last processed node).
// 4. Update the head pointer to the new head.
// 5. Update the tail pointer to the new tail (which is the old head).
// 6. Update the next pointer of the new tail to NULL.
// 7. Update the prev pointer of the new head to NULL.

// Time Complexity: O(n), where n is the number of nodes in the doubly linked list.
// Space Complexity: O(1), as we are not using any extra space.

/*
class Node {
  public:
    int data;
    Node *next;
    Node *prev;
    Node(int val) {
        data = val;
        next = NULL;
      a  prev = NULL;
    }
};

*/
class Solution {
  public:
    Node *reverse(Node *head) {
        Node * temp=head;
        while (temp){
            Node * node = temp->next;
            temp->next = temp->prev;
            temp->prev = node;
            if(!node) break;
            temp = node;
        }
        
        return temp;
    }
};