#include <bits/stdc++.h>
using namespace std;

// Problem: Sort a linked list using Merge Sort
// Approach: Convert linked list to array, sort the array, and then update the linked list

// Steps:
// 1. Traverse the linked list and store the values in a vector.
// 2. Sort the vector.
// 3. Traverse the linked list again and update the node values with the sorted values from the vector.
// 4. Return the head of the sorted linked list.

// Time Complexity: O(N log N) due to sorting the array
// Space Complexity: O(N) for storing the values in the vector

/*
The structure of linked list is the following

struct Node {
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
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        Node *temp = head;
        vector<int> v;
        while(temp!=NULL){
            v.push_back(temp->data);
            temp = temp->next;
        }
        sort(v.begin(),v.end());
        temp = head;
        int i = 0;
        while(temp!=NULL && i<v.size()){
            temp->data = v[i];
            temp = temp->next;
            i++;
        }
        return head;
    }
};


