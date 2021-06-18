#include <iostream>
#include <queue>
#include <stack>
using namespace std ;
class node {
public :
    int data ;
    node * left_child ;
    node * right_child;
};
node * root ;
class tree {
private :
    queue <node*> q;

public :

    tree (int x ){
        root = new node;
        root ->right_child = root->left_child = NULL;
        root -> data = x ;
        q.push(root);

    }

    void create_tree (int A[], int size ){
        int  x = - 1 ;
        node *p ,*t ;
        while (!q.empty()){


            p = q.front();
            q.pop();
            int i = 0 ;
            while (i<size){



                if (A[i] != -1) {
                    t = new node;
                    p->left_child = t;
                    t->data = A[i];
                    t->left_child = t->right_child = NULL;
                    q.push(t);
                    i ++ ;


                }

                if (A[i] != -1) {
                    t = new node;
                    p->right_child = t;
                    t->data = A[i];
                    t->right_child = t->left_child = NULL;
                    q.push(t);
                    i++ ;
                }
                else {
                    p = q.front();
                    p ->right_child = NULL ;
                    p ->left_child = NULL ;
                    q.pop();
                    i++ ;
                }

            }


        }



    }


    void preorder (node *t ){
        if (t!=NULL){
            cout<<t->data<<" ";
            preorder(t->left_child);
            preorder(t->right_child);
        }

    }
    void postorder(node *t ){
         if (t!= NULL){
             postorder(t->left_child);
             postorder(t->right_child);
             cout<<t->data<<" ";
         }

    }

    void inorder(node *t){
        if (t!= NULL){
            inorder(t->left_child);
            cout<<t->data<<"\n";
            inorder(t->right_child);

        }

    }

    void I_inorder(node *t){
        stack <node *> st ;


        while (t != nullptr || ! st.empty()){
            st.push(t);
            if (t!= nullptr){
                st.emplace(t);
                t = t->left_child;

            }
            else {
                t = st.top();
                st.pop();
                cout<<t->data << " ";

                t = t->right_child;
            }



        }


    }

    void level_order(node *p ) {
        queue <node *> q;
        q.push(p);
        while (p != NULL || ! q.empty()){
            if (p!= NULL){

            }
        }

    }





};

int main() {
    tree t (5);
    int A[] = {4,3,2,1 , 7 ,8 , -1 , -1 , -1 , -1 ,-1 ,-1 ,-1 ,-1 };
    cout<< "Creating tree ";
    t.create_tree(A, 14);

    cout<<"The preorder of the tree is "<<"\n";
    t.preorder(root);
    /*
   cout<<"The inorder of the tree is "<< "\n ";
   t.inorder(root);
   cout<<"The postorder of the tree is "<<"\n";
   t.postorder(root);*/

    // t.I_inorder(root);






    return 0;
}
