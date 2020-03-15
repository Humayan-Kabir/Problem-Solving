/*input
2
1 1
*/
#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
int ara[mx],cnt[mx];
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int large = 0;
	for(int i = 1; i<=n; i++)
	{
		cin >> ara[i];
		cnt[ara[i]]++;
	}
	sort(ara+1,ara+n+1);
	large = ara[n];
	if(cnt[large] % 2 == 1)
	{
		cout <<"Conan"<< endl;
		return 0;
	}
	int now = 0;
	for(int i = 1; i<=n; i++) if(ara[i] == large) now++;
	if(now == n)
	{
		if(n%2 == 1) cout <<"Conan"<< endl;
		else cout <<"Agasa"<< endl;
		return 0;
	}
	for(int i = 1; i<=n; i++)
	{
		if(cnt[ara[i]] % 2 == 1) 
		{
			cout <<"Conan"<< endl;
			return 0;
		}
	}
	cout <<"Agasa"<< endl;
	return 0;
}