https://practice.geeksforgeeks.org/problems/height-using-parent-array4103/1 

int findHeight(int n, int a[]){
          int root, height = 0;
          vector<int> adj[n + 1];
          for(int i = 0; i < n; ++i) {
              if(a[i] == -1) root = i;
              else
              adj[a[i]].push_back(i);
          }
          queue<int> q;
          q.push(root);
          q.push(-1);
          while(!q.empty()) {
              int front = q.front();
              q.pop();
              if(front == -1) {
                  if(!q.empty()) q.push(-1);
                  height += 1;
              }
              else {
                  for(auto i : adj[front])
                     q.push(i);
              }
          }
          
          return height;
    }
