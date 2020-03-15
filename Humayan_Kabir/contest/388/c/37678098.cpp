#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#define mx 1000007
#define sq 330
using namespace std;
typedef long long int LL;
int main()
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    int playeyX = 0, playeyY = 0;
    vector<int> vv;
    for(int i = 1; i<=n; i++)
    {
        int m;
        cin >> m;
        for(int i = 1; i<=m; i++)
        {
            int num;
            cin >> num;
            if(m % 2 == 0)
            {
                if(2 * i <= m) playeyX+=num;
                else playeyY+=num;
            }
            else
            {
                if(i == (m + 1) / 2)
                {
                    vv.push_back(num);
                    continue;
                }
                if(i < (m + 1) / 2) playeyX+=num;
                else playeyY+=num;
            }
        }
    }
    sort(vv.begin(),vv.end());
    int player1 = 1;
    for(int i = vv.size() - 1; i>=0; i--)
    {
        if(player1) playeyX+=vv[i];
        else playeyY+=vv[i];
        player1 = player1 ^ 1;
    }
    cout << playeyX <<" "<<playeyY<<endl;
    return 0;
}