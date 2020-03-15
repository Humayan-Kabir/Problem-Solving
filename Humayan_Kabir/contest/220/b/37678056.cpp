#include<iostream>
#include<stdio.h>
#include<algorithm>
#define mx 1000007
#define sq 330
using namespace std;
typedef long long int LL;
struct MO
{
    int id, l, r;
    inline bool operator < (const MO &a) const
    {
        int x = l / sq;
        int y = a.l / sq;
        if(x!=y) return x < y;
        if(x&1) return r < a.r;
        else return r > a.r;
    }
}query[mx];
int n, m, cnt[mx], ara[mx], ans = 0, res[mx];
inline void Remove(int idx)
{
    if(idx > n || ara[idx] > n) return;
    if(cnt[ara[idx]] == ara[idx])
    {
        if(ans > 0) ans--;
    }
    cnt[ara[idx]]--;
    if(cnt[ara[idx]] == ara[idx]) ans++;
    return;
}
inline void Add(int idx)
{
    if(idx > n || ara[idx] > n) return;
    if(cnt[ara[idx]] == ara[idx])
    {
        if(ans > 0) ans--;
    }
    cnt[ara[idx]]++;
    if(cnt[ara[idx]] == ara[idx]) ans++;
    return;
}
int main()
{
    scanf("%d %d",&n,&m);
    for(int i = 1; i<=n; i++) scanf("%d",&ara[i]);
    for(int i = 1; i<=m; i++)
    {
        scanf("%d %d",&query[i].l,&query[i].r);
        query[i].id = i;
    }
    sort(query + 1, query + m + 1);
    int L = 1, R = 0;
    for(int i = 1; i<=m; i++)
    {
        int l = query[i].l;
        int r = query[i].r;
        int id = query[i].id;
        while(L < l)
        {
            Remove(L);
            L++;
        }
        while(L > l)
        {
            L--;
            Add(L);
        }
        while(R < r)
        {
            R++;
            Add(R);
        }
        while(R > r)
        {
            Remove(R);
            R--;
        }
        res[id] = ans;
    }
    for(int i = 1; i<=m; i++)
        printf("%d\n",max(0,res[i]));
    return 0;
}