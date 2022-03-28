https://practice.geeksforgeeks.org/problems/swap-bits5726/1# 

int swapBits(int x, int p1, int p2, int n)
    {
        int ar[32] = {0}; 
        
        for(int i = 31; i >= 0; --i) {
    	    if((x & (1 << i))) {
    	        ar[i] = 1;
    	    }
    	    else {
    	        ar[i] = 0;
    	    }
	    }
	    
	    for(int i = 0; i < n; ++i) {
	        swap(ar[p1 + i], ar[p2 + i]);
	    }
	    
	    int ans = 0;
	    for(int i = 31; i >= 0; --i) {
	        if(ar[i]) {
	            ans = ans + (1 << i);
	        }
	    }
	    
	    return ans;
    }
