/*input
3
1 10
3 14
1 10
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t--) {
		LL a, b;
		cin >> a >> b;
		if(a > b) swap(a, b);
		cout << a << " "<< 2 * a << endl;
	}
	return 0;
}