class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
    vector<int> indexes(m, 0);
    for (int i = 0; i < m; i++) {
        pq.push({mat[i][0], i});
    }
    int ans = 0;
    while (k--) {
        auto top = pq.top();
        pq.pop();
        ans = top.first;
        int row = top.second;
        indexes[row]++;
        if (indexes[row] < n) {
            pq.push({mat[row][indexes[row]], row});
        }
    }
    return ans;
}
};