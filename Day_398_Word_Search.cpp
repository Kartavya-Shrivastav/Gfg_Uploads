#include <bits/stdc++.h>
using namespace std;

// Problem: Word Search in a 2D Grid
// Given a 2D grid of characters and a word, check if the word exists in the grid.
// The word can be constructed from letters of sequentially adjacent cells, where "adjacent" cells are horizontally or vertically neighboring. The same letter cell may not be used more than once.

// Approach: Use Depth-First Search (DFS) to explore all possible paths in the grid starting from each cell.

// Steps:
// 1. Define a helper function that performs DFS to find the word in the grid.
// 2. If the current index of the word matches the length of the word, return true.
// 3. Check for out-of-bound indices and character mismatches.
// 4. Mark the current cell as visited by changing its value temporarily.
// 5. Recursively call the helper function for all four adjacent cells (up, down, left, right).
// 6. Backtrack by restoring the original value of the cell.
// 7. Iterate through each cell in the grid and call the helper function.
// 8. Return true if the word is found, otherwise return false.

// Time Complexity: O(N * 3^L) where N is the number of cells in the grid and L is the length of the word. Each cell can lead to 3 possible directions (excluding the direction we came from).
// Space Complexity: O(L) for the recursion stack, where L is the length of the word.

class Solution {
  public:
  bool findMatch(vector<vector<char>> &mat, string word, int x, int y, int wIdx) {
    int wLen = word.length();
    int n = mat.size();
      int m = mat[0].size();
  
    // Pattern matched
    if (wIdx == wLen)
        return true;

    // Out of Boundary
    if (x < 0 || y < 0 || x >= n || y >= m)
        return false;

    // If grid matches with a letter while
    // recursion
    if (mat[x][y] == word[wIdx]) {

        // Marking this cell as visited
        char temp = mat[x][y];
        mat[x][y] = '#';

        // finding subpattern in 4 directions
        bool res = findMatch(mat, word, x - 1, y, wIdx + 1) ||
                   findMatch(mat, word, x + 1, y, wIdx + 1) ||
                   findMatch(mat, word, x, y - 1, wIdx + 1) ||
                   findMatch(mat, word, x, y + 1, wIdx + 1);

        // marking this cell as unvisited again
        mat[x][y] = temp;
        return res;
    }
      
      // Not matching then return false
    return false;
}
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        int wLen = word.length();
    int n = mat.size();
      int m = mat[0].size();
  
    // if total characters in matrix is
    // less than word length
    if (wLen > n * m)
        return false;

    // Traverse in the grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {

            // If first letter matches, then recur and check
            if (mat[i][j] == word[0]){
                if (findMatch(mat, word, i, j, 0))
                    return true;
            }
        }
    }
    return false;
    }
};