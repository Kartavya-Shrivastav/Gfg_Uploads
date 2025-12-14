class Solution {
  public:
    virtual void swapDiagonal(vector<vector<int>> &mat) {
      int i=0, j=0, n=mat.size();
      while(i<n && j<n){
          int t = mat[i][j];
          mat[i][j] = mat[i][n-1-j];
          mat[i][n-1-j] = t;
      
          i++, j++;
      }
      
      return;    
    }
};