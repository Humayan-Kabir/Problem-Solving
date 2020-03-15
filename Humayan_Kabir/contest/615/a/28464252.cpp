#include<bits/stdc++.h>
using namespace std;
const int N=123456;
typedef long long int LL;
int main()
{
    int n,m;
    cin>>n>>m;
    int ara[m+2];
    memset(ara,0,sizeof ara);
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        while(k--)
        {
            int p;
            cin>>p;
            ara[p]=1;
        }
    }
    int flag=0;
    for(int i=1;i<=m;i++)
    {
        if(ara[i]==1) flag++;
    }
    if(flag==m) cout<<"YES"<<endl;
    else cout<<"NO"<<'\n';

    return 0;
}
