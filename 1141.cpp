#include <iostream>
#include <cstring>
using namespace std;
struct node
{
    string str;
    node *next=nullptr;
};
const int mod1=100007;
const int k=137;
int main(){
    int n;
    cin>>n;
    string x;
    node* hash1[100007];
    node *p;
    for(register int i=0;i<mod1;i++){
        hash1[i]=new node;
    }
    int ans=0;
    for(register int i=0;i<n;i++){
        cin>>x;
        int h=0;
        for(register int j=0;x[j]!='\0';j++){
            h=(h*k+x[j])%mod1;
        }
        p=hash1[h];
        bool find=false;
        while(p!=nullptr){
            if(p->str==x){
                find=true;
                break;
            }
            if(p->next!=nullptr) p=p->next;
            else break;
        }
        if(find) continue;
        ans++;
        p->next=new node;
        p->next->str=x;
    }
    cout<<ans<<endl;
    return 0;
}
