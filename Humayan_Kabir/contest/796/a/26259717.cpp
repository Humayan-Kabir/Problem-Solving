#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ara[100007],n,m,k;
    int mx=INT_MAX;
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        int dis;
        cin>>dis;
        if(dis==0) continue;
        if(k>=dis)
        {
            int d=abs(i-m)*10;
            if(d<mx) mx=d;
        }
    }

   cout<<mx<<endl;
    return 0;
}
