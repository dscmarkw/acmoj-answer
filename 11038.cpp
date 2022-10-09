#include <iostream>
using namespace std;
struct node{
    int x;
    node *next;
};
//只需模拟即可，构造一个循环链表，每次删除第n个节点即可
int main(){
    int m;
    cin>>m;
    int cur=m;
    node *head=new node;
    node *p=head,*q;
    for(int i=1;i<=m;i++){
        node *tmp=new node;
        tmp->x=i;
        p->next=tmp;
        p=tmp;
    }
    p->next=head->next;
    int n;
    q=p;
    p=p->next;
    for(int i=0;i<m-1;i++){
        cin>>n;
        for(int j=0;j<(n-1)%cur;j++){
            q=p;
            p=p->next;
        }
        q->next=p->next;
        delete p;
        p=q->next;
        cur--;
    }
    cout<<p->x<<endl;
    return 0;
}