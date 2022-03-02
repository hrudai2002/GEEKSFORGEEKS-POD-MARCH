https://practice.geeksforgeeks.org/problems/2ac2f925b836b0625d848a0539ffd3d2d2995f92/1# 

long long countStrings(string s)
    {
        long long n = s.size(); 
        long long ans = (n*(n - 1)) / 2;
        vector<long long> ar(26, 0);
        for(char c : s) ar[c - 'a']++;
        
      
        bool yes = false;
        for(int i = 0; i < 26; ++i) {
            if(ar[i] > 1) {
                ans -= (ar[i] * (ar[i] - 1)) / 2;
                yes = true;
            }
        }
        return yes? ans + 1: ans;
    }  
