#include<bits/stdc++.h>
#define input(a) scanf("%d",&a)
using namespace std;
typedef long long int LL;
const int N=200007;
int ara[N],bsiz=447;
LL Ans[N],ans=0;
LL cnt[1000007];
vector<pair<pair<int,int>,int> > query;
bool inline comp(pair<pair<int,int>,int > a,pair<pair<int,int>,int > b)
{
    if((a.first.first/bsiz)==(b.first.first/bsiz))
        return a.first.second<b.first.second;
    return (a.first.first/bsiz)<(b.first.first/bsiz);
}
int main()
{
    int n,q;
    input(n);
    input(q);
    for(int i=1; i<=n; i++)
    {
        input(ara[i]);
    }
    for(int i=1; i<=q; i++)
    {
        int l,r;
        input(l);
        input(r);
        query.push_back({{l,r},i});
    }

    sort(query.begin(),query.end(),comp);

    int L=1,R=0;

    for(int i=0; i<q; i++)
    {
        int l=query[i].first.first;
        int r=query[i].first.second;
        int id=query[i].second;
        while (R<r)
        {
            R++;
            ans-=(ara[R]*cnt[ara[R]]*cnt[ara[R]]);
            cnt[ara[R]]++;
            ans+=(ara[R]*cnt[ara[R]]*cnt[ara[R]]);
        }
        while (R>r)
        {
            ans-=(ara[R]*cnt[ara[R]]*cnt[ara[R]]);
            cnt[ara[R]]--;
            ans+=(ara[R]*cnt[ara[R]]*cnt[ara[R]]);
            R--;
        }
        while (L<l)
        {
            ans-=(ara[L]*cnt[ara[L]]*cnt[ara[L]]);
            cnt[ara[L]]--;
            ans+=(ara[L]*cnt[ara[L]]*cnt[ara[L]]);
            L++;
        }
        while (L>l)
        {
            L--;
            ans-=(ara[L]*cnt[ara[L]]*cnt[ara[L]]);
            cnt[ara[L]]++;;
            ans+=(ara[L]*cnt[ara[L]]*cnt[ara[L]]);
        }
        Ans[id]=ans;
    }

    for(int i=1; i<=q; i++)
    {
        printf("%lld\n",Ans[i]);
    }

    return 0;
}
