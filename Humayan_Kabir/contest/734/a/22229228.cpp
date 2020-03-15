#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
  int a,b,i,j,k,cas=1,ans,t;
  string str;
    while (scanf("%d",&a)!=EOF)
    {
        getchar();
        getline(cin,str);
       b=0;
       j=0;
       for (i=0;i<str.size() ;i++ )
       {
          if(str[i]=='A')
            b++;
          else
            j++;
       }
       if(b>j){
        printf("Anton\n");
       }
       else if(j>b)
        printf("Danik\n");
       else
        printf("Friendship\n");
    }
 return 0;
}
