#include<bits/stdc++.h>
using namespace std;
int main()
{
   /* #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif*/
    ios_base::sync_with_stdio(0);

    int n,m;
    cin>>n>>m;
    int foo=0;
    for(int i=1;i<=1000000;i++)
    {
        if(n%m==0)
        {
            foo=1;
            break;
        }
        n=n+n;
        n=n%m;
    }

    if(foo) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}