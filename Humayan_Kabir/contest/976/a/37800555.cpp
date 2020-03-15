/*input
1001
*/
#include <bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	int cnt = 0;
	for(int i = 0; i<str.length(); i++)
	{
		if(str[i] == '1' && cnt == 0) 
		{
			cout << 1;
			cnt++;
		}
		else if(str[i] == '0') cout << 0;
	}
	cout << endl;
	return 0;
}