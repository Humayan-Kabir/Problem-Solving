#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#define mx 3000002
#define sq 330
using namespace std;
typedef long long int LL;
int n, ara[mx], mark[1000002];
vector<int> divisor[1000002];
int bestl[mx], bestr[mx], last[mx], dp[mx];
int main()
{
    scanf("%d",&n);
    int one = 0;
    for(int i = 1; i<=n; i++)
    {
        scanf("%d",&ara[i]);
        mark[ara[i]] = 1;
        if(ara[i] == 1) one++;
    }
    if(one > 0)
    {
        printf("1 %d\n",n - 1);
        printf("1\n");
        return 0;
    }
    for(int i = 2; i<=1000000; i++)
    {
        for(int j = i; j<=1000000; j+=i)
        {
            if(mark[j]) divisor[j].push_back(i);
        }
    }

    for(int v : divisor[ara[1]])
        last[v] = 1;
    bestl[1] = 1;
    last[1] = 1;
    for(int i = 2; i<=n; i++)
    {
        for(int v : divisor[ara[i]])
        {
            if(ara[i - 1] % v != 0)
            {
                last[v] = i;
            }
        }
        bestl[i] = last[ara[i]];
    }
    for(int v : divisor[ara[n]])
        last[v] = n;
    bestr[n] = n;
    last[1] = n;
    int ans = 0;
    for(int i = n - 1; i>=1; i--)
    {
        for(int v : divisor[ara[i]])
        {
            if(ara[i + 1] % v != 0) last[v] = i;
        }
        bestr[i] = last[ara[i]];
        dp[bestl[i]] = max(dp[bestl[i]],bestr[i] - bestl[i]);
        ans = max(ans,bestr[i] - bestl[i]);
    }
    dp[bestl[n]] = max(dp[bestl[n]],bestr[n] - bestl[n]);

    int cnt = 0;
    vector<int> hudai;
    for(int i = 1; i<=n; i++)
    {
        if(dp[i] == ans)
        {
            cnt++;
            hudai.push_back(i);
        }
    }
    printf("%d %d\n",cnt,ans);
    for(int i = 0; i < cnt; i++)
    {
        if(i == 0) printf("%d",hudai[i]);
        else printf(" %d",hudai[i]);
    }
    printf("\n");
    return 0;
}