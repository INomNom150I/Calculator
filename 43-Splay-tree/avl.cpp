#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct node {
    int key, height;
    node *left, *right;
    node(int key=0):key(key), height(1) {
        left = right = nullptr;
    }
};

ostream& operator << (ostream &os, const node &n)
{
    os << n.key << '(' << n.height << ") ";
    return os;
}

class avlTree{
public:
    avlTree() {root = nullptr;}
    avlTree &insert(int key){
        root = insert(root,key);
        return *this;
    }
    avlTree &remove(int key){
        root = remove(root,key);
        return *this;
    }
    void inOrder(){
        inOrder(root);
        std::cout << endl;
    }
    void levelTraversal(){
        levelTraversal(root);
        std::cout << endl;
    }

private:
    node *root;
    node *leftRotate(node *);
    node *rightRotate(node *);
    node *balance(node *);
    
    node *insert(node *n, int key);
    node *remove(node *n, int key);
    void inOrder(node * n);
    void levelTraversal(node * n);

    node *findMin(node *n);
    node *findMax(node *n);
    int height(node *n) {
        if(!n) return 0;
        return n->height;
    }

};


node * avlTree::insert(node * n,int key)
{
    if(n == nullptr){
         return new node(key);
    }
    if(n->key < key) n->right = insert(n->right,key);
    else if(n->key > key) n->left = insert(n->left,key);
    return balance(n);
}

node * avlTree::remove(node * n,int key)
{
    if(!n) return n;
    if(n->key< key) n->right = remove(n->right,key);
    else if(n->key > key) n->left = remove(n->left,key);   
    else{
        if(n->right && n->left){
            node * a = findMin(n->right);           
            n->key = a->key;
            n->right = remove(n->right,a->key);
        } else{
            node * tmp = n;
            n = (n->left)?n->left:n->right;
            delete tmp;
            return n;
        }
    }
    return balance(n);
}

node * avlTree::leftRotate(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    x->height = 1 + max(height(x->right),height(x->left));
    y->height = 1 + max(height(y->right),height(y->left));
    return y;
}

node * avlTree::rightRotate(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    x->height = 1 + max(height(x->right),height(x->left));
    y->height = 1 + max(height(y->right),height(y->left));
    return y;
}

node* avlTree::balance(node *n)
{
    int diff = height(n->left) - height(n->right);   
    if(diff > 1){
        node * a = n->left;
        if(height(a->right) > height(a->left)){
            n->left = leftRotate(a);
        } 
        n = rightRotate(n);
    } 
    else if(diff < -1){
        node * a = n->right;
        if(height(a->left) > height(a->right)){
            n->right = rightRotate(a);
        }
        n = leftRotate(n);
    }
    else{
        n->height = 1+max(height(n->left),height(n->right));
    }
    return n;
}

node * avlTree::findMin(node *n)
{
    if(n->left == nullptr) return n;
    return findMin(n->left);
}

node * avlTree::findMax(node *n)
{
    return n;
}

void avlTree::inOrder(node *n)
{
    if(n == nullptr) return;
    inOrder(n->left);
    std::cout << *n;
    inOrder(n->right);
}

void avlTree::levelTraversal(node *n)
{
    queue<node *> q,q1;
    q.push(n);
    while(!q.empty()){
        while(!q.empty()){
            node * a = q.front();
            q.pop();
            std::cout << *a;
            if(a->left) q1.push(a->left);
            if(a->right) q1.push(a->right);
        }
        q.swap(q1);
        std::cout << endl;
    }       
}

int main() 
{ 
    avlTree tree;

    for (int i = 1; i<16; ++i) {
        tree.insert(i);
    }
    tree.remove(1);
    tree.inOrder(); 
    tree.levelTraversal();
   
    return 0; 
} 

