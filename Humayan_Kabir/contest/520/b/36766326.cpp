/*input
10 1
*/
#include <bits/stdc++.h>
#define mx 100002
using namespace std;
typedef long long int LL;
int ara[mx], vis[mx];
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	int ans = INT_MAX;
	queue <int> Q;
	for(int i = 1; i<=10000; i++) ara[i] = INT_MAX;
	Q.push(n);
	ara[n] = 0;
	vis[n] = 1;
	while(!Q.empty())
	{
		int u = Q.front();
		Q.pop();
		LL next = 2 * u * 1LL;
		if(next <= 100000 && vis[next] == 0)
		{
			vis[next] = 1;
			ara[next] = ara[u]  + 1;
			Q.push(next);
		}
		if(u - 1 >= 0  && vis[u - 1] == 0)
		{
			vis[u - 1] = 1;
			ara[u - 1] = ara[u] + 1;
			Q.push(u - 1);
		}
		if(vis[m] == 1) break;
	}  
	cout << ara[m] << endl;
	return 0;
}