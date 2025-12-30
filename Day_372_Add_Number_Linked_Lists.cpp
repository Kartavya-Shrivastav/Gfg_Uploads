#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// Problem: Add Two Numbers Represented by Linked Lists
// Approach: Reverse Linked Lists and Add Digits

// Steps:
// 1. Reverse both linked lists to facilitate addition from least significant digit.
// 2. Initialize carry to 0 and create a new linked list to store the result.
// 3. Traverse both linked lists, adding corresponding digits along with carry.
// 4. If one linked list is longer, continue adding its remaining digits with carry.
// 5. If there's a carry left after processing both lists, add a new node with the carry.
// 6. Reverse the resultant linked list to restore the original order.

// Time Complexity: O(max(N, M)) where N and M are lengths of the two linked lists
// Space Complexity: O(max(N, M)) for the resultant linked list
class Solution {
  public:
    Node* reverseLink(Node* head, Node* prev = nullptr) {
      if (head->next == nullptr) {
        if (head == nullptr) {
          return head;
        }
        head->next = prev;
        return head;
      }
    
      Node* next = head->next;
      head->next = prev;
      return reverseLink(next, head);
    }
    
    Node* removeTrailZero(Node* head) {
      if (head == nullptr) {
        return head;
      }
    
      auto res = removeTrailZero(head->next);
    
      if (res == nullptr && head->data == 0) {
        delete head;
        return nullptr;
      }
    
      head->next = res;
      return head;
    }
    
    Node* addTwoLists(Node* head1, Node* head2) {
      head1 = reverseLink(head1);
      head2 = reverseLink(head2);
    
      int carry = 0;
      Node *head = nullptr, *temp = nullptr;
      while (head1 != nullptr && head2 != nullptr) {
        int sum = head1->data + head2->data + carry;
        head1 = head1->next;
        head2 = head2->next;
    
        if (head == nullptr) {
          head = new Node(sum % 10);
          temp = head;
          carry = sum / 10;
          continue;
        }
        temp->next = new Node(sum % 10);
        temp = temp->next;
        carry = sum / 10;
      }
    
      while (head1 != nullptr) {
        int sum = head1->data + carry;
        temp->next = new Node(sum % 10);
        temp = temp->next;
        carry = sum / 10;
        head1 = head1->next;
      }
      while (head2 != nullptr) {
        int sum = head2->data + carry;
        temp->next = new Node(sum % 10);
        temp = temp->next;
        carry = sum / 10;
        head2 = head2->next;
      }
    
      if (carry) {
        temp->next = new Node(carry);
      }
    
      return reverseLink(removeTrailZero(head));
    }

};