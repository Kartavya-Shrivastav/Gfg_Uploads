class Solution {
  public:
    int minThrow(int N, int arr[]) {
        unordered_map<int,int> mpp;
        for(int i = 1; i < 2*N; i += 2){
            mpp[arr[i-1]] = arr[i];  
        }
        
        vector<int> vis(31, 0);  
        vis[1] = 1;
        queue<int> q;
        q.push(1);
        
        int count = 0;
        while(!q.empty()){
            int size = q.size();
            count++;
            for(int i = 0; i < size; i++){
                int node = q.front(); q.pop();
                
                for(int dice = 1; dice <= 6 && (node + dice) <= 30; dice++){
                    int adjNode = node + dice;
                    
                    if(mpp.count(adjNode)) {
                        adjNode = mpp[adjNode];  
                    }
                    
                    if(!vis[adjNode]){
                        if(adjNode == 30) return count;
                        vis[adjNode] = 1;  
                        q.push(adjNode);
                    }
                }
            }
        }
        return -1;
    }
};