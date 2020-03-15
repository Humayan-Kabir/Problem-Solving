/*input
100 99
*/
#include <bits/stdc++.h>
#define mx 1000000000
using namespace std;
typedef long long int LL;
set<LL> vv1,vv2;
vector<LL> v1,v2;
inline void rec(int pos,int limit,LL sum)
{
	if(pos==limit)
	{
		vv1.insert(sum);
		return;
	}
	rec(pos+1,limit,sum+v1[pos]);
	rec(pos+1,limit,sum-v1[pos]);
	rec(pos+1,limit,sum);
}
inline void REC(int pos,int limit, LL sum)
{
	if(pos==limit)
	{
		vv2.insert(sum);
		return;
	}
	REC(pos+1,limit,sum+v2[pos]);
	REC(pos+1,limit,sum-v2[pos]);
	REC(pos+1,limit,sum);
}
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	LL w, m, now = 1;
	cin >> w >> m;
	if(w==2)
	{
		cout<<"YES"<<endl;
		return 0;
	}
	for(int i = 1; ; i++)
	{
		if(i&1) v1.push_back(now);
		else v2.push_back(now);
		if(now>m) break;
		now = now * w;
	}
	rec(0,v1.size(),0);
	REC(0,v2.size(),0);
	//sort(vv2.begin(), vv2.end());
	int foo = 0;
	for(auto it = vv1.begin(); it!=vv1.end(); it++)
	{
		if(vv2.find(*it+m)!=vv2.end()) foo = 1;
	}
	if(foo) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}