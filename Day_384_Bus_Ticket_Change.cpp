class Solution {
  public:
     bool canServe(vector<int> &arr) {
        int das=0,panch=0;
        int N=arr.size();
        
        for(int i=0;i<N;i++){
            if(arr[i]==5){
                panch++;
            }
            else if(arr[i]==10){
                if(panch>0){
                    panch--;
                }
                else{
                    return false;
                }
                das++;
            }
            else{
                
                if(das>0&&panch>0){
                    das--;
                    panch--;
                }
                else if(panch>2){
                    panch-=3;
                }
                else{
                    return false;
                }
                
            }
            
        }
        return true;
        
    }
};