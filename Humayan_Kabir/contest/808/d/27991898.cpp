#include <iostream>
#include<bits/stdc++.h>

using namespace std;

typedef long long int LL;

int main() {
    int n;
    cin>>n;
    int ara[100007];
    LL sum=0;
    for(int i=0;i<n;i++)
    {
        cin>>ara[i];
        sum+=ara[i];
    }
    
    if(sum&1)
    {
        std::cout << "NO" << std::endl;
        return 0;
    }
    
    LL total=0;
    
    std::set<LL> s;
    
    sum=sum>>1;
    
    for(int i=0;i<n;i++)
    {
        total+=ara[i];
        
        if(sum==total)
        {
            std::cout << "YES" << std::endl;
            return 0;
        }
        if(total>sum && s.find(total-sum)!=s.end())
        {
            cout<<"YES"<<endl;
            return 0;
        }
        s.insert(ara[i]);
    }
    
    reverse(ara,ara+n);
    
    total=0;
    
    s.clear();
    
    for(int i=0;i<n;i++)
    {
        total+=ara[i];
        
        if(sum==total)
        {
            std::cout << "YES" << std::endl;
            return 0;
        }
        if(total>sum && s.find(total-sum)!=s.end())
        {
            cout<<"YES"<<endl;
            return 0;
        }
        s.insert(ara[i]);
    }
    
    std::cout << "NO" << std::endl;
    return 0;
}