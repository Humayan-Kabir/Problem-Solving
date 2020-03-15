/*input
10000
*/
#include <bits/stdc++.h>
#define mx 200007
#define mod 1000000007
using namespace std;
typedef long long int LL;
inline bool isperfect(int num)
{
	int cnt = 0;
	while(num)
	{
		cnt+=(num % 10);
		num/=10;
	}
	return (cnt == 10);
}
int ara[100000];
int main(int argc, char const *argv[])
{
	int pos = 1;
	for(int i = 1; i<=10800100; i++)
	{
		if(isperfect(i))
		{
			ara[pos] = i;
			pos++;
		}
	}
	int num;
	scanf("%d",&num);
	printf("%d\n",ara[num]);
	return 0;
}