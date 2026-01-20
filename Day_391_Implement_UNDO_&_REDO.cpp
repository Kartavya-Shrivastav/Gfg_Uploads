#include <bits/stdc++.h>
using namespace std;

// Problem Statement: Implement a simple text editor that supports the following operations:
// 1. Append a character to the end of the document.
// 2. Undo the last append operation.
// 3. Redo the last undone append operation.
// Approach: We can maintain a vector to store the characters of the document and an integer to track the current position in the document. The append operation adds a character to the end of the vector and updates the current position. The undo operation decrements the current position if possible, effectively removing the last appended character from the current view of the document. The redo operation increments the current position if possible, restoring the last undone character. The read operation constructs and returns the current state of the document as a string.

// Steps:
// 1. Initialize an empty vector to store characters and an integer to track the current position.
// 2. For the append operation, add the character to the vector and update the current position.
// 3. For the undo operation, decrement the current position if it's greater than or equal to zero.
// 4. For the redo operation, increment the current position if it's less than the size of the vector minus one.
// 5. For the read operation, construct a string from the vector up to the current position and return it.

// Time Complexity: O(1) for append, undo, and redo operations; O(n) for read operation where n is the number of characters in the current document.
// Space Complexity: O(m) where m is the total number of characters appended to the document.


class Solution {
    int curr = -1;
    vector<char>doc;
    
  public:
    void append(char x) {
        while(curr < (int)doc.size()-1){
            doc.pop_back();
        }
        
        doc.push_back(x);
        curr++;
        
    }

    void undo() {
        if(curr >= 0){
            curr--;
        }
    }

    void redo() {
        if(curr < (int)doc.size()-1){
            curr++;
        }
    }

    string read() {
        string res = "";
        for(int i=0;i<=curr;i++){
            res += doc[i];
        }
        return res;
    }
};