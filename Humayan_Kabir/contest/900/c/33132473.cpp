/*input
1
1
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int n,tree[mx],ara[mx],record[mx],to_make[mx];
void update(int idx)
{
	while(idx<=n)
	{
		tree[idx]+=1;
		idx +=(idx & -idx);
	}
}
int query(int idx)
{
	int sum = 0;
	while(idx>0)
	{	
		sum+=tree[idx];
		idx-=(idx & -idx);
	}
	return sum;
}
int main(int argc, char const *argv[])
{
	
	scanf("%d",&n);
	for(int i = 1; i<=n; i++) scanf("%d",&ara[i]);
	int MX = 0,total = 0;
	for(int i = 1; i<=n; i++)
	{

		MX = max(MX,ara[i]);
		if(MX==ara[i]) record[ara[i]] = 1,total++;
	}	
	MX = 0;
	for(int i = 1; i<=n; i++)
	{
		MX = max(MX,ara[i]);
		update(ara[i]);
		int q = query(ara[i]);
		if(q == i - 1) 
		{
			to_make[MX]++;
		}
	}
	int ans = 0, possible = -1;
	for(int i = 1; i<=n; i++)
	{
		int now = total - record[i] + to_make[i];
		if(now > possible)
		{
			possible = now;
			ans = i;
		}
	}
	cout << ans << endl;
	return 0;
}