https://practice.geeksforgeeks.org/problems/1df2447c003940512562d766cf0583bbdc7a75ed/1

long long countPairs(int N, int X, vector<int> numbers){
        unordered_map<string, int> freq;
        for(auto i : numbers)
             freq[to_string(i)]++;
        
        long long cnt = 0;
        for(int i = 0; i < N; ++i){
            string n = to_string(numbers[i]);
            string x = to_string(X);
            
            int idx = 0;
            while((idx < n.size() && idx < x.size()) && (n[idx] == x[idx])) {
                idx++;
            }
            if(idx == 0 || idx >= x.size() || idx < n.size()) {
                continue;
            }
            
            string back = "";
            for(int j = idx; j < x.size(); ++j) back += x[j];
            
            // cout << back << "\n";
            cnt += freq[back];
            if(back == n) cnt--;
        }
        return cnt;
}