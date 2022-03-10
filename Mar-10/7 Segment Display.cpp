https://practice.geeksforgeeks.org/problems/7-segment-display0752/1#

string sevenSegments(string s, int n) {
       int sum = 0;
       int ssd[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 5};
       for(int i = 0; i < n; ++i) {
           sum += ssd[s[i] - '0'];
       }
       vector<int> a(n);
       for(int i = 0; i < n; ++i) {
           sum -= 2;
           a[i] = 2;
       }
       int i = 0;
       while(sum >= 4) {
           a[i] += 4;
           sum -= 4;
           i++;
       }
       
       int j = n - 1;
       while(j >= 0 && sum > 0) {
           int r = 7 - a[j];
           a[j] += min(sum, r);
           sum -= min(r, sum);
           j--;
       }
       string ans = "";
       for(int i = 0; i < n; ++i) {
           if(a[i] == 6) ans += "0";
           else if(a[i] == 2) ans += "1";
           else if(a[i] == 3) ans += "7";
           else if(a[i] == 4) ans += "4";
           else if(a[i] == 5) ans += "2";
           else ans += "8";
       }
       return ans;
    }
