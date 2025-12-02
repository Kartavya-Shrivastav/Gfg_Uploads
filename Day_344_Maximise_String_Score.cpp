#include <bits/stdc++.h>
using namespace std;

// Problem: Given a string s and a list of allowed character jumps, maximize the score of the string by jumping through characters.
// Approach: Use dynamic programming with precomputation of prefix sums and next occurrence indices to efficiently calculate the maximum score.

// Steps:
// 1. Create an adjacency matrix to represent allowed jumps between characters.
// 2. Precompute prefix sums of character ASCII values for quick range sum calculations.
// 3. Precompute the count of each character up to each index for quick frequency calculations.
// 4. Precompute the next occurrence indices for each character to facilitate jumps.
// 5. Use a recursive function with memoization to explore all possible jumps and calculate the maximum score.
// 6. Return the maximum score obtained.

// Time Complexity: O(n * 26^2) in the worst case, where n is the length of the string, due to the nested loops in the Solve function.
// Space Complexity: O(n * 26) for storing prefix sums, character counts, and next occurrence indices.

class Solution
{
public:
    vector<vector<int>> adj;
    vector<int> pref;
    vector<vector<int>> arr;
    vector<int> DP;
    vector<vector<int>> Next;
    int Solve(int i, string &s)
    {
        int n = s.size();
        if (i >= n)
            return 0;
        if (DP[i] != -1)
            return DP[i];
        int ans = 0;
        for (int j = 0; j < 26; j++)
        {
            if (adj[s[i] - 'a'][j] == 0)
                continue;
            int idx = upper_bound(Next[j].begin(), Next[j].end(), i) - Next[j].begin();
            if (idx == Next[j].size())
                continue;
            int x = Next[j][idx];
            int cost = pref[x] - ((i > 0) ? pref[i - 1] : 0);
            int cnt = arr[j][x] - ((i > 0) ? arr[j][i - 1] : 0);
            int p = int(char(j + 'a'));
            cost -= p * cnt;
            ans = max(ans, cost + Solve(x, s));
        }
        return DP[i] = ans;
    }
    int maxScore(string &s, vector<vector<char>> &jumps)
    {
        int n = s.size(), m = jumps.size();
        if (n == 1)
            return 0;
        adj.assign(26, vector<int>(26, 0));
        for (int i = 0; i < 26; i++)
            adj[i][i] = 1;
        for (int i = 0; i < m; i++)
        {
            int u = jumps[i][0] - 'a';
            int v = jumps[i][1] - 'a';
            adj[u][v] = 1;
        }
        pref.assign(n, 0);
        for (int i = 0; i < n; i++)
        {
            int x = int(s[i]);
            pref[i] = x;
            if (i > 0)
                pref[i] += pref[i - 1];
        }
        arr.assign(26, vector<int>(n, 0));
        for (int j = 0; j < n; j++)
        {
            int x = s[j] - 'a';
            for (int i = 0; i < 26; i++)
            {
                if (j > 0)
                    arr[i][j] += arr[i][j - 1];
                if (x == i)
                    arr[i][j]++;
            }
        }
        Next.assign(26, vector<int>());
        for (int i = 0; i < n; i++)
            Next[s[i] - 'a'].push_back(i);
        DP.assign(n, -1);
        int ans = Solve(0, s);
        return ans;
    }
};