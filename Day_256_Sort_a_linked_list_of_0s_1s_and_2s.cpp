#include <bits/stdc++.h>
using namespace std;

// Problem: Sort a linked list of 0s, 1s and 2s
// Approach: Use a multiset to store the values and then overwrite the linked list

// Steps:
// 1. Traverse the linked list and store the values in a multiset.
// 2. Traverse the linked list again and overwrite the values from the multiset.
// 3. Return the head of the modified linked list.

// Time Complexity: O(N log N) due to multiset insertion
// Space Complexity: O(N) for storing values in the multiset


/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/

class Solution {
  public:
   Node* segregate(Node* h) {
        multiset<int> s;
        Node *p = h;
        
        while(p) s.insert(p->data), p = p->next;
        
        p = h;
        for(int i : s) p->data = i, p = p->next;
        
        return h;
}
};
