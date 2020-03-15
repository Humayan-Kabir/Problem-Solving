#include<bits/stdc++.h>
#define FOR(i,n) for(int i=1;i<=n;i++)
using namespace std;
typedef long long int LL;
int main()
{
    ios_base::sync_with_stdio(false);
    LL s,v1,v2,t1,t2;
    cin>>s>>v1>>v2>>t1>>t2;
    LL x=(t1+(s*v1)+t1);
    LL y=(t2+(s*v2)+t2);
   // cout<<x<<" "<<y<<endl;
    if(x<y)
    {
        cout<<"First"<<endl;
        return 0;
    }
    if(y<x)
    {
        cout<<"Second"<<endl;
        return 0;
    }
    cout<<"Friendship"<<endl;

    return 0;
}
