#include<bits/stdc++.h>
using namespace std;
const int N=100003;
int n,m,k;
int ara[N][6];
struct data
{
    int vt[6];
};
data tree[3*N];

data d;

void build(int node,int l,int r)
{
    if(l>r) return;
    if(l==r)
    {
        for(int i=1; i<=m; i++)
        {
            tree[node].vt[i]=ara[l][i];
        }
        return;
    }
    int mid=(l+r)/2;
    int lson=node<<1;
    int rson=lson+1;
    build(lson,l,mid);
    build(rson,mid+1,r);
    for(int i=1; i<=m; i++)
    {
        tree[node].vt[i]=max(tree[lson].vt[i],tree[rson].vt[i]);
    }
}

data merge(data a,data b)
{
    data mm;
    for(int i=1; i<=m; i++)
    {
        mm.vt[i]=max(a.vt[i],b.vt[i]);
    }
    return mm;
}

data query(int node,int l,int r,int x,int y)
{
    if(l>y || r<x) return d;
    if(l>=x && r<=y)
    {
        return tree[node];
    }
    int mid=(l+r)/2;
    int lson=node<<1;
    int rson=lson+1;

    return merge(query(lson,l,mid,x,y),query(rson,mid+1,r,x,y));
}

int main()
{
    ios_base::sync_with_stdio(false);
    for(int i=1; i<=m; i++) d.vt[i]=0;
    cin>>n>>m>>k;

    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            cin>>ara[i][j];
    build(1,1,n);

    int low=1,high=n;

    data received;
    data ans;

    int ok=0;

    while (low<=high)
    {
        int mid=(low+high)/2;
        int flag=0;
        for(int i=1; (i+mid-1)<=n; i++)
        {
            received=query(1,1,n,i,(i+mid-1));
            long long int total=0;
            for(int i=1; i<=m; i++) total+=received.vt[i];
            if(total<=k)
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            ans=received;
            low=mid+1;
            ok=1;
        }
        else high=mid-1;
    }

    if(!ok)
    {
        for(int i=1; i<=m; i++)
        {
            if(i==1)
            {
                cout<<0;
                continue;
            }
            cout<<" "<<0;
        }
        cout<<endl;
        return 0;
    }

    for(int i=1; i<=m; i++)
    {
        if(i==1)
        {
            cout<<ans.vt[i];
            continue;
        }
        cout<<" "<<ans.vt[i];
    }
    cout<<endl;

    return 0;


}
