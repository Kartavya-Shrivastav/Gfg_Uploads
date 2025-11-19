#include <bits/stdc++.h>
using namespace std;

// Problem: Path With Minimum Effort
// Approach: Dijkstra's Algorithm

// Steps:
// 1. Use a priority queue to explore the matrix cells based on the minimum effort required
// 2. Maintain a distance matrix to track the minimum effort to reach each cell
// 3. Explore all four possible directions from the current cell and update the effort accordingly
// 4. Return the minimum effort required to reach the bottom-right cell

// Time Complexity: O(N*M*log(N*M)) where N and M are the dimensions of the matrix
// Space Complexity: O(N*M) for the distance matrix and priority queue

class Solution {
  public:
    struct Cell {
        int x, y, cost;
        Cell(int _x, int _y, int _cost) : x(_x), y(_y), cost(_cost) {}
    };

    int minCostPath(vector<vector<int>>& mat) {
        if (mat.empty() || mat[0].empty()) return 0;

        int n = mat.size(), m = mat[0].size();

        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));

        auto cmp = [](const Cell& a, const Cell& b) {
            return a.cost > b.cost;
        };

        priority_queue<Cell, vector<Cell>, decltype(cmp)> pq(cmp);

        dist[0][0] = 0;
        pq.push(Cell(0, 0, 0));

        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};

        while (!pq.empty()) {
            Cell cur = pq.top();
            pq.pop();

            if (cur.x == n - 1 && cur.y == m - 1) 
                return cur.cost;

            if (cur.cost > dist[cur.x][cur.y])
                continue;

            for (int i = 0; i < 4; i++) {
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];

                if (nx < 0 || ny < 0 || nx >= n || ny >= m)
                    continue;

                int step = abs(mat[cur.x][cur.y] - mat[nx][ny]);
                int newCost = max(cur.cost, step);

                if (newCost < dist[nx][ny]) {
                    dist[nx][ny] = newCost;
                    pq.push(Cell(nx, ny, newCost));
                }
            }
        }

        return dist[n - 1][m - 1] == INT_MAX ? -1 : dist[n - 1][m - 1];
    }
};
