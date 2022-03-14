https://practice.geeksforgeeks.org/problems/biconnected-graph2528/1 


int biGraph(int arr[], int n, int e) {
        if(n == 2 && e == 1) {
            return 1;
        }
        int f[n] = {0};
        for(int i = 0; i < 2*e; ++i)
          f[arr[i]]++; 
        for(int i = 0; i < n; ++i) {
            if(f[i] <  2) return 0;
        }
        return 1;
    }
