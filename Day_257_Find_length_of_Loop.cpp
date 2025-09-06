#include <bits/stdc++.h>
using namespace std;

// Problem: Find length of loop in linked list
// Approach: Use a map to store the nodes and their positions, if a node is revisited, calculate the loop length

// Steps:
// 1. Traverse the linked list and store each node in a map with its position.
// 2. If a node is revisited, calculate the loop length using the current position and the stored position.
// 3. If the end of the list is reached without revisiting any node, return 0 (no loop).
// 4. Return the length of the loop if found.

// Time Complexity: O(N) where N is the number of nodes in the linked list
// Space Complexity: O(N) for storing nodes in the map


/*
class Node {
 public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    int lengthOfLoop(Node *head) {
        if(head==nullptr || head->next==nullptr) return 0;
        map<Node*,int> mp;
        int i=1;
        while(head!=nullptr)
        {
           if(mp.find(head)!=mp.end()) return i-mp[head];
           mp[head]=i;
           i++;
           head=head->next;
        }
        return 0;
    }
};