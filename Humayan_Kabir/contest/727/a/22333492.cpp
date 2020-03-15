#include<bits/stdc++.h>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;
int destination,n,k;
vector<int> solution;
vector<int> vct;

int rec(long long int num){
 if(num==destination && k==0){
     k=1;
     vct.push_back(num);
     ///cout<<"inside num "<<num<<endl;
     for (int i=0;i<vct.size() ;i++ )
     solution.push_back(vct[i]);
    return 1;
 }
 if(num>destination) return 0;
 int ret1,ret2;
 vct.push_back(num);
 ///cout<<"outside num "<<num<<endl;
 ret1=rec(2*num);
 ret2=rec((10*num)+1);
 vct.pop_back();
 return ret1|ret2;
}

int main(){
  int a,b,i,j,cas=1,ans,t;
  while (scanf("%d%d",&a,&destination)!=EOF)
  {
      ///cout<<a<<" "<<destination<<endl;
     k=0;
     if(a>destination){
        printf("NO\n");
     }
     else{
        if(rec(a)==1){
            printf("YES\n");
            printf("%d\n",solution.size());
            for (i=0;i<solution.size()-1 ;i++ )
            {
               printf("%d ",solution[i]);
            }
            printf("%d\n",solution[solution.size()-1]);
        }
        else
         printf("NO\n");
     }
     solution.clear();
     vct.clear();
  }

 return 0;
}
