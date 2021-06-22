#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
    Node() {};
    Node(int data);
};

Node::Node(int data) {
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}

Node *root ;
class Tree{
private:
    Node * root ;
public:
    Tree();
    void CreateTree();
    void Preorder(Node* p);
    void Preorder() { Preorder(root); }  // Passing Private Parameter in Constructor
    void Inorder(Node* p);
    void Inorder() { Inorder(root); }
    void Postorder(Node* p);
    void Postorder() { Postorder(root); }
    void Levelorder(Node* p);


    Node* generateFromTraversal(int inorder[], int preorder[], int inStart, int inEnd);

    // Searching in  a  binary search tree

    Node *  search(Node * t , int x ){
        int a = 0 ;
        while (t!=NULL){
            if (t->data == x ){
                return t ;
            }
            else if (t->data > x ){
                t = t->lchild;
            }
            else {
                t = t->rchild;
            }
            a = a+1 ;
        }

        return NULL ;

    }
    // Insertion in a BST iterative
    void  insertion_iterative(Node *p , int x ){
        Node *t , *r ;
        t = new Node ;
        t->data = x ;
        t->lchild = t->rchild = NULL ;
        while (p!= NULL ){
            r = p ;
            if (p==NULL){

                return  ;
            }
            else if (p->data > x ){
                p = p->lchild;

            }
            else {
                p = p->rchild;
            }
        }
        if (r->data < x ){
            r->rchild = t ;

        }
        else {
            r->lchild = t ;
        }


    }

    // Insertion in a BST using recursion
    Node *  insertion_recursive (Node *p , int x ){
        Node *t ;
        if (p==NULL){
            t = new Node ;
            t->lchild = t ->rchild = NULL;
            t->data = x ;
            return t ;

        }

        if (p->data > x ){
            p->lchild = insertion_recursive(p->lchild , x );
        }

        else if (p->data < x ){
            p->rchild = insertion_recursive(p->rchild ,x ) ;
        }
        return p;

    }
    int Height(Node *p) {
        int x;
        int y;
        if (p == nullptr){
            return 0;
        }
        x = Height(p->lchild);
        y = Height(p->rchild);
        return x > y ? x + 1 : y + 1;
    }

    Node* InPre(Node *p) {
        while (p && p->rchild != nullptr){
            p = p->rchild;
        }
        return p;
    }

    Node* InSucc(Node *p) {
        while (p && p->lchild != nullptr){
            p = p->lchild;
        }
        return p;
    }
/*
    Node * Delete_recursive(Node * p , int x ){
        Node *q ;

        // For cominng out of recursion
        if (p==NULL ){
            return NULL ;
        }
        if (p->lchild == NULL && p->rchild == NULL ){


            free ( p );
            return NULL ;
        }




        // Same part as searching in a tree
        if (p->data > x ){
            p->lchild = Delete_recursive(p->lchild ,x );
        }
        else if (p->data < x ){
            p->rchild = Delete_recursive(p->rchild , x ) ;
        }

        // Comparing height of the right sub tree with the height of the left subtree
        else {
            // Checking the height of the subtrees of the node
            // Will delete the node from the higher subtree

            // Here we will not delete a node but we will change the values of the node
            if (Height(p->lchild) > Height(p->rchild)){
                // q will store the inorder predecesor

                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete_recursive(p->lchild, q->data );




            }
            // Similar for the right subtree but the we will use successor
            else {
                q = InSucc(p->lchild);
                p->data = q->data;
                p->rchild = Delete_recursive(p->rchild, q->data  );

            }
        }
        return p  ;

    }*/

    Node* Delete(Node *p, int key) {
        Node* q;

        if (p == nullptr){
            return nullptr;
        }

        if (p->lchild == nullptr && p->rchild == nullptr){
            if (p == root){
                root = nullptr;
            }
            delete p;
            return nullptr;
        }

        if (key < p->data){
            p->lchild = Delete(p->lchild, key);
        } else if (key > p->data){
            p->rchild = Delete(p->rchild, key);
        } else {
            if (Height(p->lchild) > Height(p->rchild)){
                q = InPre(p->lchild);
                p->data = q->data;
                p->lchild = Delete(p->lchild, q->data);
            } else {
                q = InSucc(p->rchild);
                p->data = q->data;
                p->rchild = Delete(p->rchild, q->data);
            }
        }
        return p;
    }
    /*
    void  creating_bst_from_preorder(int *A  , int size ){
        stack <Node * > st ;
        Node * p , * t ;
        t = new Node ;
        t->data = A[0];
        t->lchild = t->rchild = NULL ;
        p = t ;
        root_2 = t ;
        int i = 1 ;
        while (i<size ){

            if (A[i] < p->data ){
                t = new Node ;
                t ->data = A[i];
                t->lchild = t->lchild = NULL ;
                p->lchild = t;

                p = p->lchild;
                i++ ;
            }
            if (A[i] > p->data){
                if (A[i] > p->data && A[i]< (st.top())->data ) {
                    t = new Node ;
                    t ->data = A[i];
                    t->lchild = t->lchild = NULL ;
                    p->rchild = t ;
                    st.push (p);
                    p=t;
                    i++ ;

                }
                else {
                    p = st.top();
                    st.pop();

                }
            }
        }

    }
     */
    
