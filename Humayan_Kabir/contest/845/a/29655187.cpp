#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ios_base::sync_with_stdio(false);
    set<int> vt;
    int n;
    cin>>n;
    int a[2*n+5];
    for(int i=0;i<2*n;i++)
    {
    cin>>a[i];
    }
    sort(a,a+2*n);
   reverse(a,a+2*n);
     int fs=0;
     int sc=0;
     for(int i=0,j=2*n-1;i<n;i++,j--)
     {
         if(a[i]<=a[j])
            sc++;
         else fs++;
     }
     if(sc)
     cout<<"NO\n";
     else cout<<"YES\n";

    return 0;
}
