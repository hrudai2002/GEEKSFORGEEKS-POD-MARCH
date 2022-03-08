https://practice.geeksforgeeks.org/problems/reverse-a-string-using-stack/1 

char* reverse(char *s, int len)
{
    //code here
    stack<char> st;
for(int i = 0;i< len;i++)
st.push(s[i]);
int i = 0;
while(st.empty() != true){
s[i] = st.top();
st.pop();
i++;
}

return s;
}
