/*input
3 2
4 6 3
2 4 1
3 5 4
*/
#include <bits/stdc++.h>
using namespace std;
vector< pair<int,int> > vv[200007];
map<pair<int,int>,int> mymap;
int main(int argc, char const *argv[])
{
	int n,x;
	scanf("%d %d",&n,&x);
	vector< pair<pair<int,int>,int> > vt;
	for(int i = 1; i<=n ; i++)
	{
		int u,v,cost;
		scanf("%d %d %d",&u,&v,&cost);
		vt.push_back({{u,v},cost});
	}
	sort(vt.begin(), vt.end());
	for(int i = 0; i<n; i++)
	{
		int x=vt[i].first.first,y=vt[i].first.second,z=vt[i].second;
		if(mymap.find({x,y})==mymap.end())
		{
			vv[y-x+1].push_back({x,z});
			mymap[{x,y}]=1;
		}
	}
	for(int i = 0; i<=200000; i++)
	{
		sort(vv[i].begin(), vv[i].end());
	}
	for(int i = 0; i<=200000; i++)
	{
		int minumum=INT_MAX;

		for(int j = vv[i].size()-1; j>=0; j--)
		{
            minumum=min(minumum,vv[i][j].second);
            vv[i][j].second=minumum;
		}
	}
	int foo=0,sol=INT_MAX;

	for(int i = 0; i<n; i++)
	{
       int now=vt[i].second,l=vt[i].first.first,r=vt[i].first.second;
       int need=x-(r-l+1);
       if(need<0) continue;
       int ans=-1,low=0,high=vv[need].size()-1;
       while(low<=high)
       {
       	  int mid=(low+high)/2;
       	  if(vv[need][mid].first<=r)
       	  {
       	  	 low=mid+1;
       	  }
       	  else
       	  {
       	  	 high=mid-1;
       	  	 ans=vv[need][mid].second;
       	  }
       }
       if(ans!=-1)
       {
       	 foo=1;
       	 sol=min(sol,now+ans);
       }
	}
	if(foo)
	{
		cout<<sol<<endl;
	}
	else 
	{
		cout<<-1<<endl;
	}
	return 0;
}