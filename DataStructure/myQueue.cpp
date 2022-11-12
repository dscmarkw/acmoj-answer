template<class elemType>
struct Node
{
    elemType val;
    Node<elemType> *next;
};
//采用链式结构储存队列，优点是不用扩容，缺点是消耗额外空间储存指针
class queueEmpty;
template<class elemType>
class myQueue{
    private:
    Node<elemType> *head,*rear;
    public:
    myQueue(){
        head=new Node<elemType>;
        rear=head;
    }
    void push(elemType e){
        rear->next=new Node<elemType>;
        rear=rear->next;
        rear->val=e;
    }
    bool empty(){
        return head==rear;
    }
    elemType top(){
        if(empty()) throw(queueEmpty())
        return head->next->val;
    }
    void pop(){
        if(empty) return;
        Node<elemType> *p=head;
        head=head->next;
        delete p;
    }
    ~myQueue(){
        while(head){
            Node<elemType> *p=head;
            head=head->next;
            delete p;
        }
    }
};