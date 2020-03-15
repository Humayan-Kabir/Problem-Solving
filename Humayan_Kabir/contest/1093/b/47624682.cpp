/*input
3
aa
abacaba
xdd
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
		int cnt[26];
		memset(cnt, 0, sizeof cnt);
		string str;
		cin >> str;
		int unique = 0;
		for(int i  = 0; i < str.length(); i++) {
			cnt[str[i] - 'a']++;
		}
		for(int i = 0; i < 26; i++) {
			unique += (cnt[i] > 0);
		}
		if(unique == 1) {
			cout << -1 << endl;
		}
		else {
			for(char ch = 'a'; ch <= 'z'; ch++) {
				while(cnt[ch - 'a']--) {
					cout << ch;
				}
			}
			cout << endl;
		}
	}
	return 0;
}