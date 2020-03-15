/*input
3
1 1 10 1
*/
#include <bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[mx];
int parent[mx];
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;
    for(int i = 1; i<=n+1; i++) cin >> ara[i];
    int cnt = n;
    for(int i = 1; i<=n; i++)
    {
        if(ara[i] > 1 && ara[i+1] > 1) cnt = -1;
    }
    if(cnt == n)
    {
        cout << "perfect"<<endl;
        return 0;
    }
    else
    {
        cout <<"ambiguous"<<endl;
        parent[1] = 0;
        int node = 2;
        int prev = 1;
        for(int i = 2; i<=n+1; i++)
        {
            int now = INT_MAX;
            for(int j = 1; j<=ara[i]; j++) 
            {
                parent[node] = prev;
                now = min(now,node);
                node++;
            }
            prev = now;
        }
        for(int i = 1; i<node; i++)
        {
            if(i == 1) cout << parent[i];
            else cout <<" "<<parent[i];
        }
        cout << endl;
        vector<int> lev,nexlev;
        parent[1] = 0;
        lev.push_back(1);
        node = 2;
        for(int i = 2; i<=n+1; i++)
        {
            int now = ara[i];
            for(int j = 0; j<lev.size() - 1; j++)
            {
                if(now == 0) continue;
                parent[node] = lev[j];
                nexlev.push_back(node);
                now--;
                node++;
            }
            if(now > 0)
            {
                for(int j = lev.size() - 1; j<lev.size(); j++)
                {
                    while(now)
                    {
                         parent[node] = lev[j];
                         nexlev.push_back(node);
                         now--;
                         node++;
                    }
                }
            }
            lev.clear();
            lev = nexlev;
            nexlev.clear();
        }
        for(int i = 1; i<node; i++)
        {
            if(i == 1) cout << parent[i];
            else cout <<" "<<parent[i];
        }
        cout << endl;
    }    

    return 0;
}