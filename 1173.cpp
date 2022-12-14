#include <iostream>
using namespace std;
void quick_sort(long long int *a,int l,int r){
    if(l>=r) return;
    int i=l,j=r;
    int key=a[l];
    while(i<j){
        while(i<j&&a[j]>=key) j--;
        a[i]=a[j];
        while(i<j&&a[i]<=key) i++;
        a[j]=a[i];
    }
    a[i]=key;
    quick_sort(a,l,i-1);
    quick_sort(a,i+1,r);
}
int main(){
    int n;
    cin>>n;
    long long int *a=new long long int [n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    quick_sort(a,0,n-1);
    long long int *b=new long long int [n];
    for(int i=0;i<n;i++){
        cin>>b[i];
    }
    quick_sort(b,0,n-1);
    long long int ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i]*b[i];
    }
    cout<<ans<<" ";
    ans=0;
    for(int i=0;i<n;i++){
        ans+=a[i]*b[n-i-1];
    }
    cout<<ans<<endl;
    return 0;
}