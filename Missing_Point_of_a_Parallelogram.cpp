
class Solution {
  public:
    vector<double> findPoint(int A[], int B[], int C[])
    {
        vector<vector<double>>V;
        V.push_back({A[0]+C[0]-B[0], A[1]+C[1]-B[1]});
        V.push_back({B[0]+C[0]-A[0], B[1]+C[1]-A[1]});
        V.push_back({A[0]+B[0]-C[0], A[1]+B[1]-C[1]});
        sort(V.begin(),V.end());
        return V[0];
    }
};