https://practice.geeksforgeeks.org/problems/choose-and-swap0531/1#

string chooseandswap(string a){
        unordered_set<char> s;
        int n = a.size();
        for(int i = 0; i < n; ++i) {
            char smallest = a[i];
            for(int j = i + 1; j < n; ++j) {
                if(s.find(a[j]) == s.end() && a[j] < smallest) {
                    smallest = a[j];
                }
            }
            if(smallest != a[i]) {
                char toChange = a[i];
                for(int j = 0; j < n; ++j) {
                    if(a[j] == smallest) 
                       a[j] = toChange;
                    else if(a[j] == toChange)
                       a[j] = smallest;
                }
                return a;
            }
            s.insert(a[i]);
        }
        return a;
    }
