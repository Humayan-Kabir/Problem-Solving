/*input
5 0 0
*/
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,a,b;
	cin >> n >> a >> b;
	if(n==1)
	{
		cout << 50000 <<  endl;
		return 0;
	}
	if(b == 0 && a == n - 1)
	{
		cout<< -1 << endl;
		return 0;
	}
	int ara[110];
	int now = 1, pos;
	for(int i = 1; i<= b + 1; i++)
	{
		ara[i] = now;
		now = now * 2;
		pos = i + 1;
	}
	if(b == 0) ara[2] = 1, pos = 3;
	for(int i = pos, j = a; i<=n; i++, j--)
	{
		if(j > 0)
			ara[i] = ara[i-1] + 1;
		else ara[i] = ara[i-1];
	}
	for(int i = 1; i<=n; i++)
		cout <<ara[i]<<" ";
	cout << endl;
	return 0;
}