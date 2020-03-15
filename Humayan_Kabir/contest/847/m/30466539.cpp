#include "bits/stdc++.h"
using namespace std;
int ara[200];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ara[i];
    int dis=ara[1]-ara[2];
    int foo=0;
    for(int i=1;i<n;i++)
    {
        int now=ara[i]-ara[i+1];
        if(now!=dis)
        {
            foo=1;
            break;
        }
    }
    if(foo) cout<<ara[n]<<endl;
    else cout<<ara[n]-dis<<endl;
    return 0;
}
