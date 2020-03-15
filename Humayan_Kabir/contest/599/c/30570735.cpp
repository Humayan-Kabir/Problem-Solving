#include <bits/stdc++.h>
#define mx 100007
using namespace std;
int tree[4*mx],Tree[4*mx],ara[mx],n;
void build(int node,int l, int r)
{
    if(l==r)
    {
        tree[node]=ara[l];
        Tree[node]=ara[l];
        return;
    }
    int lson=2*node,rson=lson+1,mid=(l+r)/2;
    build(lson,l,mid);
    build(rson,mid+1,r);
    tree[node]=min(tree[lson],tree[rson]);
    Tree[node]=max(Tree[lson],Tree[rson]);
}
int query1(int node,int l,int r,int x,int y)
{
    if(l>y || r<x) return INT_MAX;
    if(l>=x && r<=y) return tree[node];
    int lson=2*node,rson=lson+1,mid=(l+r)/2;
    return min(query1(lson,l,mid,x,y),query1(rson,mid+1,r,x,y));
}
int query2(int node,int l,int r,int x,int y)
{
    if(l>y || r<x) return 0;
    if(l>=x && r<=y) return Tree[node];
    int lson=2*node,rson=lson+1,mid=(l+r)/2;
    return max(query2(lson,l,mid,x,y),query2(rson,mid+1,r,x,y));
}
int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%d",&ara[i]);
    }
    build(1,1,n);
    int now=0,ans=0;
    for(int i=1; i<=n; i++)
    {
        int q2=query2(1,1,n,1,i);
        int q1=query1(1,1,n,i+1,n);
        if(q2<=q1)
        {
            ans++;
        }
    }

    printf("%d\n",ans);
    return 0;
}