    // To be checked once again 
    void createFromPreorder(int *pre, int n) {

        // Create root node
        int i = 0;
        root = new Node;
        root->data = pre[i++];
        root->lchild = nullptr;
        root->rchild = nullptr;

        // Iterative steps
        Node* t;
        Node* p = root;
        stack<Node*> stk;

        while (i < n){
            // Left child case
            if (pre[i] < p->data){
                t = new Node;
                t->data = pre[i++];
                t->lchild = nullptr;
                t->rchild = nullptr;
                p->lchild = t;
                stk.push(p);
                p = t;
            } else {
                // Right child cases
                if (pre[i] > p->data && pre[i] < stk.empty() ? 32767 : stk.top()->data){
                    t = new Node;
                    t->data = pre[i++];
                    t->lchild = nullptr;
                    t->rchild = nullptr;
                    p->rchild = t;
                    p = t;
                } else {
                    p = stk.top();
                    stk.pop();
                }
            }
        }
    }


};

Tree::Tree() {
    root = nullptr;
}




void Tree::CreateTree() {
    Node* p;
    Node* t;
    int x;
    queue<Node*> q;

    root = new Node;
    cout << "Enter root data: " << flush;
    cin >> x;
    root->data = x;
    root->lchild = nullptr;
    root->rchild = nullptr;
    q.emplace(root);

    while (! q.empty()){
        p = q.front();
        q.pop();

        cout << "Enter left child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->lchild = t;
            q.emplace(t);
        }

        cout << "Enter right child data of " << p->data << ": " << flush;
        cin >> x;
        if (x != -1){
            t = new Node;
            t->data = x;
            t->lchild = nullptr;
            t->rchild = nullptr;
            p->rchild = t;
            q.emplace(t);
        }
    }
}

void Tree::Preorder(Node *p) {
    if (p){
        cout << p->data << ", " << flush;
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}

void Tree::Inorder(Node *p) {
    if (p){
        Inorder(p->lchild);
        cout << p->data << ", " << flush;
        Inorder(p->rchild);
    }
}

void Tree::Postorder(Node *p) {
    if (p){
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << ", " << flush;
    }
}

void Tree::Levelorder(Node *p) {
    queue<Node*> q;
    cout << p->data << ", " << flush;
    q.emplace(p);

    while (! q.empty()){
        p = q.front();
        q.pop();

        if (p->lchild){
            cout << p->lchild->data << ", " << flush;
            q.emplace(p->lchild);
        }

        if (p->rchild){
            cout << p->rchild->data << ", " << flush;
            q.emplace(p->rchild);
        }
    }
}


int searchInorder(int inArray[], int inStart, int inEnd, int data){
    for (int i=inStart; i<=inEnd; i++){
        if (inArray[i] == data){
            return i;
        }
    }
    return -1;
}

Node* Tree::generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) {
    static int preIndex = 0;

    if (inStart > inEnd){
        return nullptr;
    }

    Node* node = new Node(preorder[preIndex++]);

    if (inStart == inEnd){
        return node;
    }

    int splitIndex = searchInorder(inorder, inStart, inEnd, node->data);
    node->lchild = generateFromTraversal(inorder, preorder, inStart, splitIndex-1);
    node->rchild = generateFromTraversal(inorder, preorder, splitIndex+1, inEnd);

    return node;
}



int main() {

    Tree bt;

    int preorder[] = {40 , 30 , 20 , 35 , 50 , 45 , 60 , 70 };
    int inorder[] = {20 , 30 , 35 , 40 , 45 , 50 , 60 , 70 };

    int size = sizeof(inorder)/sizeof(inorder[0]);

    Node* T = bt.generateFromTraversal(inorder, preorder, 0, size-1);



    bt.createFromPreorder(preorder , size );
    cout<<"The preorder of the tree is "<< endl ;
    bt.Inorder(root);











    return 0;
}
