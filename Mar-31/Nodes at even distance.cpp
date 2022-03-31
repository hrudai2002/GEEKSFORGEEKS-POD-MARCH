https://practice.geeksforgeeks.org/problems/nodes-at-even-distance0532/1# 


int countNodes(vector<int> graph[], int n, int root)
    {
        vector<vector<int>> level;
        level.push_back({root});
        queue<int> q;
        q.push(root);
        q.push(-1);
        
        vector<bool> vis(n + 1, false);
        vector<int> a;
        vis[root] = true;
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            if(node == -1) {
                level.push_back(a);
                if(!q.empty()) q.push(-1);
                a.clear();
            }
            else {
                for(auto i : graph[node]) {
                if(!vis[i]) {
                    q.push(i);
                    vis[i] = true;
                    a.push_back(i);
                }
               }
            }
        }
        int ans = 0;
        for(int i = 0; i < level.size(); ++i) {
            int c = 0, m;
            for(int j = i + 1; j < level.size(); ++j) {
                c++;
                if((c & 1) == 0) {
                   ans += (level[i].size() * level[j].size());
                }
            }
            m = level[i].size();
            ans += ((m*(m - 1))/2);
        }
        return ans;
    }
    int countOfNodes(vector<int> graph[], int n)
    {
        return countNodes(graph, n, 1);
    }
