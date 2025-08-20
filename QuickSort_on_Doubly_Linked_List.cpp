class Solution {
  public:
    DLLNode* quickSort(DLLNode* head) {
        DLLNode* temp=l;
        while(temp!=h){
          if(temp->data>h->data){
              swap(temp->data,h->data);
          }
          temp=temp->next;
        }
        return temp;
    }
};