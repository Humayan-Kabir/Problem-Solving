/*input
1 2 0
*/
#include <bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	LL a,b,c;
	cin >> a >> b >> c;
	LL now = a % b;
	int pos = 1;
	int ans = -1;
	now = now * 10;
	for(int i = 1; i<=1000000; i++)
	{
		if(now>=b)
		{
			LL x = now / b;
			if(x == c) 
			{
				ans = pos;
				break;
			} 
			now = now % b;
			now = now * 10;
		}
		else
		{
			now = now * 10;
			if(c == 0)
			{
				ans = pos;
				break;
			}
		}
		pos++;
	}	
	cout << ans <<endl;
	return 0;
}