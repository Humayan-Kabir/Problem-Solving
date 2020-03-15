#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n, inp[37], modulo;
	cin >> n >> modulo;
	for(int i = 0; i<n; i++)
		cin >> inp[i];
	int left, right, ans = 0;
	vector<int> vv1,vv2,ara;
	for(int i = 0; i<(n/2); i++){
		ara.push_back(inp[i]);
	}
	left = ara.size();
	for(int i = 0; i<(1<<left); i++)
	{
		int sum = 0;

		for(int j = 0; j<left; j++)
		{
			if(i & (1<<j)) sum = ( (sum)% modulo + (ara[j]) % modulo)% modulo;
		}
        ans = max(ans , sum);
		vv1.push_back(sum);
	}	 
	ara.clear();
	for(int i = n/2; i<n; i++)
		ara.push_back(inp[i]);
	right = ara.size();
	for(int i = 0; i<(1<<right); i++)
	{
		int sum = 0;

		for(int j = 0; j<right; j++)
		{
           if(i & (1<<j))
           	sum = ( (sum)% modulo + (ara[j]) % modulo)% modulo;

		}
        ans = max(ans, sum);
		vv2.push_back(sum);
	}
	sort(vv1.begin(), vv1.end());
	sort(vv2.begin(), vv2.end());
	for(int i = 0;  i<vv1.size(); i++)
	{
		int now = vv1[i];
		int need = modulo - vv1[i];
		int low = 0, high =  vv2.size() - 1, mod = 0;
		while(low <= high)
		{
			int mid = (low + high)/2;
			if(vv2[mid]>=need)
			{
				high = mid - 1;
			}
			else
			{
				mod = vv2[mid];
				low = mid + 1;
			}
		}
		ans = max(ans,(mod + now) % modulo);
	}
	cout<< ans <<endl;
	return 0;
}