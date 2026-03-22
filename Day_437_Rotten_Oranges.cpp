
class Solution {
  public:
    int orangesRot(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair< pair<int,int>, int> > q;
        vector<vector<int>> vis(n, vector<int>(m));
        int freshCount=0;
        
        for(int r=0; r<n; r++){
            for(int c=0; c<m; c++){
                if(grid[r][c] == 2){
                    q.push({ {r,c}, 0 });
                    vis[r][c] = 1;
                }
                else if(grid[r][c] == 1) freshCount++;
            }
        }

        vector<pair<int,int>> adjNodes = {{-1,0}, {0,1}, {1,0}, {0,-1}};
        int time=0;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            int r = node.first.first;
            int c = node.first.second;
            int t = node.second;
            time = max(time, t);

            for(auto p: adjNodes){
                int nr = r + p.first;
                int nc = c + p.second;

                if(nr>=0 && nr<n && nc>=0 && nc<m && vis[nr][nc]==0 && grid[nr][nc]==1){
                    q.push({ {nr,nc}, t+1 });
                    vis[nr][nc] = 1;
                    freshCount--;
                }
            }
        }

        if(freshCount != 0) return -1;

        return time;
    }
};