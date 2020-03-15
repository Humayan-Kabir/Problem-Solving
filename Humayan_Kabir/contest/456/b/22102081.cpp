#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int a,b,i,j,k,cas=1,ara[5];
  ara[1]=6;
  ara[2]=9;
  ara[3]=6;
  ara[0]=3;
  string str;
  while (getline(cin,str))
  {
     k=str.size();
     if(k>1){
        a=(str[k-1]-'0')+10*(str[k-2]-'0');
     }
     else
       a=(str[k-1]-'0');
     if(a%2==0){
        printf("%d\n",(ara[a%4]+1)%5);
     }
     else{
        printf("%d\n",(ara[a%4]+4)%5);
     }
  }


 return 0;
}
