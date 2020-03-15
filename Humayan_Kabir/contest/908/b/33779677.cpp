/*input
5 3
...
.S.
###
.E.
...
3
*/
#include <bits/stdc++.h>
#define mx 210002
using namespace std;
typedef long long int LL;
int n,m;
string grid[110];
string direction;
int ara[] = {1,2,3,4};
int x,y,x1,y1;
bool out(int u,int v)
{
	return (u>=0 && u<n && v>=0 && v<m);
}
bool possible(int u,int v)
{
	return (u == x1 && v == y1);
}
int check()
{
	int now1 = x, now2 = y;
	for(int i = 0; i<direction.length(); i++)
	{
		if(out(now1,now2) == 0 || grid[now1][now2] == '#') return 0;
		if(out(now1,now2) && possible(now1,now2)) return 1;
		int xx = direction[i] - '0';
		if(ara[xx] == 1)
		{
			now2++;
		}
		if(ara[xx ] == 2)
		{
			now2--;
		}
		if(ara[xx ] == 3)
		{
			now1--;
		}
		if(ara[xx] == 4)
		{
			now1++;
		}
		if(out(now1,now2) == 0 || grid[now1][now2] == '#') return 0;
		if(possible(now1,now2) && out(now1,now2)) return 1;
	}
	if(out(now1,now2) == 0 || grid[now1][now2] == '#') return 0;
	if(possible(now1,now2) && out(now1,now2)) return 1;
	return 0;
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 0; i<n; i++)
	{
		cin >> grid[i];
		for(int j = 0; j<grid[i].length(); j++)
		{
			if(grid[i][j] == 'S') 
			{
				x = i; y = j;
			}
			if(grid[i][j] == 'E')
			{
				x1 = i; y1 = j;
			}
		}
	}
	int ans = 0;
	cin >> direction;
	do 
	{
	  if(check()) ans++;
	}while(next_permutation(ara,ara+4));
	cout << ans << endl;
	return 0;
}