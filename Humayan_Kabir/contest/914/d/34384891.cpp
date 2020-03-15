/*input
5
1 2 3 4 5
6
1 1 4 2
2 3 6
1 1 4 2
1 1 5 2
2 5 10
1 1 5 2
*/
#include <bits/stdc++.h>
#define mx 500007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int blocksize = 750;
int n;
int ara[mx];
int blockgcd[800];
int totalblock;
inline void update(int block)
{
	int start = block * blocksize;
	int last = (block + 1) * blocksize;
	last = min(last,n);
	last--;
	int g = 0;
	for(int i = start; i<=last; i++) g = __gcd(g,ara[i]);
	blockgcd[block] = g;	
}
inline int fun(int block,int x)
{
	int start = block * blocksize;
	int last = (block + 1) * blocksize;
	last = min(last,n);
	last--;
	int cnt = 0;
	for(int i = start; i<=last; i++)
	{
		if(ara[i] % x !=0) cnt++;
		if(cnt >= 2) return cnt;
	}
	return cnt;
}
inline int query(int l,int r,int x)
{
	int startblock = (l / blocksize);
	int endblock = (r / blocksize);
	int last = min(r+1,(startblock + 1) * blocksize);
	last--;
	int cnt = 0;
	for(int i = l; i<=last; i++)
	{
		if(ara[i] % x != 0) 
		{
			cnt++;
		}
		if(cnt > 1) return 0;
	}
	startblock++;
	for(int i = startblock; i<endblock; i++)
	{
		if(blockgcd[i] % x != 0)
		{
			if(cnt == 1) return 0;
			cnt+=fun(i,x);
			if(cnt >= 2) return 0;
		}
	}
	int now = endblock * blocksize;
	for(int i = max(now,last + 1); i<=r; i++)
	{
		if(ara[i] % x != 0) 
		{
			cnt++;
		}
		if(cnt > 1) return 0;
	}
	return 1;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i = 0; i<n; i++)
	{
		scanf("%d",&ara[i]);
	}
	totalblock = n/blocksize;
	for(int i = 0; i<=totalblock; i++)
		update(i);
	int q;
	scanf("%d",&q);
	int u,v,w,x;
	while(q--)
	{
		scanf("%d %d %d",&u,&v,&w);
		if(u == 2)
		{
			ara[v - 1] = w;
			int bno = (v - 1)/blocksize;
			update(bno);
		}
		else 
		{
			scanf("%d",&x);
			if(query(v-1,w-1,x))
			{
				printf("YES\n");
			}
			else printf("NO\n");
		}
	}
	return 0;
}