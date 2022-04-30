#include <iostream>

using namespace std;
template<class T>
class Node {
    public:
    T data;
    Node* next;
    //Node(T, Node* n=0);
     Node* getNext();

      void setNext(Node* );

       T getInfo ();

       void setInfo (T);
};
template<class T>
void Node<T>::setNext(Node* n)
{
    next=n;
}
template<class T>
Node<T>* Node<T>::getNext()
{
    return next;
}
template<class T>
void Node<T>::setInfo(T i)
{
    data=i;
}
template<class T>
T Node<T>::getInfo()
{
    return data;
}

template<class T>
class SLL {

    Node<T> *head, *tail;
    public:
    SLL(){head = tail = NULL;}
    void addtoHead(T);
    void addtoTail(T);
    T removeFromHead();
    T removeFromTail();
    T getValueAtHead();//a function that returns the value at head without deleting it
    bool isEmpty();
    void Clear();
    friend ostream& operator<<(ostream& out, const SLL<T>& LL);
    void print();
};
    template<class T>
    bool SLL<T>::isEmpty()
    {
        if(head==NULL)
        {
            return true;
        }
        else{
            return false;
        }
    }
    template<class T>
    void SLL<T>::addtoHead(T value)
    {
        Node<T>* newnode=new Node<T>;

        newnode->data=value;
        newnode->next=head; //value of old head =NULL
        head=newnode;  //now head refer to newnode
    }
    template<class T>
    void SLL<T>::addtoTail(T value)
    {
        if(head==NULL)
        {
            addtoHead(value);
        }
        else
        {
        Node<T> *current=new Node<T>;
        current=head;
        while(current->next!=NULL)
            {current=current->next;}
        //here current=NULL
        Node<T> *newnode=new Node<T>;
        newnode->next=NULL;
        newnode->data=value;
        current->next=newnode; //refer to  last node
        }
    }
    template<class T>
    T SLL<T>::removeFromHead()
    {
        if(isEmpty())
            {return false;}
        else{
        T value;
        Node<T>* current=head;
        value=current->data;
        head=head->next;
        delete current;
        return value;
        }
    }
    template<class T>
    T SLL<T>::removeFromTail()
    {
        if(isEmpty())
        {
            return false;
        }
        else{
        T value;
        Node<T>* prev=NULL;
        Node<T>* current=head;
        while(current->next!=NULL)
        {
            prev=current;
            current=current->next;
        }
        //here current=NULL
        value=current->data;
        prev->next=NULL; //=NULL
        delete current;

        return value;
        }
    }
    template<class T>
    T SLL<T>::getValueAtHead()
    {
        if(isEmpty())
            return false;
        else{
        return head->data;
        }
    }
    template<class T>
    void SLL<T>::Clear()
    {

        while(head!=NULL)
        {
            Node<T>* current=head;
            head=head->next;
            delete current;
        }
    }
    /*template<class T>
     ostream& operator<<(ostream& out, const SLL<T>& LL)
    {
        Node<T> *n=head;
        while(n!=NULL)
        {
            out<< n -> data << endl;
            n=n->link;

        }
        return out;

    }*/
    template <class T>
    void SLL<T>::print()
    {
        Node<T>* current=head;
        while(current!=NULL)
        {
            cout<<current->data<<"->";
            current=current->next;
        }
        cout<<endl;
    }


int main()
{
    SLL<int> l;
    int m;
    cout<<"enter the first"<<endl;
    cin>>m;
    l.addtoHead(m);

    for(int i=0;i<4;i++)
    {
        cout<<"Enter element"<<endl;
        cin>>m;
        l.addtoTail(m);
    }
    l.print();
    cout<<"the value of head = "<<l.getValueAtHead()<<endl;
    l.removeFromHead();
    l.removeFromTail();


    l.print();
    cout<<"the value of head = "<<l.getValueAtHead()<<endl;

    l.Clear();
    l.print();
    cout<<"List has been deleted"<<endl;
    return 0;
}
