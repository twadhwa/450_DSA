// Sorting techniques



#include <iostream>
using namespace std;

// Swapping variables
int swap(int *a , int *b){
    int temp ;
    temp = *a ;
    *a = *b ;
    *b = temp ;
    return 0  ;


}

// Bubble sort
// 1) Time complexity worst O(n2)
// 2) Time complexity best O(n)
// 3) We can make this sorting technique adaptive using a variable flag
// 4) Bubble sort is stable
int bubble_sort (int Arr[] , int n ){
    for (int i = 0; i<n-1 ; i++){
        int flag = 0;
        for (int j = 0; j<n-1-i ; j++){
            if (Arr[j]>Arr[j+1]){
                flag = 1  ;
                swap(Arr[j],Arr[j+1]);
            }
        }
        if (flag == 0 ){
            break ;
        }
    }
    return 0 ;

}

// Insertion sort
// 1) Time complexity worst O(n2)
// 2) Time complexity best O(n)
// 3) Insertion sort is adaptive by nature
// 4) Insertion sort is stable

int insertion_sort(int Arr [] , int n ){
    for (int i = 1 ; i<n ; i++){
        int x = Arr[i];
        int j = i-1;
        while (j>-1 && Arr[j]>x){
            Arr[j+1] = Arr[j];
            j--;
        }
        Arr[j+1] = x;
    }

    return 0 ;
}

// Selection sort
// 1) Time complexity worst O (n2)
// 2) Time complexity best O(n2)
// 3) It is not adaptive by nature
// 4) It is not stable
int selection_sort(int Arr[] , int n ){
    for (int i =0 ; i<n ; i++){
        int j = i , k =i;
        for (j; j<n ; j++){
            if(Arr[j] < Arr[k] ){
                k = j;
            }
        }

        swap(Arr[k] , Arr[i]);



    }
    return 0 ;
}


// Count Sort
// The best time complexity of the sort is O(n)
// The worst time complexity of the sort is O(n)
// It is not adaptive
// It is stable sort
int count_sort(int Arr[] , int n ){
    int max =0 ;
    // Finding the maximum element
    for (int i = 0 ; i < n ; i++){
        if (Arr[i] > max ){
            max = Arr[i];
        }
    }

    // Creating a new array of size max
    int c[max+1];
    for (int i=0 ; i<max +1  ; i++){
        c[i] = 0 ;
    }

    // Initializing that array with values
    for (int i =0 ; i<n ; i++){
        c[Arr[i]] ++ ;
    }


    //Loop for sorting the array

    int i = 0 , j =0 ;
    while (i < max+1 ){
        if (c[i] > 0 ){
            Arr[j++] = i ;

            c[i]--;
        }
        else {
            i++;
        }
    }
    return 0 ;
}

// Class for bin sort
class node {
private :
    int data ;
    node * p;
};

// Insertion function for insertion in a linked list
int insert(){

}

int bin_sort (int Arr[] , int n ){
    int max = 0 ;
    for (int i = 0 ; i < n ; i++){
        if (Arr[i] > max ){
            max = Arr[i];
        }
    }

    node **c ;
    c = new node *[max+1] ;
    for (int i = 0  ; i < max +1 ; i++){
        c[i] = NULL;
    }
    for (int i = 0 ; i< n ; i++){
        new node ;
    }
}



int main() {
    int Arr[6] = {7,3,9,9,2,1};
    int n =6 ;
    cout<<"Array before sorting " ;

    for (int i = 0 ; i < n ; i++){
        cout<<Arr[i]<<" ";
    }

    cout<<endl;
    count_sort(Arr,n);
    cout<<"Array after sorting ";
    for (int i = 0 ; i < n ; i++){
        cout<<Arr[i]<<" ";
    }




    return 0;
}

