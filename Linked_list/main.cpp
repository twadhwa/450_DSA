/*
#include <iostream>
using namespace std ;
class node {
public:
    node *next ;
    int data ;
};

class linked_list {
private:
    node *first ;
    int  n = 5 ;
public :
    linked_list(){

       first = NULL;

}
void create (int A[], int n){
    node *last , *t ;

    first = new node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1 ; i < n ; i ++ ){
        t = new node;
        t->data = A[i];
        t->next = NULL;
        last->next = t ;
        first -> next = t  ;


    }
}

void display(){
    node *t ;
    t = first ;
    int i =0 ;
    while (t!=NULL){
        cout<<"Number _2 "<< t->data << "\n";
        t = t->next;
        i++;
        cout<<"Number"<<i;
    }
}
};
int main (){
    int A[5]={6,53,5,32,4};

    linked_list L;
    L.create(A,5);
    L.display();
    return 0 ;
}
*/

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class linked_list
{
private:
    Node *first;
public:
    linked_list(){first=NULL;}
    linked_list(int A[],int n);
    ~linked_list();
    void Display();
    void Insert(int index,int x);
    int Delete(int index);
    int Length();
    int reverse();
    int reverse_group(int k );
    int duplicates_remove();
    int first_last ();
    int adding_one();
    int linked_list_number();
    int linked_list_sum( linked_list b );
    int intersection(linked_list a , linked_list b );
    friend linked_list intersection(linked_list a , linked_list b );
};
linked_list::linked_list(int A[],int n)
{
    Node *last,*t, *loop;
    int i=0;
    first=new Node;
    first->data=A[0];
    first->next=NULL;
    last=first;for(i=1;i<n;i++)
    {
        t=new Node;
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}
linked_list::~linked_list()
{
    Node *p=first;
    while(first)
    {
        first=first->next;
        delete p;
        p=first;
    }
}
void linked_list::Display()
{
    Node *p=first;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int linked_list::Length()
{
    Node *p=first;
    int len=0;
    while(p)
    {
        len++;
        p=p->next;
    }return len;
}
void linked_list::Insert(int index,int x)
{
    Node *t,*p=first;
    if(index <0 || index > Length())
        return;
    t=new Node;
    t->data=x;
    t->next=NULL;
    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i<index-1;i++)
            p=p->next;
        t->next=p->next;
        p->next=t;
    }
}
int linked_list::Delete(int index)
{
    Node *p,*q=NULL;
    int x=-1;
    if(index < 1 || index > Length())
        return -1;
    if(index==1)
    {
        p=first;
        first=first->next;
        x=p->data;
        delete p;}
    else
    {
        p=first;
        for(int i=0;i<index-1;i++)
        {
            q=p;
            p=p->next;
        }
        q->next=p->next;
        x=p->data;
        delete p;
    }
    return x;
}

// Program to reverse a linked list
int linked_list:: reverse(){
    Node *p , *q , *r ;
    p = first  ;
    q = NULL;
    r = NULL;
    int i =0 ;
    while (p!=NULL){
        r=q;
        q=p;
        p = p -> next ;
        q->next = r ;

    }
    first = q ;


    return 0 ;

}

// Reversing a list in a group
int linked_list:: reverse_group (int k ){
    Node *p, *q , *r ;
    p = first;
    r= NULL;
    q = NULL;
    for (int i =0; i < k ; i ++){
        r= q;
        q=p;
        p = p->next;
        q->next = r ;

    }
    first ->next = p ;
    first = q;
    return 0 ;
}

// Removing duplicates in a sorted list
int linked_list::duplicates_remove(){
    Node *p, *q;
    q = first ;
    p = first->next ;
    while (p!= NULL){

        if (p->data == q->data ){
            q->next = p->next ;
            p= p->next;
        }
        else {
            q = p;
            p = p->next;
        }
    }
    return 0 ;

}

// Function to bring the last element to the start
int linked_list :: first_last (){
    Node *p , *q , *r ;
    r = first ;
    p = first ->next ;
    q = first -> next ->next  ;
    while (q!=NULL){
        r=p;
        p = q ;
        q =q->next;

    }
    p->next = first ;
    r->next = NULL;
    first = p;
    return 0 ;


}

// Adding number to sum of linked list
int linked_list:: adding_one (){
    int sum = 0;
    Node *p , *q , *r;
    q= NULL;
    r= NULL;
    p= first;



    while (p!=NULL){
        r=q;
        q=p;
        p = p -> next ;
        q->next = r ;
        sum = sum*10 + q->data;

    }
    first = q ;
    sum = sum + 1 ;

    while (q!= NULL){
        q->data = sum%10;
        sum=sum/10;
        q = q->next ;
    }
    reverse ();



    return 0 ;

}
// Function to find the number from linked list
int linked_list :: linked_list_number(){
    Node *q,*p;
    p = NULL;
    q = first;
    int sum = 0 ;
    while (q!=NULL){
        p = q ;
        sum = sum*10 + q->data;
        q = q->next ;


    }
    return sum;
}


// Intersection of 2 sorted list
linked_list intersection( linked_list a , linked_list b){
    Node *p, *q, *r,*s;
    linked_list c;
    c.first ->next =NULL;
    r = c.first;

    p = a.first;
    q= b.first;
    while (p->next != NULL || q->next != NULL) {


        if (p->data == q->data) {
            s= new Node ;
            r->data = p->data ;
            r->next = NULL;
            q=q->next;
            r=r->next;



        }
        else if (p->data >= q->data){
            q=q->next ;
        }
        else {
            p =p->next ;
        }
    }
    return c ;

}

int main()
{
    int A[]={1,2,3,4,5};
    int B[] = {2,3,6,7,8};
    linked_list l(A,5);
    linked_list l_1(B, 5);

    intersection(l,l_1);


    return 0;
}