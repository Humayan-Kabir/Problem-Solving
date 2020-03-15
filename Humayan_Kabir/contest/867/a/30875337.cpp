#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
  int n;
  int fransisco=0,seatle=0;
  string st;
  cin>>n;
  cin>>st;
  char prev=st[0];
  for(int i=0; i<st.length(); i++)
  {
      if(st[i]!=prev)
      {
          if(prev=='F') fransisco++;
          else seatle++;
          prev=st[i];
      }
  }
  if((fransisco>0 or seatle>0) && (seatle>fransisco)) cout<<"YES"<<endl;
  else cout<<"NO"<<endl;
  return 0;
}
