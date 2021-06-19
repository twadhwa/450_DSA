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

    void create_tree (node *p){
        int  x = - 1 ;
        node  *t ;
        while (!q.empty()){


            p = q.front();
            q.pop();

            cout<< "Enter the left child of "<< p->data << " ";
            cin >>x ;
            if (x != -1) {
                t = new node;
                p->left_child = t;
                t->data = x ;
                t->left_child = t->right_child = NULL;
                q.push(t);



            }
            cout<<"Enter the right child of "<<p->data<<" ";
            cin>>x ;
            if ( x != -1) {
                t = new node;
                p->right_child = t;
                t->data = x ;
                t->right_child = t->left_child = NULL;
                q.push(t);

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
            cout<<t->data<<" ";
            inorder(t->right_child);

        }

    }

    void I_inorder(node *t){
        stack <node *> st ;


        while (t != nullptr || ! st.empty()){
            st.push(t);
            if (t!= nullptr){
                st.push(t);
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
        node *t ;
        t = p ;
        cout<<t->data<<" ";

        q.push(t);
        while (! q.empty()){
            if (t->left_child!=NULL){
                q.push(t->left_child);

                cout<<t->left_child->data<<" ";




            }
            if (t->right_child!=NULL){
                q.push(t->right_child);
                cout<<t->right_child->data<<" ";

            }
            cout<<" ";
            q.pop();
            t = q.front();



        }

    }

    int count_node (node *p){
        int x , y ;
        if (p!=NULL){
            x = count_node(p->left_child);
            y = count_node(p->right_child);
            return x + y + 1 ;
        }
        return 0 ;


    }
    int leafNodeCount(node *p) {
        int x;
        int y;
        if (p != NULL){
            x = leafNodeCount(p->left_child);
            y = leafNodeCount(p->right_child);
            if (p->left_child == NULL && p->right_child == NULL){
                return x + y + 1;
            }
            else {
                return x + y;
            }
        }
        return 0;
    }

    void iterativePostorder(node *p) {
        stack<long int  > stk;
        long int temp;
        while (p != nullptr || ! stk.empty()){
            if (p != nullptr){
                stk.push((long int )p);
                p = p->left_child;
            } else {
                temp = stk.top();
                stk.pop();
                if (temp > 0){
                    stk.push(-temp);
                    p = ((node*)temp)->right_child;
                } else {
                    cout << ((node*)(-1 * temp))->data << " ";
                    p = nullptr;
                }
            }
        }
        cout << endl;
    }





};

int main() {
    tree t (5);
    int A[] = {4,3,2,1 , 7 ,8 , -1 , -1 , -1 , -1 ,-1 ,-1 ,-1 ,-1 };
    cout<< "Creating tree "<<"\n";




    t.create_tree(root);

    cout<<"The postorder of the tree is "<<"\n";
    t.iterativePostorder(root);
    cout<<"The preorder of the tree is "<<"\n";


    t.preorder(root);
    cout<<"\n";
    cout<<"The level order of the tree is "<<"\n";
    t.level_order(root);
    cout<< "\n";


    cout<<"The inorder of the tree is "<< "\n ";
    t.inorder(root);
    cout<<"\n"; 
    cout<<"The postorder of the tree is "<<"\n";
    t.postorder(root);








    return 0;
}
