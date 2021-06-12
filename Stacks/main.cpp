#include <iostream>
using namespace std ;
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
    stack st (5);
    st.push(5);
    st.push(6);
    st.push(7);
    st.display();

    return 0;
}
