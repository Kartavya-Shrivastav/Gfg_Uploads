class Solution {
  public:
    void diagonalSort(vector<vector<int> >& matrix, int n, int m) {
        for(int i=1;i<n;i++){
            
            int row=i,col=0;
            priority_queue<int, vector<int>, greater<int> >p;
            
            while(row<n && col<m){
                p.push(matrix[row++][col++]);
            }
            row=i;
            col=0;
             while(row<n && col<m){
                matrix[row++][col++]=p.top();
                p.pop();
            }
        }
        
         for(int i=1;i<m;i++){
            
            int row=0,col=i;

             priority_queue<int> pq;
            while(row<n && col<m){
                pq.push(matrix[row++][col++]);
            }
            row=0;
            col=i;
             while(row<n && col<m){
                matrix[row++][col++]=pq.top();
                pq.pop();
            }
        }
    }
};