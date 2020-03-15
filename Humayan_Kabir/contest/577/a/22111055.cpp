#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  long long int a,b,i,j,k,cas=1,ans,t;
    while (scanf("%I64d %I64d",&a,&b)!=EOF)
    {
       ans=0;
       for (i=1;i<=a ;i++ )
       {
          if(b%i==0 && i*a>=b)
            ans++;
       }
       printf("%I64d\n",ans);

    }
 return 0;
}
