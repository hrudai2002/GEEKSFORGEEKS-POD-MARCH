https://practice.geeksforgeeks.org/problems/counts-zeros-xor-pairs0349/1


long long int calculate(int a[], int n)
{
    sort(a, a + n);
    long long int ans = 0, cnt = 1;
    for(int i = 1; i < n; ++i) {
        if(a[i] == a[i - 1]) {
            cnt++;
        }
        else{
            ans += ((cnt*(cnt - 1))/2);
            cnt = 1;
        }
    }
    ans += ((cnt*(cnt - 1))/2);
    return ans;
}
