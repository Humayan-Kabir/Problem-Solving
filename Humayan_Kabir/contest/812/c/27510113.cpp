#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);

	long long int n,money;

	cin>>n>>money;

	vector<pair<long long int,long long int> > price;

	for(int i=1;i<=n;++i)
	{
		long long int p;

		cin>>p;

		price.push_back({p,i});
	}

	long long int ans=0,tk=0,low=1,high=n;
    
	while(low<=high)
	{
		long long int mid=(low+high)/2;

		long long int total=0;

		vector<long long int> vt;

		for(long long int i=1;i<=n;i++)
		{
           vt.push_back((price[i-1].first+(price[i-1].second*mid)));
		}

		sort(vt.begin(),vt.end());

		for(int i=0;i<mid;i++) total+=vt[i];

		if(total<=money)
		{
			ans=mid;

			tk=total;

			low=mid+1;
		}
		else high=mid-1;

	}

	cout<<ans<<" "<<tk<<endl;

	return 0;
}