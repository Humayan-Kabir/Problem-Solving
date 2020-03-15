#include<bits/stdc++.h>
using namespace std;
int main()
{
   long long int n,pos,m_pos,val,i,j,k;
   while (scanf("%lld%lld",&n,&pos)==2)
   {
      m_pos=0;
      for (i=n;i>=1 ;i-- )
      {
         if(m_pos==pos){
            //val=i;
            break;
         }
        else if(m_pos<pos){
            m_pos+=(pow(2,i)/2);
            val=i;
         }
        else if(m_pos>pos){
            m_pos-=(pow(2,i)/2);
            val=i;
        }
      }
      printf("%lld\n",val);
   }

   return 0;
}
