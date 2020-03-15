/*input
z
*/
#include <bits/stdc++.h>
#define mx 210002
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	string st;
	cin >> st;
	int ans = 0;
	for(int i = 0; i<st.length(); i++)
	{
		if(st[i]>='a' && st[i]<='z')
		{
			if(st[i] == 'a' || st[i] == 'e' || st[i] == 'i' || st[i] == 'o' || st[i] == 'u') ans++;
		}
		else
		{
			int now = st[i] - '0';
			if(now & 1) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}