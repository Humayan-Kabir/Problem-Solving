/*input
1000000000000 2 0
*/
#include <bits/stdc++.h>
#include <string>
#define MX 55
#define mod 1000000007
typedef long long int LL;
using namespace std;
LL m,X[MX][MX], I[MX][MX], now[MX][MX];
int fun(char ch)
{
	if(isupper(ch)) return ch - 'A' + 26;
	else return ch - 'a';
}
void multiply(LL a[MX][MX], LL b[MX][MX])
{
	memset(now,0,sizeof now);
	for(int i = 0; i<m; i++) for(int j = 0; j<m; j++) for(int k = 0; k<m; k++) now[i][j] = (a[i][k] * b[k][j] + now[i][j]) %mod;
	for(int i = 0; i<m; i++) for(int j = 0; j<m; j++) for(int k = 0; k<m; k++) a[i][j] = now[i][j];	
}
int main(int argc, char const *argv[])
{
	//ios_base::sync_with_stdio(false);
	LL n,k;
	cin >> n >> m >> k; n--;
	for(int i = 0; i<m; i++)
		for(int j = 0; j<m; j++)
			X[i][j] = 1;
	while(k--)
	{
		char u, v;
		scanf(" %c %c",&u,&v);
		X[fun(u)][fun(v)] = 0;	
	}	
	for(int i = 0; i<m; i++) I[i][i] = 1;
	for(LL i = 1; i<=n; i*=2)
	{
		if(n&i) multiply(I,X);
		multiply(X,X);
	}	
	LL ans = 0;
	for(int i = 0; i<m; i++) for(int j = 0; j<m; j++) ans=(I[i][j] + ans) % mod;
	cout<< ans <<endl;	
	return 0;
}