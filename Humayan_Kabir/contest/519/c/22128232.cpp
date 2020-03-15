#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
 long long int a,b,i,j,k,cas=1,ans,t;
 while (scanf("%lld %lld",&a,&b)!=EOF)
 {
    ans=(a+b)/3;
    if(ans<min(a,b)){
        printf("%lld\n",ans);
    }
    else
     printf("%lld\n",min(a,b));
 }

 return 0;
}
