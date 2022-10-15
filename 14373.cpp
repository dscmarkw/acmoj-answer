#include <iostream>
using namespace std;
int main(){
    int s,n;
    cin>>s>>n;
    int *q=new int[s];
    int front=0,rear=0;
    int opt,x,size=0;
    while(n--){
        cin>>opt;
        switch(opt){
            case 0:
                cin>>x;
                if(size==s-1){
                    int *tmp=new int[s*2];
                    for(int i=0;i<s;i++){
                        tmp[i]=q[i];
                    }
                    s*=2;
                    delete []q;
                    q=tmp;
                }
                q[(++rear)%s]=x;
                rear%=s;
                size++;
                cout<<rear<<" "<<size<<endl;
                break;
            case 1:
                if(!size){
                    cout<<front<<" "<<size<<endl;
                    break;
                }
                front++;
                front%=s;
                size--;
                cout<<front<<" "<<size<<endl;
                break;
            default:
            break;
        }
    }
    delete q;
    return 0;
}