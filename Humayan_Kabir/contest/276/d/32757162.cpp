/*input
10000000000 20000000000
*/
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long a,b,XOR,bit = 0;
	cin >> a >> b;
	XOR = a ^ b;
	//cout << XOR << endl;
	while(XOR)
	{
		bit ++;
		XOR/=2;
	}
	long long ans = (1LL << bit) ;
	cout << ans - 1<<endl;
	return 0;
}