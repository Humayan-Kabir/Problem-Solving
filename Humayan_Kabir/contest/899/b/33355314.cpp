/*input
3
31 31 28
*/
#include<bits/stdc++.h>
#define mx 200007
using namespace std;
typedef long long int LL;
int ara[] = {31,28,31,30,31,30,31,31,30,31,30,31};
int main(int argc, char const *argv[])
{
    ios_base::sync_with_stdio(false);
    int a[30];
    int n;
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> a[i];
    int flag = 0;
    for(int i = 0; i<12; i++)
    {
        int now = i, february = 0, cnt = 0;
        for(int j = 0; j<n; j++)
        {
            int pos = now % 12;
            if(pos == 1)
            {
                if(a[j] == 29) february++;
                else if(a[j] == 28) cnt++;
            }
            else if(ara[pos] == a[j]) cnt++;
            now++;
        }
        if(february<=1 && february + cnt == n) flag = 1; 
    }
    if(flag) cout <<"YES"<<endl;
    else cout <<"NO"<<endl;
    return 0;
}