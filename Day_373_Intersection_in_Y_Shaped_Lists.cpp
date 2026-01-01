#include <bits/stdc++.h>
using namespace std;

// Problem: Given two Y shaped linked lists, find the point where they intersect.
// Approach: Use two pointers to traverse both lists. When one pointer reaches the end, redirect it to the head of the other list.

// Steps:
// 1. Initialize two pointers, one for each list.
// 2. Traverse both lists. When a pointer reaches the end of its list, redirect it to the head of the other list.
// 3. Continue until the two pointers meet. The meeting point is the intersection node.
// 4. If there is no intersection, both pointers will eventually become NULL.
// 5. Return the intersection node or NULL if there is no intersection.

// Time Complexity: O(N + M), where N and M are the lengths of the two lists.
// Space Complexity: O(1)

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

class Solution {
  public:
    Node* intersectPoint(Node* head1, Node* head2) {
        if (head1 == NULL || head2 == NULL) 
            return NULL;
        Node *x1 = head1;
        Node *x2 = head2;
        while (x1 != x2) {
            x1 = (x1 == nullptr) ? head2 : x1->next;
            x2 = (x2 == nullptr) ? head1 : x2->next;
        }
        return x2;
    }
};