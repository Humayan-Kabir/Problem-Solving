#include<bits/stdc++.h>
using namespace std;
int main()
{
    map<int,int> up,down,same;
    vector<pair<int,int> > vt;
    int n,need;
    cin>>n;
    need=(n+1)/2;
    for(int i=1;i<=n;i++)
    {
        int u,v;
        cin>>u>>v;
        up[u]++; down[v]++;
        if(u==v) same[u]++;
        vt.push_back({u,v});

    }

    int ans=INT_MAX;

    for(int i=0;i<vt.size();i++)
    {

        int x=up[vt[i].first],y=down[vt[i].first],z=same[vt[i].first];

        if((x+y-z)>=need)
        {
            ans=min(ans,max(0,need-x));
        }

        if(down[vt[i].second]>=need)
        {
            ans=min(ans,need);
        }
    }

    if(ans==INT_MAX)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<ans<<endl;
    }

    return 0;
}

