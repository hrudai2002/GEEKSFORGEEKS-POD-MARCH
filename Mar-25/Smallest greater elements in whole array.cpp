https://practice.geeksforgeeks.org/problems/smallest-greater-elements-in-whole-array2751/1 


int* greaterElement(int arr[], int n)
{
    vector<int> v(arr, arr + n);
    sort(v.begin(), v.end());
    unordered_map<int, int> mp;
    for(int i = 0; i < n; ++i ) {
        if(i == n - 1)
          mp[v[i]] = -10000000;
        else 
          mp[v[i]] = v[i + 1];
    }
    for(int i = 0; i < n; ++i) {
        arr[i] = mp[arr[i]];
    }
    return arr;
}
