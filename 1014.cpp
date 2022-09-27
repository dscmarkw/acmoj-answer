#include <iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    if(!n){
        cout<<0<<endl;
        return 0;
    }
    int *arr=new int [n];
    for(register int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int x;
    for(register int i=0;i<n;i++){
        scanf("%d",&x);
        arr[i]=x-arr[i];
    }
    long long int ans=0,a=0,b=0;
    x=arr[0];
    if(x>0) a+=x;
    else b-=x;
    for(int i=1;i<n;i++){
        x=arr[i]-arr[i-1];
        if(x>0) a+=x;
        else b-=x;
    }
    ans = (a>b?a:b);
    cout<<ans<<endl;
    return 0;
}