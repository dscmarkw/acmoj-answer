#include <iostream>
using namespace std;
#define fa(p) p>>1
#define ls(p) p<<1
#define rs(p) ((p) << 1 | 1)
template<class elemType>
class priorityQueue{
    private:
        elemType* val;
        int maxSize;
        int currentSize=0;
    public:
        priorityQueue(int s=1e7+7){
            maxSize=s;
            val=new elemType [s];
        }
        priorityQueue(int size,elemType sval[]){
            maxSize=size;
            val=new elemType [size];
            buildQueue(size,sval);
        }
        bool cmp(elemType e1,elemType e2){
            return (e1<e2);//小于号为最小的在前面，大于号为最大的在前面
        }
        void buildQueue(int size,elemType sval[]){
            for(int i=1;i<=size;i++){
                val[i]=sval[i];
                currentSize++;
            }
            for(int i=currentSize;i>=1;i--){
                pushup(i);
            }
        }
        void swap(int a,int b){
            elemType tmp=val[a];
            val[a]=val[b];
            val[b]=tmp;
        }
        void pushdown(int index){
            if(ls(index)>currentSize) return;//叶子节点
            if(rs(index)>currentSize){
                if(cmp(val[ls(index)],val[index])){
                    swap(ls(index),index);
                }
                return;
            }
            int mn=(cmp(val[ls(index)],val[rs(index)])?val[ls(index)]:val[rs(index)]);
            if(cmp(val[index],mn)) return;
            if(cmp(val[ls(index)],val[rs(index)])){
                swap(ls(index),index);
                pushdown(ls(index));
            }
            else{
                swap(rs(index),index);
                pushdown(rs(index));
            }
        }
        void pushup(int index){
            if(index==1) return;
            if(cmp(val[index],val[fa(index)])){
                swap(index,fa(index));
                pushup(fa(index));
            }
        }
        void push(elemType e){
            if(currentSize==maxSize){
                maxSize<<=1;
                elemType *tmp=new elemType [maxSize];
                for(int i=1;i<=currentSize;i++){
                    tmp[i]=val[i];
                }
                delete [] val;
                val=tmp;
            }
            val[++currentSize]=e;
            pushup(currentSize);
        }
        void pop(){
            swap(1,currentSize--);
            pushdown(1);
        }
        elemType top(){
            return val[1];
        }
        int size(){
            return currentSize;
        }
};
int main(){
    int n;
    cin>>n;
    long int x;//有个节点爆int
    priorityQueue<long int> q;
    for(register int i=0;i<n;i++){
        cin>>x;
        q.push(x);
    }
    long int ans=0,a,b;
    for(register int i=0;i<n-1;i++){
        a=q.top();
        q.pop();
        b=q.top();
        q.pop();
        ans+=a+b;
        q.push(a+b);
    }
    cout<<ans<<endl;
    return 0;
}