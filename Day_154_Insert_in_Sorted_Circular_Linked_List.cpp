#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        // Case 1: Empty list
        if (!head) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;

        // Special case: new data should be inserted before head
        if (data <= head->data) {
            // Find last node
            while (curr->next != head) {
                curr = curr->next;
            }

            // Insert new node before head and update links
            curr->next = newNode;
            newNode->next = head;
            return newNode; // newNode is new head
        }

        // General case: find position to insert
        Node* prev = head;
        curr = head->next;

        while (curr != head && curr->data < data) {
            prev = curr;
            curr = curr->next;
        }

        // Insert between prev and curr
        prev->next = newNode;
        newNode->next = curr;

        return head;
    }
};