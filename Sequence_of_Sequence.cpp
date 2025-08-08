class Solution {
  public:
    int maxcount = 0;
    void solve(int i, int m, int n, int j){
        if(j>n){
            maxcount++;
            return;
        }
        
        int power = pow(2,n-j);
        int start = i;
        while(start*power<=m){
            solve(start*2,m,n,j+1);
            start++;
        }
    }
    
    int numberSequence(int m, int n){
        int i = 1, j = 1;
        solve(i,m,n,j);
        return maxcount;
    }
};