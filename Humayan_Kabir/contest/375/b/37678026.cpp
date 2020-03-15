#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#define mx 3000002
#define sq 330
using namespace std;
typedef long long int LL;
vector<int> vv[5010];
int main()
{
    ios_base::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    for(int i = 1; i<=n; i++)
    {
        string str;
        cin >> str;
        int prev = -1, was[5010];
        was[m + 1] = -1;
        for(int i = m; i>=1; i--)
        {
           if(str[i-1] == '1')
           {
               if(was[i + 1] != -1) was[i] = was[i + 1];
               else was[i] = i;
           }
           else
           {
               was[i] = -1;
           }

           if(was[i] != -1)
           {
               vv[i].push_back(was[i] - i + 1);
           }
        }
    }
    int ans = 0;
    for(int i = 1; i<=m; i++)
    {
        sort(vv[i].begin(),vv[i].end());
        int sz = vv[i].size(), cur = 0;
        for(int j = sz - 1; j>=0; j--)
        {
            cur++;
            int now = vv[i][j] * cur;
            ans = max(ans,now);
        }
    }
    printf("%d\n",ans);
    return 0;
}