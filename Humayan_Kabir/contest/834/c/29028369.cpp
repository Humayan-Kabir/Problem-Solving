#include<bits/stdc++.h>
using namespace std;
typedef long long int LLI;
LLI oka[1000006];

int idx(LLI num){
    if(num<1){
        return -1;
    }
    if(num==1){
        return 1;
    }
    int lo = 1;
    int hi = 1000001;
    while(lo<=hi){
        int mid = (lo+hi)/2;
        if(oka[mid]==num){
            return mid;
        }
        else if(oka[mid]>num){
            hi=mid-1;
        }
        else{
            lo = mid+1;
        }
    }
    return -1;
}

void pre(){
    for(int i=1;i<=1000001;i++){
        LLI s = ((LLI)i*(LLI)i*(LLI)i);
        oka[i]=s;
    }
}

int main(){
    int t;
    scanf("%d",&t);
    pre();
    while(t--){
        int a,b;
        scanf("%d %d",&a,&b);
        LLI ss = (LLI)a*b;
        int id = idx(ss);
        if(id==-1){
            printf("No\n");
        }
        else{
            if(a%id==0 && b%id==0)
            printf("Yes\n");
            else printf("No\n");
        }
    }
    return 0;
}
