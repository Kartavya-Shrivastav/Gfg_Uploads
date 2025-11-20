#include <bits/stdc++.h>
using namespace std;

// Problem: Make Strings Equal
// Approach: Floyd-Warshall Algorithm

// Steps:
// 1. Create a distance matrix to represent the cost of transforming one character to another
// 2. Initialize the distance matrix with given transformation costs
// 3. Use the Floyd-Warshall algorithm to compute the minimum transformation costs between all pairs of characters
// 4. For each character position in the two strings, find the minimum cost to make them equal
// 5. Sum up the minimum costs for all character positions
// 6. If any position cannot be made equal, return -1

// Time Complexity: O(26^3 + N) where N is the length of the strings
// Space Complexity: O(26^2) for the distance matrix

class Solution {
public:
    int minCost(string &s, string &t, vector<vector<char>> &transform,vector<int> &cost) {
        const int INF = 1e9;
        vector<vector<int>> dist(26, vector<int>(26, INF));
        for (int i = 0; i < 26; i++) dist[i][i] = 0;
        for (int i = 0; i < transform.size(); i++) {
            int u = transform[i][0] - 'a';
            int v = transform[i][1] - 'a';
            dist[u][v] = min(dist[u][v], cost[i]);
        }
        for (int k = 0; k < 26; k++)
            for (int i = 0; i < 26; i++)
                for (int j = 0; j < 26; j++)
                    if (dist[i][k] < INF && dist[k][j] < INF)
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
        long long ans = 0;
        for (int i = 0; i < s.size(); i++) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            if (a == b) continue;
            int best = INF;
            for (int c = 0; c < 26; c++) {
                if (dist[a][c] < INF && dist[b][c] < INF) {
                    best = min(best, dist[a][c] + dist[b][c]);
                }
            }
            if (best == INF) return -1;
            ans += best;
        }
        return ans;
    }
};