/*input
2 100
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	LL k, p;
	std::vector<LL> vv;
	scanf("%lld %lld",&k,&p);
	LL siz = 0;
	for(int i = 1; i<=100007; i++)
	{
		vector<LL> digit, vt;
		LL tem = i,rev = 0;
		while(tem)
		{
			digit.push_back(tem % 10);
			tem/=10;
		}
		vt = digit;
		reverse(digit.begin(),digit.end());
		for(int j = 0; j<vt.size(); j++)
		{
			digit.push_back(vt[j]);
		}
		for(int j = digit.size()-1; j>=0; j--)
		{
			rev = 10 * rev + digit[j];
		}
		vv.push_back(rev);
		siz++;
		if(siz >=100001) break;
	}
	sort(vv.begin(), vv.end());
	LL ans = 0;
	for(int i = 0; i<k; i++)
	{
		ans = (ans + vv[i] + p) % p;
	}
	printf("%lld\n",ans);
	return 0;
}
