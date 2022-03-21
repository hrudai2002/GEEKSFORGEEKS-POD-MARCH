https://practice.geeksforgeeks.org/problems/5ef42ba605fff6cd60b1b2dd2ee230ade1fa25b0/1


int minRepeats(string A, string B) {
        string temp = A;
        int cnt = 1;
        while(A.size() < B.size()) {
            A += temp;
            cnt += 1;
        }
        if(A.find(B) != -1)
           return cnt;
        A += temp;
        if(A.find(B) != -1)
           return cnt + 1;
        return -1;
           
    }
