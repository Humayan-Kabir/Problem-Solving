/*input
QAQQQZZYNOIWIN
*/
#include <bits/stdc++.h>
#define mx 200007
typedef long long int LL;
using namespace std;
int main(int argc, char const *argv[])
{
    string st;
    cin >> st;
    int len = st.length();
    int ans = 0;
    for(int i = 0; i<len - 2; i++)
    {
        if(st[i]!='Q') continue;
        for(int j = i+1; j<len - 1; j++)
        {
            if(st[j]!='A') continue;
            for(int k = j+1 ; k<len; k++)
            {
                if(st[k]=='Q') ans++; 
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
