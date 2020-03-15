/*input
3
1 1 1
*/
#include <bits/stdc++.h>
#include <random>
typedef long long int ll;
using namespace std;
int cnt[5050],last[5005] ,result[5050];
int main(int argc, char const *argv[])
{
    int n, ara[5050];
    scanf("%d",&n);
    for(int i = 1; i<=n; i++) 
    scanf("%d",&ara[i]);
    for(int i = 1; i<=n; i++)
    {
        priority_queue< pair<int,pair<int,int> > > PQ;
        memset(cnt, 0 , sizeof cnt);
        memset(last,-1,sizeof last);
        for(int k = i; k<=n; k++)
        {
           if(last[ara[k]]==-1) last[ara[k]] = k;
           cnt[ara[k]]++;
           PQ.push({cnt[ara[k]],{-ara[k], ara[k]}});
           int best = PQ.top().second.second;
          // cout<<i<<" "<<k<<" "<<best<<endl;
           result[best]++; 
        }
    }    
    for(int i = 1; i<=n; i++)
        printf("%d ",result[i]);
    return 0;
}
