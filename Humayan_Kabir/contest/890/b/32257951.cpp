/*input
6
2 1 2 2 4 1
*/
#include <bits/stdc++.h>
#include<algorithm>
#define fs first
#define sc second 
#define mx 200007
#define PII pair<int,int>
typedef long long int LL;
using namespace std;
int main(int argc, char const *argv[])
{
    int ara[mx];
    int n;
    cin >>  n;
    int ans;
    set<int> s;
    for(int i = 1; i<=n; i++)
    {
    	int id;
    	scanf("%d",&id);
    	s.insert(id);
    	ara[id] = n - i;	
    }
    int now = - 1;
    set<int> :: iterator it;
    for(it = s.begin(); it!=s.end(); it++)
    {
    	int id = *it;
    	if(ara[id]>now)
    	{
    		ans = id;
    		now = ara[id];
    	}
    }
    cout<<ans<<endl;
    return 0;
}