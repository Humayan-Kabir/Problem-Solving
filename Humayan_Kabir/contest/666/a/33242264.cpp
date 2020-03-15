/*input
abacabaca
*/
#include <bits/stdc++.h>
using namespace std;
int n,dp[10007][4];
set< string > S;
string str;
int rec(int pos,int prev,string back)
{
    if(pos == n && prev != n - 1) return 1;
    int &ret = dp[pos][pos - prev];
    if(ret != -1 ) return ret;
    int now1 = 0, now2 = 0, now3 = 0;
    string st;
    if(pos + 2 <=n)
    {
        st+=str[pos];
        st+=str[pos+1];
        if(st != back) now1 = now1 | rec(pos + 2,pos,st);
        if(now1) S.insert(st);
    }
    if(pos + 3<=n)
    {
        st+=str[pos+2];
        if(st != back) now2 = now2 | rec(pos + 3,pos,st);
        if(now2)
            S.insert(st);
    }
    rec(pos+1,pos+1,"");

    return ret = max(now1,now2);
}
int main(int argc, char const *argv[])
{
    cin >> str;
    memset(dp,-1,sizeof dp);
    n = str.length();
    if(n < 7)
    {
        cout << 0 << endl;
        return 0;
    }
    for(int i = 5; i<6; i++)
    {
        rec(i,i,"");
    }
    cout << S.size() <<endl;
    set<string> :: iterator it;
    for(it = S.begin(); it!=S.end(); it++)
        cout << *it <<endl;
    return 0;
}
