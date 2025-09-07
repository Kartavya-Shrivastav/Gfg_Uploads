#include <bits/stdc++.h>
using namespace std;

// Problem: Merge K sorted linked lists
// Approach: Use a helper function to merge two sorted linked lists and iteratively merge all K lists

// Steps:
// 1. Create a helper function `mergeTwo` that merges two sorted linked lists.
// 2. Initialize a result pointer to NULL.
// 3. Iterate through each linked list in the array and merge it with the result using `mergeTwo`.
// 4. Return the merged linked list.

// Time Complexity: O(N*K) where N is the average number of nodes in each linked list and K is the number of linked lists
// Space Complexity: O(1) as we are not using any extra space for merging


/*Linked list Node structure

struct Node
{
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
  
    Node* mergeTwo(Node* head1, Node* head2){
        Node* dummyHead = new Node(-1);
        Node* curr = dummyHead;
        
        while(head1 != NULL && head2 != NULL){
            if(head1->data <= head2->data){
                curr->next = head1;
                head1 = head1->next;
            }
            else{
                curr->next = head2;
                head2 = head2->next;
            }
            
            curr = curr->next;
        }
        
        if(head1 != NULL){
            curr->next = head1;
        }
        else{
            curr->next = head2;
        }
        
        return dummyHead->next;
    }
  
    Node* mergeKLists(vector<Node*>& arr) {
        Node* res = NULL;
        for(Node* node : arr){
            res = mergeTwo(res, node);
        }
        
        return res;
    }
};