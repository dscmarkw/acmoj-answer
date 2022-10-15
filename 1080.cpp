#include <iostream>
using namespace std;
template <class elemType>
struct node
{
    elemType data;
    node *previous=NULL;
};
class outOfBound{};
class illegalSize{};
class stackEmpty{};
template <class elemType>
class myStack{
    private:
        node<elemType> *top_p;
        node<elemType> *bottom_p;
    public:
        myStack();
        ~myStack();
        void push(const elemType &x);
        void pop();
        elemType top() const;
        bool empty() const;
};
template <class elemType>
myStack<elemType>::myStack(){
    top_p = bottom_p = new node<elemType>;
    top_p->previous = NULL;
    bottom_p->previous=NULL;
}
template <class elemType>
myStack<elemType>::~myStack(){
    node<elemType> *tmp;
    while(top_p != bottom_p){
        tmp = top_p;
        top_p = top_p->previous;
        delete tmp;
    }
    delete bottom_p;
}
template <class elemType>
void myStack<elemType>::push(const elemType &x){
    node<elemType> *tmp = new node<elemType>;
    tmp->data = x;
    tmp->previous = top_p;
    top_p = tmp;
}
template <class elemType>
bool myStack<elemType>::empty() const{
    return (top_p==bottom_p);
}
template <class elemType>
elemType myStack<elemType>::top() const{
    //if(empty()) throw stackEmpty();
    return top_p->data;
    
}
template <class elemType>
void myStack<elemType>::pop(){
    //if(empty()) throw stackEmpty();
    node<elemType> *tmp=top_p;
    top_p=top_p->previous;
    delete tmp;
}
int main(){
    myStack<int> s;
    string str;
    cin>>str;
    int n=str.length();
    int a,b;
    int cur=0;
    for(int i=0;i<n;i++){
        if(str[i]>='0'&&str[i]<='9'){
            cur=cur*10+str[i]-'0';
            continue;
        }
        if(str[i]=='.'){//运算符后面没有点，所以出现点的时候前面肯定是数字
            s.push(cur);
            //犯错点：这里画蛇添足判断cur是不是0，但是有的时候输入值真的是0
            cur=0;
            continue;
        }
        if(str[i]=='+'){
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(a+b);
            continue;
        }
        if(str[i]=='-'){
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b-a);
            continue;
        }
        if(str[i]=='*'){
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(a*b);
            continue;
        }
        if(str[i]=='/'){
            a=s.top();
            s.pop();
            b=s.top();
            s.pop();
            s.push(b/a);
            continue;
        }
        if(str[i]=='@') break;
    }
    cout<<s.top()<<endl;
    return 0;
}