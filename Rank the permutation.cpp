https://practice.geeksforgeeks.org/problems/rank-the-permutations2229/1 


long long fact(long long k) {
        if(k == 0 || k == 1) return 1;
        long long res = 1;
        for(int i = 2; i <= k; ++i)
            res *= i;
        return  res;
    }
    long long findRank(string str) {
        long long ans = 1;
        long long k = str.size() - 1;
        for(int i = 0; i < str.size(); ++i){
            int less = 0;
            for(int j = i + 1; j < str.size(); ++j){
                if(str[j] < str[i]) less++;
            }
            if(less > 0){
                ans += less*fact(k);
            }
            k--;
        }
        return ans;
    }
