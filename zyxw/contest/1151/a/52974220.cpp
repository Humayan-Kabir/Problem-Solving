#include <bits/stdc++.h>
#define mx 100007
using namespace std;
typedef long long int LL;
bool comp(pair<LL,LL> a, pair<LL,LL> b) {
	LL x = a.first - a.second;
	LL y = b.first - b.second;
	return x > y;
}
int main(int argc, char const *argv[])
{
	vector< pair<LL,LL> > vt;
	int n;
	cin >> n;
	string str;
	string gnome = "ACTG";
	cin >> str;
	int ans = INT_MAX;
	for(int i = 0; i < str.length(); i++) {
		int baki = n - i;
		if(baki < 4) break;
		int curans = 0;
		for(int j = i; j < i + 4; j++) {
			int x = (int) (str[j] - 'A');
			int y = (int) (gnome[j - i] - 'A');
			if(x == y) continue;
			int cnt1 = 0, cnt2 = 0, temp = x;
			while(1) {
				cnt1++;
				temp = (temp + 1 + 26) % 26;
				if(temp == y) break;
			}
			temp = x;
			while(1) {
				cnt2++;
				temp = (temp - 1 + 26) % 26;
				if(temp == y) break;
			}
			curans += min(cnt1, cnt2);
		}
		ans = min(ans, curans);
	}	
	cout << ans << endl;
	return 0;
}