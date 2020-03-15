#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
vector<long long int> vct;
int main(){
 long long int a,b,i,j,n,c,k,cas=1,ans,t;
  while (scanf("%lld%lld%lld%lld",&n,&a,&b,&c)!=EOF)
  {

    if(n%4==0){
       printf("0\n");
       continue;
    }
    k=n%4;
    k=4-k;
    if(k==1){
      vct.push_back(a);
      vct.push_back(b+c);
      vct.push_back((2*b)+a);
      vct.push_back(3*c);
    }
    else if(k==2){
        vct.push_back(2*a);
        vct.push_back(b);
        vct.push_back(2*c);
    }
    else if(k==3){
       vct.push_back(a*3);
       vct.push_back(a+b);
       vct.push_back(c);
       vct.push_back(3*b+(a));

    }
    sort(vct.begin(),vct.end());
    cout<<vct[0]<<endl;
    vct.clear();

  }
 return 0;
}
