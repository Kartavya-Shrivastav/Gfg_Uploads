class Solution {
  public:
    string calculateFraction(int a, int b) {
        string beforeDot = "";
	    
	    int newa = a/b;
	    int remainder = a % b;
	    
	    if(remainder == 0) return to_string(newa);
	    
	    beforeDot += to_string(newa);
	    newa = remainder;
	    unordered_map<int,int> mp;
	    string afterDot = "";
	    
	    while(newa != 0 and mp.find(newa) ==  mp.end()){
	        
	        mp[newa] = afterDot.length();
	        newa *= 10;
	        afterDot += to_string(newa/b);
	        newa %= b;
	        
	    }
	    
	    if(newa == 0){
	        return beforeDot + "." +   afterDot ;
	    }
	    
	    afterDot.insert(mp[newa], "(");
	    afterDot += ")";
	    return beforeDot + "." + afterDot;
    }
};