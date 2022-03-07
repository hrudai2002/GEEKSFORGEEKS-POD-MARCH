https://practice.geeksforgeeks.org/problems/85781966a9db2a1ac17eaaed26a947eba5740d56/1

vector<vector<int>> computeBeforeMatrix(int N, int M, vector<vector<int>> after){
        vector<vector<int>> before(N, vector<int> (M, 0));
        for(int i= 0; i < N; ++i){
            int sum = 0;
            for(int j = 0; j < M; ++j){
                if(i == 0) {
                    before[i][j] = after[i][j] - sum;
                    sum += before[i][j];
                }
                else if(j == 0) {
                    before[i][j] = after[i][j] - after[i- 1][j];
                }
                else {
                    sum += before[i][j - 1];
                    before[i][j] = after[i][j] - (sum + after[i - 1][j]);
                }
            }
        }
        return before;
    }
