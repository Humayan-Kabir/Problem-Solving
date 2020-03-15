#include<bits/stdc++.h>
using namespace std;
int n,dp[107][2007];
vector<int> ans;
struct pii
{
    int first,pos;
    pair<int,int> second;
    bool operator <(const pii &a) const
    {
        return first<a.first;
    }
};
pii ara[107];
int rec(int pos,int time)
{
    if(pos==n) return 0;
    int &ret=dp[pos][time];
    if(ret!=-1) return ret;
    int now=0;
    now=rec(pos+1,time);
    if(time+ara[pos].second.first<ara[pos].first)
        now=max(now,ara[pos].second.second+rec(pos+1,time+ara[pos].second.first));
    return ret=now;
}

void path(int pos,int time)
{
    if(pos==n) return;
    int &ret=dp[pos][time];
    if(ret==rec(pos+1,time)) path(pos+1,time);
    else
    {
        ans.push_back(ara[pos].pos);
        path(pos+1,time+ara[pos].second.first);
        return;
    }
}

int main()
{
    scanf("%d",&n);
    for(int i = 0; i<n; i++)
    {
        scanf("%d %d %d",&ara[i].second.first,&ara[i].first,&ara[i].second.second);
        ara[i].pos=i+1;
    }

    sort(ara, ara + n) ;
    memset(dp,-1,sizeof dp);
    printf("%d\n",rec(0,0));
    path(0,0);
    printf("%d\n",ans.size());
    for(int i = 0; i<ans.size(); i++)
    {
        if(i==0) printf("%d",ans[i]);
        else printf(" %d",ans[i]);
    }
    return 0;
}
