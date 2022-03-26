https://practice.geeksforgeeks.org/problems/maximum-average-subarray5859/1

int findMaxAverage(int arr[], int n, int k) {
        int mavg = 0, sti = 0, sum = 0;
        for(int i = 0; i < k; ++i)
            sum += arr[i];
        mavg = sum;
        
        int ptr = 0;
        for(int i = k; i < n; ++i) {
            sum -= arr[ptr];
            sum += arr[i];
            ptr++;
            if(sum > mavg) {
                sti = ptr;
                mavg = sum;
            }
            
        }
        return sti;
    }
