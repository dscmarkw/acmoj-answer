#include <iostream>
#include <numeric>
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
            return (e1>e2);//小于号为最小的在前面，大于号为最大的在前面
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
            elemType mn=(cmp(val[ls(index)],val[rs(index)])?val[ls(index)]:val[rs(index)]);
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

class fraction{
    friend ostream &operator<<(ostream &os,fraction f);
    public:
    int a;//这里要是定义成long long会莫名其妙地RE，所以就只能在重载运算符的时候强制转换一下了
    int b;
    fraction(int A=0,int B=1){
        a=A;
        b=B;
    }
    bool operator>(const fraction &f)const{
        return ((long long int)a*f.b>(long long int)b*f.a);
    }
};
int gcd(int a,int b) {
    if(b == 0) return a;
    return gcd(b,a % b);
}
ostream &operator<<(ostream &os,fraction f){
        os<<f.a<<"/"<<f.b;
        return os;
}
//原理：先把所有(i-1)/i入堆，弹出一个数就把分母相同的前一个数压入
int main(){
    int n,k;
    cin>>n>>k;
    priorityQueue<fraction> q(100);
    for(int i=2;i<=n;i++){
        fraction a(i-1,i);
        q.push(a);
    }
    fraction x;
    int j;
    for(int i=0;i<k;i++){
        x=q.top();
        q.pop();
        for(j=x.a-1;j>0;j--){
            if(gcd(j,x.b)==1) break;
        }
        fraction c(j,x.b);
        q.push(c);
    }
    cout<<x<<endl;
    return 0;
}