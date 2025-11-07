class Solution {
  public:
    int solve(int n, int i, int maxThershold){
        if(n==0 || i==1 || maxThershold==0) return n;
        
        int take = 1e4, not_take = 1e4;
        
        //take current i
        if(n>=i*i)
            take = solve(n-i*i, i, maxThershold-1) + 1;
        
        //not_take
        not_take = solve(n, i-1, maxThershold);
        
        return min(take, not_take);
    }
    
    int minSquares(int n) {
        // Code here
        return solve(n, pow(n, 0.5), 4);
    }
};