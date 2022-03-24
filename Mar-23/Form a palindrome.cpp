https://practice.geeksforgeeks.org/problems/form-a-palindrome2544/1

int findMinInsertions(string s){
        int n = s.size(); 
        vector<vector<int>> lcs(n + 1, vector<int>(n + 1, 0));
        string t = s;
        reverse(t.begin(), t.end());
        
        for(int i = 0; i <= n; ++i) {
            for(int j = 0; j <= n; ++j) {
                if(i == 0 || j == 0)
                    lcs[i][j] = 0;
                
                else if(s[i - 1] == t[j - 1])
                    lcs[i][j] = 1 + lcs[i - 1][j - 1];
                
                else 
                   lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
            }
        }
        return n - lcs[n][n];
    }
