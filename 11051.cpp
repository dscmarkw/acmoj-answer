#include <iostream>
using namespace std;
struct node
{
    int val;
    node *next=NULL;
};

int main(){
    int n,m;
    cin>>n;
    node *head=new node;
    node *p=head,*q;
    for(int i=0;i<n;i++){
        p->next=new node;
        p=p->next;
        cin>>p->val;
    }
    cin>>m;
    int search;
    int cnt=0;
    for(int i=0;i<m;i++){
        cin>>search;
        p=head->next;
        q=head;
        while(++cnt&&p->val!=search&&p->next!=NULL){
            p=p->next;
            q=q->next;
        }
        if(p->val!=search) continue;
        q->next=p->next;
        p->next=head->next;
        head->next=p;
    }
    cout<<cnt<<endl;
    return 0;
}