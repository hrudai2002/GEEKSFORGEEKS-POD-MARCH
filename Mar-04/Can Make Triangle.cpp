https://practice.geeksforgeeks.org/problems/51b7f8fb8b33d657a857f230361b7dad6565ce62/1 

bool triangle(int a, int b, int c){
        if(a + b <= c) return false;
        if(b+ c <= a) return false;
        if(c + a <= b) return false;
        return  true;
    }
    vector<int> canMakeTriangle(vector<int> a, int N){
        vector<int> ans; 
        for(int i = 0; i  < N - 2; ++i){
            if(triangle(a[i], a[i + 1], a[i + 2])){
                ans.push_back(1);
            } else {
                ans.push_back(0);
            }
        }
        return ans;
    }
