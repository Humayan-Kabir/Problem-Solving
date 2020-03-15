/*input
4
2
13
37
100
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);	
	int t;
	cin >> t;
	while(t--) {
		int num;
		cin >> num;
		cout << num / 2 << endl;
	}
	return 0;
}