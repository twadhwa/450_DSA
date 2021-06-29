//
// Created by tushar on 29/06/21.
//

// Heap and sorting techniques
#include <iostream>
using namespace std ;
class Array {
private :
    int A[10] = {40,30,15,20, 10, 12 , 6 } ;
    int size = 10 ;
    int length = 7;
public :

    void insert(int n){
        int i = n;
        int temp = A[n];
        while (i > 0 && temp > A[i % 2 == 0 ? (i/2)-1 : i/2]){
            A[i] = A[i % 2 == 0 ? (i/2)-1 : i/2];
            i = i % 2 == 0 ? (i/2)-1 : i/2;
        }
        A[i] = temp;
    }
    void display (){
        cout<<"The Array is "<< endl;
        for (int i = 0 ; i < 10 ; i++){

            cout<<A[i]<<",";

        }

    }





};




int main() {
    Array Ar ;
    Ar.display();
    Ar.insert(50);
    cout<<endl ;
    Ar.display();
    return 0;
}
