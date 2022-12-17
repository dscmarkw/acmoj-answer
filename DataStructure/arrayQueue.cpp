#include <iostream>
using namespace std;
template<class elemType>
class arrayQueue{
    private:
    int size;
    elemType *arr;
    int head,rear;
    public:
    arrayQueue(int _s=10){
        arr=new elemType [_s];
        head=rear=0;
    }
    bool empty(){
        return (head==rear);
    }
    void doubleSize(){
        elemType *tmp=new elemType [size<<1];
        for(register int i=0;i<size;i++){
            tmp[i]=arr[i];
        }
        delete arr;
        arr=tmp;
    }
    inline bool full(){
        return (rear+1)%size==head;
    } 
    void push(const elemType &e){
        if(full()) doubleSize();
        arr[rear]=e;
        rear=(rear+1)%size;
    }
    elemType front() const{
        return arr[head];
    }
    void pop(){
        if(empty()) return;
        head=(head+1)%size;
    }
    ~arrayQueue(){
        delete arr;
    }
};
int main(){
    arrayQueue<int> q;
    int n;
    cin>>n;
    int x;
    for(register int i=0;i<n;i++){
        cin>>x;
        q.push(x);
    }
    while(!q.empty()){
        x=q.front();
        q.pop();
        cout<<x<<" ";
    }
    cout<<endl;
    return 0;
}