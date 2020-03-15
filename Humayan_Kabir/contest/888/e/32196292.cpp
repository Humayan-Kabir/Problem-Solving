/*input
15 982451653
384052103 7482105 882228352 582828798 992251028 892163214 687253903 951043841 277531875 402248542 499362766 919046434 350763964 288775999 982610665
*/
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int n, inp[37], modulo;
	cin >> n >> modulo;
	for(long long int i = 0; i<n; i++)
		cin >> inp[i];
	long long int left, right, ans = 0;
	vector<long long int> vv1,vv2,ara;
	for(long long int i = 0; i<(n/2); i++)
	{
		ara.push_back(inp[i]);
	}
	left = ara.size();
	for(long long int i = 0; i<(1<<left); i++)
	{
		long long int sum = 0;

		for(long long int j = 0; j<left; j++)
		{
			if(i & (1<<j)) sum = (sum + ara[j]) % modulo;
		}
        ans = max(ans , sum);
		vv1.push_back(sum);
	}	 
	ara.clear();
	for(long long int i = n/2; i<n; i++)
		ara.push_back(inp[i]);
	right = ara.size();
	for(long long int i = 0; i<(1<<right); i++)
	{
		long long int sum = 0;

		for(long long int j = 0; j<right; j++)
		{
           if(i & (1<<j)) sum += ara[j];

           sum = (sum + modulo) % modulo;
		}
        ans = max(ans, sum);
		vv2.push_back(sum);
	}
	sort(vv1.begin(), vv1.end());
	sort(vv2.begin(), vv2.end());
	for(long long int i = 0;  i<vv1.size(); i++)
	{
		long long int now = vv1[i];
		long long int need = modulo - vv1[i];
		long long int low = 0, high =  vv2.size() - 1, mod = 0;
		while(low <= high)
		{
			long long int mid = (low + high)/2;
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