https://practice.geeksforgeeks.org/problems/5109f04a157ca54bbb373477b1afeec22e7f1812/1

int count(int N, vector<int> A,int X)
    {   
        int ans = N;
        int mask = 0;
        for(int i = 31; i >= 0; --i) {
            if((X >> i) & 1) {
                mask ^= (1 << i);
            }
            else {
                int temp = mask ^ (1 << i);
                int count = 0;
                for(int i = 0; i < N; ++i) {
                    if((temp&A[i]) != temp) {
                        count++;
                    }
                }
                ans = min(ans, count);
            }
        }
        return ans;
    }
