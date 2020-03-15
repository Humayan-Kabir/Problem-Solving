/*input
5
0 1 0 1 3
*/
#include <bits/stdc++.h>
#include<algorithm>
#define fs first
#define sc second 
#define mx 200007
#define PII pair<int,int>
typedef long long int LL;
using namespace std;
int ara[mx],mark[mx];
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    for(int i = 0; i<n; i++) scanf("%d",&ara[i]);
    int ans = 1, time = 0;
    mark[0] = 1;
    for(int i = 0; i<n; i++)
    {   
         time++;
        if(mark[ara[i]])
        {
        	mark[ara[i]] = 0;
        	mark[time] = 1;
        } 
        else
        {
        	mark[time] = 1;
        	ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}