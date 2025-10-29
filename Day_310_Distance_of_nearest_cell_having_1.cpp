
class Solution {
  public:
    // Function to find distance of nearest 1 in the grid for each cell.
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // Code here
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n,0));
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        for(int i = 0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({{i,j},0});
                    vis[i][j] = 1;
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first.first;
            int y = q.front().first.second;
            int steps = q.front().second;
            q.pop();
            dist[x][y] = steps;
            vector<pair<int,int>> dir = {{0,1},{1,0},{0,-1},{-1,0}};
            for(auto d: dir){
                int nx = x + d.first, ny = y + d.second;
                if(nx>=0 && nx<m && ny>=0 && ny<n && vis[nx][ny] == 0){
                    vis[nx][ny] = 1;
                    dist[nx][ny] = steps + 1;
                    q.push({{nx,ny}, steps+1});
                }
            }
        }
        return dist;
    }
};