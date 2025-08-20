// Problem: Implement quicksort partitioning for a doubly linked list.
// Approach: Use the last node as a pivot and traverse the list from the beginning, swapping values greater than the pivot to ensure
//           correct partitioning before recursive calls.

// Steps:
// 1. Choose the last node (`h`) as the pivot.
// 2. Initialize a pointer `temp` at the first node (`l`).
// 3. Traverse nodes until `temp` reaches the pivot.
// 4. If the current node’s value is greater than the pivot’s value, swap them.
// 5. Continue traversal until the pivot node is reached.
// 6. Return the partition node (final `temp`) to be used in recursive quicksort calls.

// Time Complexity: O(n) for partitioning a list of n nodes in one pass.
// Space Complexity: O(1) since only pointers are used without extra memory.


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