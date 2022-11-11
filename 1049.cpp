#include <iostream>
#include <cstring>
using namespace std;
#define fa(p) p>>1
#define ls(p) p<<1
#define rs(p) ((p) << 1 | 1)
void premid(char pre[],char mid[],int l,int r, int &index,char tree[],int pos);
int main(){
    char pre[1000],mid[1000],tree[1000]={0};
    cin>>pre;
    cin>>mid;
    int n,i,cnt=0;
    int index=0;
    for(n=0;pre[n]!=0;n++);
    premid(pre,mid,0,n-1,index,tree,1);
    i=1;
    while(cnt<n){
        if(tree[i]!=0){
            printf("%c ",tree[i]);
            i++;
            cnt++;
        }
        else{
            printf("NULL ");
            i++;
        }
    }
    cout<<endl;
    return 0;
}
void premid(char pre[],char mid[],int l,int r, int &index,char tree[],int pos){
    if(l>r) return;
    tree[pos]=pre[index];
    index++;
    if(l==r){
        tree[ls(pos)]=0;
        tree[rs(pos)]=0;
        return;
    }
    int i;
    for(i=0;mid[i]!=pre[index-1];i++);
    premid(pre,mid,l,i-1,index,tree,ls(pos));
    premid(pre,mid,i+1,r,index,tree,rs(pos));
}