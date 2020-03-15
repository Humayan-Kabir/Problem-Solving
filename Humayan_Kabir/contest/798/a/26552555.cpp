#include<bits/stdc++.h>
using namespace std;
int main()
{
   string a,b;
   cin>>a;
   b=a;
   int ln=a.length();
   int x=b.length()-1;
   int c=0,pos;
   for(int i=0;i<ln;i++)
   {
      if(a[i]!=b[x])
      {
          c++;
          pos=i;

      }
      x--;
   }
   if(c==2)
   {
       cout<<"YES"<<endl;
   }
   else if(a.length()%2!=0 && c==0)
   {
       cout<<"YES"<<endl;
   }
   else cout<<"NO"<<endl;
  return 0;
}
