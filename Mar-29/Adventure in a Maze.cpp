https://practice.geeksforgeeks.org/problems/adventure-in-a-maze2051/1#

vector<int> FindWays(vector<vector<int>>&mat){
    int n = mat.size();
    int m = mat[0].size();
    int mod = (int)1e9 + 7;
    pair<int, int> dp[n][m];
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            dp[i][j] = {0, mat[i][j]};
        }
    }
    dp[0][0].first = 1;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            int upPaths = 0, upSum = 0, leftPaths = 0, leftSum = 0;
            if(i > 0 && (mat[i - 1][j] == 2 || mat[i - 1][j] == 3) && dp[i - 1][j].first) {
                upPaths = dp[i - 1][j].first;
                upSum = dp[i - 1][j].second;
            }
            if(j > 0 && (mat[i][j - 1] == 1 || mat[i][j - 1] == 3) && dp[i][j - 1].first) {
                leftPaths = dp[i][j - 1].first;
                leftSum = dp[i][j - 1].second;
            }
            dp[i][j] = {max(dp[i][j].first, (upPaths + leftPaths)%mod), dp[i][j].second + max(leftSum, upSum)%mod};
        }
    }
    vector<int> ans(2);
    ans[0] = (dp[n - 1][m - 1].first % mod);
    ans[1] = (dp[n - 1][m - 1].first) ? dp[n - 1][m - 1].second : 0;
    return ans;
 }
