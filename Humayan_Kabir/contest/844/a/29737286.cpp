#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    set<char> s;
    string st;
    cin>>st;
    int k;
    cin>>k;
    if(st.length()<k)
    {
        cout<<"impossible"<<endl;
        return 0;
    }

    for(int i=0;i<st.length();i++) s.insert(st[i]);
    int l=s.size();
    cout<<max(0,k-l)<<endl;

    return 0;
}
