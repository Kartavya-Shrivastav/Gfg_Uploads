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