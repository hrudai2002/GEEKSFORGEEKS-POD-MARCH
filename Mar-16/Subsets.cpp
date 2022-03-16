https://practice.geeksforgeeks.org/problems/subsets-1613027340/1 


vector<vector<int> > subsets(vector<int>& A)
    {
        vector<vector<int>> ans;
        int n = pow(2, A.size());
        for(int i = 0; i < n; ++i) {
            vector<int> a;
            for(int j = 0; j < A.size(); ++j) {
                if(i & (1 << j)) {
                    a.push_back(A[j]);
                }
            }
            ans.push_back(a);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
