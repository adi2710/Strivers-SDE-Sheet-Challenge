class Solution{
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    const int MOD = 3;
	    int ans = 0;
	    for(int i = s.size(), bit = 1; i >= 0; i--, bit = (bit * 2ll) % MOD)
	    {
	        if(s[i] == '1')
	            ans = (1ll * ans + bit) % MOD;
	    }
	    return ans == 0;
	}

};