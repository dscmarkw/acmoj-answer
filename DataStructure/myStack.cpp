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
        if(empty()) throw stackEmpty();
        return top_p->data;
}
template <class elemType>
void myStack<elemType>::pop(){
        if(empty()) throw stackEmpty();
        node<elemType> *tmp=top_p;
        top_p=top_p->previous;
        delete tmp;
}