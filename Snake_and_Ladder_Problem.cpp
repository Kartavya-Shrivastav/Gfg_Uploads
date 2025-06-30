#include <bits/stdc++.h>
using namespace std;

// Problem: Snake and Ladder Problem
// Approach: Use BFS to find the minimum number of dice throws required to reach the end of the board.

// Steps:
// 1. Create a mapping of snakes and ladders using a hash map.
// 2. Initialize a visited array to keep track of visited cells.
// 3. Use a queue to perform BFS starting from cell 1.
// 4. For each cell, simulate the dice rolls (1 to 6) and check the resulting cell.
// 5. If the resulting cell has a snake or ladder, move to the corresponding cell.
// 6. If the resulting cell is not visited, mark it as visited and add it to the queue.

// Time Complexity: O(N), where N is the number of cells (30 in this case).
// Space Complexity: O(N), for the visited array and queue.

class Solution {
    public:
        // Function to find the minimum number of dice throws required to reach the last cell (30)
        int minThrow(int N, int arr[]) {
                unordered_map<int,int> mpp; // Map to store snakes and ladders
                for(int i = 1; i < 2*N; i += 2){
                        mpp[arr[i-1]] = arr[i];  // Map start to end for each snake/ladder
                }
                
                vector<int> vis(31, 0);  // Visited array for cells 1 to 30
                vis[1] = 1;              // Start from cell 1
                queue<int> q;
                q.push(1);               // Push starting cell to queue
                
                int count = 0;           // Number of dice throws
                while(!q.empty()){
                        int size = q.size();
                        count++;             // Increment dice throw count for each level
                        for(int i = 0; i < size; i++){
                                int node = q.front(); q.pop();
                                
                                // Try all possible dice throws (1 to 6)
                                for(int dice = 1; dice <= 6 && (node + dice) <= 30; dice++){
                                        int adjNode = node + dice;
                                        
                                        // If there's a snake or ladder, move to its destination
                                        if(mpp.count(adjNode)) {
                                                adjNode = mpp[adjNode];  
                                        }
                                        
                                        // If not visited, mark as visited and add to queue
                                        if(!vis[adjNode]){
                                                if(adjNode == 30) return count; // Reached the end
                                                vis[adjNode] = 1;  
                                                q.push(adjNode);
                                        }
                                }
                        }
                }
                return -1; // If not reachable
        }
};