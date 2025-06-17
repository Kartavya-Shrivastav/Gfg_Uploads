class Solution {

  public:
    vector<int> findMaxGuests(int Entry[], int Exit[], int N) {
        // Your code goes here
        map<int, int> mp;
	    for(int i = 0; i < N; i++) mp[Entry[i]]++, mp[Exit[i]+1]--;
	    int cnt = 0, max_cnt = 0;
	    vector<int> ret(2);
        for(auto &x : mp){
            cnt += x.second;
            if(cnt > max_cnt) max_cnt = cnt, ret[0] = max_cnt, ret[1] = x.first; 
        }
        return ret;

    }
};