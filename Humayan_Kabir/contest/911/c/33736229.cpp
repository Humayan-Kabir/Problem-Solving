/*input
2 2 3
*/
#include <bits/stdc++.h>
#define mx 210002
using namespace std;
typedef long long int LL;
int x,y,z;
int ara[2*mx];
int check(int a,int b,int c)
{
	memset(ara,0,sizeof ara);
	for(int i = 0; i<=200000; i++)
	{
		int now = a + i*x;
		if(now > 200000) continue;
		ara[now] = 1;
	}
	for(int i = 0; i<=200000; i++)
	{
		int now = b + i*y;
		if(now > 200000) continue;
		ara[now] = 1;
	}
	for(int i = 0; i<=200000; i++)
	{
		int now = c + i*z;
		if(now > 200000) continue;
		ara[now] = 1;
	}
	for(int i = 1; i<=200000; i++) if(ara[i] == 0) return 0;
	return 1;	
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	cin >> x >> y >> z;
	int flag = 0; 
	for(int i = 1; i<=3; i++)
	{
		for(int j = 1; j<=3; j++)
		{
			for(int k = 1; k<=3; k++)
			{
				if(flag == 0)
				{
					if(check(i,j,k))
					flag = 1;
				}
			}
		}
	}
	if(flag) cout << "YES"<<endl;
	else cout <<"NO"<<endl;
	return 0;
}