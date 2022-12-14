#include <bits/stdc++.h>
using namespace std;
bool h[1001]={0};
int main(){
    int n;
    cin>>n;
    int cnt=n;
    int x;
    for(register int i=0;i<n;i++){
        cin>>x;
        if(h[x]){
            cnt--;
            continue;
        }
        else h[x]=1;
    }
    cout<<cnt<<endl;
    for(register int i=1;i<=1000;i++){
        if(h[i]) cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}