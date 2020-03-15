#include <bits/stdc++.h>
using namespace std;
#define mx 2000007
int tree[4*mx],lazy[4*mx];
void update(int node,int l,int r,int i,int j,int val)
{
	int lson=2*node,rson=lson+1,mid=(l+r)/2;
	if(lazy[node])
	{
		if(l!=r)
		{
			lazy[lson]=lazy[node];
			lazy[rson]=lazy[node];
		}
	}
	if(l>j || r<i) return;

	if(l>=i && r<=j)
	{
		lazy[node]=val;
		if(l!=r)
		{
			lazy[lson]=lazy[node];
			lazy[rson]=lazy[node];
		}
		return;
	}
	update(lson,l,mid,i,j,val);
	update(rson,mid+1,r,i,j,val);
}

void query(int node,int l,int r)
{
	int lson=2*node,rson=lson+1,mid=(l+r)/2;
	if(l==r)
	{
		tree[l]=lazy[node];
		return;
	}
	if(lazy[node])
	{
		if(l!=r)
		{
			lazy[lson]=lazy[node];
			lazy[rson]=lazy[node];
		}
	}
	query(lson,l,mid);
	query(rson,mid+1,r);

}
string st[100007];
vector<int> vt[100007];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n,maximum=-1;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
    	cin>>st[i];
    	int len=st[i].length();
    	int k;
    	cin>>k;
    	while(k--)
    	{
    		int pos;
    		cin>>pos;
    		vt[i].push_back(pos);
    		maximum=max(maximum,pos-1+len);
    	}
    }

    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<vt[i].size();j++)
        {
            int x=vt[i][j];
            update(1,1,maximum,x,x+st[i].length()-1,i);
        }
    }
    query(1,1,maximum);
    string ans;
    for(int i=1;i<=maximum;i++)
    {
    	if(!tree[i])
    	{
    		ans+='a';
    	}
    	else
    	{
    		int p=tree[i];
    	   	int pos=upper_bound(vt[p].begin(),vt[p].end(),i)-vt[p].begin();
    	   	pos--;
    	   	int x=i-vt[p][pos];
    	   	ans+=st[p][x];
    	}
    }

    cout<<ans<<endl;


    return 0;
}
