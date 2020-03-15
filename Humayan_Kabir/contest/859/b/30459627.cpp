#include "bits/stdc++.h"
using namespace std;

int main()
{
    int n;
    cin>>n;
    int sq=sqrt(n);
    int ans=4*sq;
    int foo=n-(sq*sq);
    if(foo<=sq && foo>0) ans+=2;
    else if(foo>sq) ans+=4;
    cout<<ans<<endl;

    return 0;
}
