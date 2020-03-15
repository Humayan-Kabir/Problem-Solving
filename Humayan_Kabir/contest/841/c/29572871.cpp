#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll ara[200007];
int main()
{
    ll n;
    scanf("%lld",&n);
    priority_queue< pair<int,int> > PQ;
    priority_queue< pair<int,int> > PQ2;
    for(int i=1;i<=n;i++)
    {
        ll num;
        scanf("%d",&num);
        PQ.push(make_pair(num,i));
    }
    for(int i=1;i<=n;i++)
    {
        ll num;
        scanf("%lld",&num);
        PQ2.push(make_pair(-num,i));
    }
    while (!PQ2.empty())
    {
       pair<ll,ll> p=PQ2.top();
       PQ2.pop();
       pair<ll,ll> q=PQ.top();
       PQ.pop();
       ara[p.second]=q.first;
    }

    for(int i=1;i<=n;i++)
    {
        if(i==1) printf("%lld",ara[i]);
        else printf(" %lld",ara[i]);
    }
    printf("\n");
    return 0;
}
