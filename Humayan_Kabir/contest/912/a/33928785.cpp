/*input
3 9
1 1 3
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{ 
	LL a,b;
	cin >> a >> b;
	LL x,y,z;
	cin >> x >> y >> z;
	LL u = 2 * x + y;
	LL v = 3 * z + y;
	cout << max(0LL,u - a) + max(0LL,v - b)<<endl;
	return 0;
}