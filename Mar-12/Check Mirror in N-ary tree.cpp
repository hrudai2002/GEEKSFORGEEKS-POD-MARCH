https://practice.geeksforgeeks.org/problems/check-mirror-in-n-ary-tree1528/1#


int checkMirrorTree(int n, int e, int A[], int B[]) {
       int m = 100000;
       vector<int> adj1[m + 1], adj2[m + 1];
       int x = 0;
       for(int i = 0; i < e; ++i) {
           adj1[A[x]].push_back(A[x + 1]);
           x += 2;
       }
       x = 0;
       for(int i = 0; i < e; ++i) {
           adj2[B[x]].push_back(B[x + 1]);
           x += 2;
       }
       
       queue<int> q;
       q.push(1);
       q.push(-1);
       vector<int> ans1, ans2;
       while(!q.empty()) {
           int front = q.front();
           q.pop();
           if(front == -1) {
               if(!q.empty()) q.push(-1);
           }
           else {
               ans1.push_back(front);
               for(auto i : adj1[front])
                 q.push(i);
           }
       }
       q.push(1);
       q.push(-1);
       vector<int> d;
       while(!q.empty()) {
           int front = q.front();
           q.pop();
           if(front == -1) {
               if(!q.empty()) q.push(-1);
               reverse(d.begin(), d.end());
               for(auto i : d) ans2.push_back(i);
               d.clear();
           }
           else {
               d.push_back(front);
               for(auto i : adj2[front])
                 q.push(i);
           }
       }
       if(ans1 == ans2) return 1;
       return 0;
    }
