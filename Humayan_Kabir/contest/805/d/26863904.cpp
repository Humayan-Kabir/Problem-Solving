#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL mod=1e9+7;
LL bigmod(LL a,LL b,LL m)
{
    if(b==0) return 1%m;
    LL x=bigmod(a,b/2,m);
    x=(x%mod*x%mod)%mod;
    if(b%2==1) x=(x*a)%mod;
    return x;
}
int main()
{
    string st;
    cin>>st;
    int ln=st.size();
    LL ans=0;
    LL cnt=0,pos=0;
    for(int i=0;i<ln;i++)
    {
        if(st[i]=='a')
        {
            cnt++;
        }
        else
        {
            if(cnt>0)
            ans=(ans+(bigmod(2,cnt,mod)-1+mod)%mod)%mod;
        }
    }

    cout<<ans<<endl;
    return 0;
}
