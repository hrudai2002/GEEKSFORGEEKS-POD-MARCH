https://practice.geeksforgeeks.org/problems/special-matrix4201/1#


int FindWays(int n, int m, vector<vector<int>>bc){
	    vector<vector<int>> mat(n, vector<int>(m, 0));
	    long long mod = (long long)1e9 + 7;
	    for(int i = 0; i < bc.size(); ++i) {
	        mat[bc[i][0] - 1][bc[i][1] - 1] = -1;
	    }
	    
	    for(int i = 0; i < n; ++i) {
	        for(int j = 0; j < m; ++j) {
	            if(mat[i][j] == -1){
	                continue;
	            }
	            else if(i == 0 && j == 0) {
	                mat[i][j] = 0;
	            }
	            else if(i == 0) {
	                mat[i][j] = (mat[i][j - 1] == -1) ? -1 : 1;
	            }
	            else if(j == 0) {
	                mat[i][j] = (mat[i - 1][j] == -1)? -1 : 1;
	            }
	            else {
	                int v1 = (mat[i - 1][j] == -1) ? 0 : mat[i - 1][j];
	                int v2 = (mat[i][j - 1] == -1) ? 0 : mat[i][j - 1];
	                
	                mat[i][j] = (v1%mod + v2%mod)%mod;
	            }
	        }
	    }
	    return (mat[n - 1][m - 1] == -1 || mat[n - 1][m - 1] == 0) ? 0 : mat[n - 1][m - 1];
	}
