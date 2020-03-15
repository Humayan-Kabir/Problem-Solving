/*input
5 3
wxhak
3 3 h x
1 5 x a
1 3 w g
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
int main(int argc, char const *argv[])
{
	int n , m;
	cin >> n >> m;
	string st;
	cin >> st;
	char ara[n+2];
	for(int i = 0; i<n; i++) ara[i] = st[i];
	while(m--)
	{
		int l , r;
		char u,v;
		cin >> l >> r;
		cin >> u >> v;
		l--; r--;
		for(int i = l; i<=r; i++)
		{
			if(ara[i] == u) ara[i]=v;
		}
	}
	for(int i = 0; i<n; i++) cout<<ara[i];
	cout << endl;
	return 0;
}