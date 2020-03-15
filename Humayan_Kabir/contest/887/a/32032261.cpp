/*input
100
*/
#include <bits/stdc++.h>
#include <random>
typedef long long int ll;
using namespace std;
int one[110], ara[110];
int main(int argc, char const *argv[])
{
    string st;
    cin>> st;
    for(int i = 0; i<st.length(); i++)
    {
        if(st[i]=='1')
        {
            int cnt = 0;
            for(int j = i+1; j<st.length(); j++)
            {
                if(st[j]=='0')
                cnt++;
            }
            if(cnt>=6) 
            {
                cout<<"yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"no"<<endl;
    return 0;
}
