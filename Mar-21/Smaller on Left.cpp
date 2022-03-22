vector<int> Smallestonleft(int arr[], int n)
{
    vector<int> ans;
    set<int> s;
    ans.push_back(-1);
    s.insert(-1);
    s.insert(arr[0]);
    for(int i = 1; i < n; ++i) {
      s.insert(arr[i]);
      auto it = s.find(arr[i]);
      it--;
      ans.push_back(*it);
    }
    return ans;
}
