#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int sq,ar[100010];
int ans;
int clr[100010];
int cnt[100010],ccnt[100010];
struct Node
{
    int x,y,k,id;
    inline bool operator <(const Node& p)const
    {
        int a=x/sq;
        int b=p.x/sq;
        if(a!=b)
            return a<b;
        if(a&1)
            return y<p.y;
        else return y>p.y;
    }
} que[100010];
void Add(int pos)
{
    cnt[ar[pos]]++;
    ccnt[cnt[ar[pos]]]++;
}
void Erase(int pos)
{
    ccnt[cnt[ar[pos]]]--;
    cnt[ar[pos]]--;
}


vector<int>v[100010];
int tim;
pii T[100010];
void dfs(int node,int pa)
{
    T[node].first=++tim;
    ar[tim]=clr[node];
    for(int i=0; i<v[node].size(); i++)
    {
        int x=v[node][i];
        if(pa==x) continue;
        dfs(x,node);
    }
    T[node].second=tim;
    return;
}


int main()
{
    int n,q,Ans[100010];
    scanf("%d %d",&n,&q);
    for(int i=1; i<=n; i++)
        scanf("%d",&clr[i]);
    for(int i=1; i<=n-1; i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].push_back(y);
        v[y].push_back(x);
    }
    tim=0;
    dfs(1,0);
    for(int i=0; i<q; i++)
    {
        int u;
        scanf("%d %d",&u,&que[i].k);
        que[i].x=T[u].first;
        que[i].y=T[u].second;
        que[i].id=i;
    }
    sq=sqrt(n)+1;
    sort(que,que+q);
    int l=que[0].x,r=que[0].y;
    for(int i=l; i<=r; i++)
        Add(i);
    Ans[que[0].id]=ccnt[que[0].k];
    for(int i=1; i<q; i++)
    {
        int currentl=que[i].x,currentr=que[i].y;
        for(; l<currentl; l++)
            Erase(l);
        for(; l>currentl; l--)
            Add(l-1);
        for(; r<currentr; r++)
            Add(r+1);
        for(; r>currentr; r--)
            Erase(r);
        Ans[que[i].id]=ccnt[que[i].k];
    }
    for(int i=0; i<q; i++)
        printf("%d\n",Ans[i]);
    return 0;
}