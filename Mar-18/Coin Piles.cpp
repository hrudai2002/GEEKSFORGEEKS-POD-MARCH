https://practice.geeksforgeeks.org/problems/coin-piles5152/1 

int minSteps(int A[], int N, int K) {
       int ans = INT_MAX;
        
        sort(A, A+N);
        
        vector<int> preSum(1,0);
        
        for(int i=0; i<N; i++)
            preSum.push_back(preSum[i]+A[i]);
        
        for(int i=0; i<N; i++)
        {
            if(preSum[i] >= ans)
                return ans;
                
            int p = upper_bound(A+i+1, A+N, A[i]+K) - A;
            
            int total = preSum[N] - preSum[p] - (N-p)*(A[i]+K);
            
            ans = min(ans, preSum[i]+total);
        }
        
        return ans;

    }
