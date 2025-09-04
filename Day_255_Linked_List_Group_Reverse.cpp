
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
