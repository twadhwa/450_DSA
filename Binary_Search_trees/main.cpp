#include <iostream>
#include <queue>
#include <stack>

using namespace std;

class Node{
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height ;
    int bf ;
    Node() {};
    Node(int data);
};

Node::Node(int data) {
    lchild = nullptr;
    this->data = data;
    rchild = nullptr;
}


class Tree{
private:
    Node * root ;
public:

    Tree() {
        root = nullptr;
    }




    void CreateTree() {
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

    void Preorder(Node *p) {
        if (p){
            cout << p->data << ", " << flush;
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }

    void Inorder(Node *p) {
        if (p){
            Inorder(p->lchild);
            cout << p->data << ", " << flush;
            Inorder(p->rchild);

        }

    }

    void Postorder(Node *p) {
        if (p){
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout << p->data << ", " << flush;
        }
    }

    void Levelorder(Node *p) {
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

    Node* generateFromTraversal(int *inorder, int *preorder, int inStart, int inEnd) {
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

        if (x>y){
            return x +1 ;
        }
        else {
            return y +1 ;
        }

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

    Node * createFromPreorder(int *pre, int n) {

        // Create root node

        Node * root_2 ;
        int i = 0;
        root_2= new Node;
        root_2->data = pre[i++];
        root_2->lchild = nullptr;
        root_2->rchild = nullptr;

        // Iterative steps
        Node* t;
        Node* p = root_2 ;
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
        return root_2 ;
    }
    */
    Node* constructBST(int preorder[], int start, int end)
    {

        if (start > end) {
            return NULL;
        }

        struct Node* node = new Node(preorder[start]);


        int i;
        for (i = start; i <= end; i++)
        {
            if (preorder[i] > node->data) {
                break;
            }
        }


        node->lchild = constructBST(preorder, start + 1, i - 1);
        node->rchild = constructBST(preorder, i, end);

        return node;
    }

    int height (Node *p){
        int h_left , h_right;
        if (p && p->lchild){
            h_left = p->lchild->height ;
        }
        else{
            h_left = 0 ;

        }


        if (p && p->rchild){
            h_right = p ->rchild->height;
        }
        else {
            h_right = p->rchild->height ;
        }

        if (h_left > h_right){
            return h_left + 1  ;
        }
        else {
            return h_right + 1 ;
        }
    }

    int BalanceFactor (Node * p){
        int h_left , h_right;
        if (p && p->lchild){
            h_left = p->lchild->height ;
        }
        else{
            h_left = 0 ;

        }


        if (p && p->rchild){
            h_right = p ->rchild->height;
        }
        else {
            h_right = p->rchild->height ;
        }

        return h_left - h_right ;
    }

    struct Node * LLRotation(struct Node *p)
    {
        int lbf,rbf;
        struct Node *pl=p->lchild;
        pl->bf=0;
        p->lchild=pl->rchild;
        pl->rchild=p;
        lbf=height(p->lchild)+1;
        rbf=height(p->rchild)+1;
        p->bf=lbf-rbf;
        if(p==root)root=pl;
        return pl;
    }
    struct Node *LRRotation(struct Node *p)
    {
        int lbf,rbf;
        struct Node *pl=p->lchild;
        struct Node *plr=pl->rchild;
        plr->bf=0;

        p->lchild=plr->rchild;
        pl->rchild=plr->lchild;
        plr->lchild=pl;
        plr->rchild=p;
        lbf=height(p->lchild)+1;
        rbf=height(p->rchild)+1;
        p->bf=lbf-rbf;

        lbf=height(pl->lchild)+1;
        rbf=height(pl->rchild)+1;
        pl->bf=lbf-rbf;
        if(p==root)root=plr;
        return plr;
    }
    struct Node *RRRotation(struct Node *p)
    {
        int lbf,rbf;
        struct Node *pr=p->rchild;
        pr->bf=0;
        p->rchild=pr->lchild;
        pr->lchild=p;
        lbf=height(p->lchild)+1;
        rbf=height(p->rchild)+1;
        p->bf=lbf-rbf;
        if(p==root)root=pr;
        return pr;
    }
    struct Node *RLRotation(struct Node *p)
    {
        int lbf,rbf;
        struct Node *pr=p->rchild;
        struct Node *prl=pr->lchild;
        prl->bf=0;

        p->rchild=prl->lchild;
        pr->lchild=prl->rchild;
        prl->rchild=pr;
        prl->lchild=p;
        lbf=height(p->lchild)+1;
        rbf=height(p->rchild)+1;
        p->bf=lbf-rbf;

        lbf=height(pr->lchild)+1;
        rbf=height(pr->rchild)+1;
        pr->bf=lbf-rbf;
        if(p==root)root=prl;
        return prl;
    }





    Node *  insertion_recursive_avl (Node *p , int x ){
        Node *t ;
        if (p==NULL){
            t = new Node ;
            t->lchild = t ->rchild = NULL;
            t->height = 0 ;
            t->data = x ;
            return t ;

        }
        root = t ;

        if (p->data > x ){
            p->lchild = insertion_recursive(p->lchild , x );
        }

        else if (p->data < x ){
            p->rchild = insertion_recursive(p->rchild ,x ) ;
        }

        // Till here we have just inserted in the binary search tree
        // From here we will start rotations

        // Declaring height of the tree
        p->height = height(p) ;

        // Checking for the balance factor of the nodes

        if (BalanceFactor(p) == 2 && BalanceFactor (p->lchild) == 1) {
            return LLRotation(p);
        } else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1){
            return LRRotation(p);
        } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == -1){
            return RRRotation(p);
        } else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1){
            return RLRotation(p);
        }

        return root ;
    }





};




int main() {

    Tree bt;

    int preorder[] = {40 , 30 , 20 , 35 , 50 , 45 , 60 , 70 };
    int inorder[] = {20 , 30 , 35 , 40 , 45 , 50 , 60 , 70 };

    int size = sizeof(inorder)/sizeof(inorder[0]);
    Node * root ;





    Node* T = bt.generateFromTraversal(inorder, preorder, 0, size-1);

    root = bt.constructBST(preorder , 0 , size-1);

    Node * root_2 = NULL;
    bt.insertion_recursive_avl(root_2 , 80 );
    cout<< root_2->data ;

    cout<<"The new preorder is "<<endl ;













    bt.Preorder(root_2 );
    bt.Inorder(root_2);
    cout<<endl;
    bt.Postorder(root_2);

    cout<< endl ;


















    return 0;
}
