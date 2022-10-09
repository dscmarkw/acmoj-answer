#include <iostream>
#include <cstdio>
using namespace std;
//这题太仁慈了，告诉你不会超时，要是搞个大点的数据量还得自己建个堆记最大值
namespace LIST
{

    struct NODE {
        // TODO
        int x;
        NODE *next;
    };

    NODE *head = nullptr;
    int len = 0;

    void init() {
        // TODO
        head=new NODE;
        head->next=head;
    }
    NODE* move(int i) {
        // TODO
        NODE *p=head;
        for(int j=0;j<i;j++){
            p=p->next;
        }
        NODE *q=p->next;
        p->next=q->next;
        while(p->next!=head){
            p=p->next;
        }
        p->next=q;
        q->next=head;
        return q;
    }
    void insert(int i, int x) {
        // TODO
        NODE *p=head;
        for(int j=0;j<i;j++){
            p=p->next;
        }
        NODE *tmp=new NODE;
        tmp->x=x;
        tmp->next=p->next;
        p->next=tmp;
        len++;
    }
    void remove(int i) {
        // TODO
        NODE *p=head;
        for(int j=0;j<i;j++){
            p=p->next;
        }
        NODE *tmp=p->next;
        p->next=tmp->next;
        delete tmp;
        len--;
    }
    void remove_insert(int i) {
        //TODO
        move(i);
    }
    void get_length() {
        // TODO
        cout<<len<<endl;
    }
    void query(int i) {
        // TODO
        if(i>=len){
            cout<<"-1"<<endl;
            return;
        }
        NODE *p=head;
        for(int j=0;j<i;j++){
            p=p->next;
        }
        cout<<p->next->x<<endl;
    }
    void get_max() {
        // TODO
        if(len==0){
            cout<<"-1"<<endl;
            return;
        }
        NODE *p=head->next;
        int max=p->x;
        while(p!=head){
            if(p->x>max){
                max=p->x;
            }
            p=p->next;
        }
        cout<<max<<endl;
    }
    void clear() {
        // TODO
        NODE *p=head->next;
        while(p!=head){
            NODE *tmp=p;
            p=p->next;
            delete tmp;
        }
        delete head;
    }
}
int n;
int main()
{
    cin >> n;
    int op, x, p;
    LIST::init();
    for (int _ = 0; _ < n; ++_)
    {
        cin >> op;
        switch(op) {
            case 0:
                LIST::get_length();
                break;
            case 1:
                cin >> p >> x;
                LIST::insert(p,x);
                break;
            case 2:
                cin >> p;
                LIST::query(p);
                break;
            case 3:
                cin >> p;
                LIST::remove(p);
                break;
            case 4:
                cin >> p;
                LIST::remove_insert(p);
                break;
            case 5:
                LIST::get_max();
                break;
        }
    }
    LIST::clear();
    return 0;
}