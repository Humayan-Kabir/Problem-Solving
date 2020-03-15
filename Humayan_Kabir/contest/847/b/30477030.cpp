#include <bits/stdc++.h>

using namespace std;
int ara[200007],tree[4*200007];
int vis[200007];
void build(int node,int l,int r)
{
    if(l==r)
    {
        tree[node]=ara[l];
        return;
    }
    int lson=2*node,rson=lson+1,mid=(l+r)/2;
    build(lson,l,mid);
    build(rson,mid+1,r);
    tree[node]=max(tree[lson],tree[rson]);
}
int query(int node,int l,int r,int x,int y)
{
    if(l>y || r<x) return 0;
    if(l>=x && r<=y) return tree[node];
    int lson=2*node,rson=lson+1,mid=(l+r)/2;
    return max(query(lson,l,mid,x,y),query(rson,mid+1,r,x,y));
}
void update(int node,int l,int r,int x,int y)
{
    if(l>y || r<x) return;
    if(l>=x && r<=y)
    {
        tree[node]=0;
        vis[l]=1;
        return;
    }
    int lson=2*node,rson=lson+1,mid=(l+r)/2;
    update(lson,l,mid,x,y);
    update(rson,mid+1,r,x,y);
    tree[node]=max(tree[lson],tree[rson]);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>ara[i];
    build(1,1,n);
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1) continue;
        printf("%d",ara[i]);
        int pos=i+1,now=ara[i];
        while (1)
        {
           int p=-1;
           int low=pos,high=n;
           while (low<=high)
           {
               int mid=(low+high)/2;
               int v=query(1,1,n,pos,mid);
               if(v>now)
               {
                   p=mid;
                   high=mid-1;
               }
               else low=mid+1;
           }
           if(p==-1) break;
           printf(" %d",ara[p]);
           update(1,1,n,p,p);
           now=ara[p];
           pos=p+1;
        }
        printf("\n");
    }
    return 0;
}
