class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, pair<int,int>>>pq;
        for(auto it : points){
            pq.push({sqrt((it[0]*it[0])+(it[1] * it[1])), {it[0], it[1]}});
            while(pq.size() > k)pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.size()){
            ans.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};