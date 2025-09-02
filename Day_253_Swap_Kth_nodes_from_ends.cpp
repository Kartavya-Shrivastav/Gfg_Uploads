#include <bits/stdc++.h>
using namespace std;

// Problem: Swap Kth node from beginning and end in a linked list.
// Approach: Find the Kth node from the beginning and the Kth node from the end, then swap their values.

// Steps:
// 1. Find the Kth node from the beginning.
// 2. Find the Kth node from the end.
// 3. Swap their values.
// 4. Return the head of the modified list.

// Time Complexity: O(n) 
// Space Complexity: O(1)

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        Node * temp = head;
        int count = 1;
        
        while(temp->next!= NULL){ count++; temp = temp->next;}
        
        if(count<k) return head;
        
        temp = head;
        for(int i=1; i<k; i++) temp = temp->next;
        
        Node * a = head;
        for(int i=1; i < count-k+1; i++) a = a->next;
        
        swap(a->data, temp->data);
        
        return head;
    }
};