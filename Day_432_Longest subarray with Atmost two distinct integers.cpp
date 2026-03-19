class Solution {
  public:
    int totalElements(vector<int> &arr) {
        // code here
        //TC=>O(n) SC=>O(1)
        int first=0,second=0;
        int MAX=0;
        unordered_map<int,int>m;
        while(second<arr.size()){
            m[arr[second]]++;
            if(m.size()>2){
                m[arr[first]]--;
                if(m[arr[first]]==0)m.erase(arr[first]);
                first++;
            }
            if(m.size()<=2)MAX=max(MAX,second-first+1);
        
            second++;
        }
        return MAX;
    }
};