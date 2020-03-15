/*input
4
1 1
2 2
-1 1
-2 2
*/
#include <bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int left = 0,right = 0;
	for(int i = 1; i<=n; i++)
	{
		int a,b;
		cin >> a >> b;
		if(a<0) left++;
		else right++;
	}
	if(left<=1 || right<=1) cout <<"Yes"<<endl;
	else cout <<"No"<<endl; 
	return 0;
}