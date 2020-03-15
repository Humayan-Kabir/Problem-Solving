#include<bits/stdc++.h>
using namespace std;
int fun(string A, int n)
{
    for(int i = 0, j = n-1; i < (n/2); i++,j--)
    {
        if(A[i] != A[j]) return true;
    }
    return false;
}
int main()
{
    string str;
    cin >> str;
    int n = str.length();
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        string A = "";
        for(int j = i; j < n; j++)
        {
            A+=str[j];
            int k = j - i + 1;
            if(fun(A,k)) ans = max(ans,k);
        }
    }
    cout << ans << endl;
    return 0;
}
