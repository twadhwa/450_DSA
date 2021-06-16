#include <iostream>

using namespace std;
// For programs queue using linked list a
class node {
public :
    int data ;
    node *next ;
};

// For program queue using array
class queue {
private :
    int size ;
    int rear =-1  ;
    int front =-1 ;
    int *A;

public :
    queue(int size) {
        this ->size = size ;

        A = new int[size];
        front = rear = -1;


    }
    ~queue(){

    delete A;

    }
    void enqueue (int x ){
        rear++;
        A[rear] = x ;


    }
    int  dequeue(){
        int x = - 1 ;
        front++ ;
        x = A[front];

        return x ;





    }
    void display (){
        for (int i = front+1; i <= rear; i++){
            cout<<A[i]<<" ";
        }

    }

    // Priority queue using array
    void priority_queue_push(int x ){
        int i , temp ;

        rear ++ ;
        A[rear] = x ;

        for (i = rear ; i >=0 ; i--){
            if (A[i] < A[i-1]){
                temp = A[i];
                A[i] = A[i-1];
                A[i-1] = temp ;
            }
        }

    }





    


};
// linked list class
node * front , * rear ;
class queue_linked_list {
private :
    node * t ;
public :
    void enqueue (int x){
        t = new node ;
        t->data = x ;
        t->next = NULL;
        if (front == NULL ){
            front = rear = t ;




        }
        else {


            rear->next = t;
            rear = t ;
        }

    }

    int  dequeue () {
        int x;

        if (front == rear ){
            cout<<"Queue is empty";

        }
        else {
            x = front->data ;
            front = front->next ;

        }
        return x ;
    }
    void display (){
        node *p ;
        p = front;

        while (p ){
            cout<<p->data<<" ";
            p = p->next;
        }




    }
    int reverse_till_k (int k ){
        node *p, *q , *r ;
        p = front;
        r= NULL;
        q = NULL;
        for (int i =0; i < k ; i ++){
            r= q;
            q=p;
            p = p->next;
            q->next = r ;

        }
        front->next = p ;
        front = q;
        return 0 ;
    }





};
node *top = NULL ;
class stack_linked_list{
private :
    node *t ;
public :

    void push (int x ){
        t = new node ;
        if (t == NULL ){
            cout<<"Stack overflow";

        }
        else {
            t ->next = top ;
            t ->data = x ;
            top = t ;
        }





    }
    int pop (){
        int x ;
        node * p = top ;
        if (top == NULL){
            cout<<"Stack empty ";
        }
        else {
            x = p->data ;
            p  = p ->next ;

        }
        return x ;
    }


    void display (){
        node * p = top ;
        while (p){
            cout<<p->data<<" ";
            p = p ->next;

        }

    }






};




class stack {
private :
    int size ;
    int top = - 1;
    int *A;
public:
    stack (int size ){
        A = new int[size];
        top = -1;

    }
    ~stack (){
        delete []A;

    }
    void display(){
        for (int i = top ; i>0; i--){
            cout<<A[i]<<" ";
        }
    }

    void push (int x ){
        if (top == size-1){
            cout<<"Stack overflow";

        }
        else {top++;
            A[top] = x ;

        }


    }

};




int main() {
    stack st  (5);
    st.push(5);
    st.push(6);
    st.push(7);
    st.display();
    cout<<"Hello ";

    return 0;
}

