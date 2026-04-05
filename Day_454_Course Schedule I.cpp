#include <bits/stdc++.h>
using namespace std;

/*
Problem: There are a total of n courses you have to take, labeled from 0 to n-1. Some courses may have prerequisites, represented as a list of pairs where each pair [a, b] indicates that you must take course b before course a. Determine if it is possible to finish all courses given the prerequisites.
Approach: This problem can be solved using a depth-first search (DFS) approach to detect cycles in the directed graph formed by the courses and their prerequisites. We will represent the courses and their prerequisites as an adjacency list. We will also maintain a state array to track the visitation status of each course:

Steps:
1. Create an adjacency list to represent the graph of courses and their prerequisites.
2. Create a state array to track the visitation status of each course:  
    - 0: unvisited
    - 1: visiting (currently in the recursion stack)
    - 2: visited (fully processed)
3. Iterate through each course from 0 to n-1:
    - If the course is unvisited, start a DFS traversal from this course:
        a. Mark the course as visiting (state = 1).
        b. For each prerequisite of this course, check its state:
            i. If the prerequisite is currently being visited (state = 1), it means we have found a cycle, and we can return false.
            ii. If the prerequisite is unvisited (state = 0), recursively perform DFS on that prerequisite.
        c. After processing all prerequisites, mark the course as visited (state = 2).
4. If we finish processing all courses without finding a cycle, return true.

Time Complexity: O(V + E) where V is the number of courses and E is the number of prerequisites, as we will visit each course and each prerequisite at most once during the DFS traversal.
Space Complexity: O(V + E) for the adjacency list and the state array, and O(V) for the recursion stack in the worst case when the graph is a single long chain. In general, the space complexity is O(V + E).
*/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }
        
        vector<int> state(n, 0);  
        
        for (int i = 0; i < n; ++i) {
            if (state[i] != 0) continue;
            
            stack<pair<int, int>> st;  
            st.push({i, 0});
            state[i] = 1;
            
            while (!st.empty()) {
                auto& [node, idx] = st.top();
                
                if (idx == adj[node].size()) {
                    state[node] = 2;
                    st.pop();
                    continue;
                }
                
                int next = adj[node][idx++];
                
                if (state[next] == 1) return false;  
                if (state[next] == 0) {
                    state[next] = 1;
                    st.push({next, 0});
                }
            }
        }
        
        return true;
    }
};