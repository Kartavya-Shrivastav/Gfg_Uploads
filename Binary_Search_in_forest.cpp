class Solution{
    public:
    int find_height(int tree[], int n, int k)
    {
        if(n==1)return tree[0]-k; // tree[0]>K given in the question
        sort(tree,tree+n);
        int start = tree[0],end = tree[n-1],mid = start + (end-start)/2;
        
        while(start<=end){
            
            int wood_collection = 0;
            for(int i=0;i<n;i++){
                if(tree[i]>mid){
                    wood_collection+=tree[i]-mid;
                }
            }
            
          if(wood_collection==k){
            return mid;
         }
            else if(wood_collection<k){
                 end = mid -1;
            }
            else{
            start = mid +1;
        }
            
            mid = start + (end-start)/2;
        }
        return -1;
    }
};