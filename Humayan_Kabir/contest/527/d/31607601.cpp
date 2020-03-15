/*input
4
2 3
3 1
6 1
0 2
*/
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	vector< pair<int,int> > vt;
	for(int i = 0; i<n; i++)
	{
		int id,w;
		cin>>id>>w;
		vt.push_back({id+w,id-w});
	}
	sort(vt.begin(), vt.end());
	int ans=1,right=vt[0].first;
	for(int i = 1; i<n; i++)
	{
		if(vt[i].second>=right)
		{
			right=vt[i].first;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}