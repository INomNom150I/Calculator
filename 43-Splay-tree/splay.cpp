#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct node {
    int key;
    node *left, *right;
    node(int key=0):key(key) {
        left = right = nullptr;
    }
};

ostream& operator << (ostream &os, const node &n)
{
    os << n.key << ' ';
    return os;
}


class spTree{
public:
    spTree() {root = nullptr;}
    void insert(int key){
        root = insert(root,key);
        root = splay(root,key);
    }
    void remove(int key){
        if(!root) return;
        root = splay(root,key);
        if(root->key != key) return;
        node * n =  root;
        if(root->left && root->right){
            root = splay(n->left,key); 
            root->right = n->right;
        }
        else{
            root = (root->right)?root->right:root->left;
        }
        delete n;
    }

    void inOrder(){
        inOrder(root);
        std::cout << endl;
    }
    void levelTraversal(){
        levelTraversal(root);
        std::cout << endl;
    }
    node * search(int key){
        root = splay(root,key);
        return root;
    }   
private:
    node *root;
    node *leftRotate(node *);
    node *rightRotate(node *);
    node *splay(node *, int);
    node *insert(node *n, int key);
    node *remove(node *n, int key);
    void inOrder(node * n);
    void levelTraversal(node * n);
};


node* spTree::insert(node * n, int key)
{
    if(!n) return new node(key);
    if(n->key > key) n->left = insert(n->left,key);    
    else if(n->key < key) n->right = insert(n->right,key);
    return n;
}

node * spTree::leftRotate(node *x)
{
    node *y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

node * spTree::rightRotate(node *x)
{
    node *y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

node *spTree::splay(node *n, int key)
{
    if(!n || n->key == key) return n;
    if(n->key > key){
        n->left = splay(n->left,key);   
        if(n->left) n = rightRotate(n);    
    }
    else{
        n->right = splay(n->right,key);
        if(n->right) n = leftRotate(n);
    }
    return n;
}

void spTree::inOrder(node * n)
{
    if(!n) return;
    inOrder(n->left);
    std::cout << *n;
    inOrder(n->right);
    
}

void spTree::levelTraversal(node * n)
{
    queue<node *> q,q1;
    q.push(n);
    while(!q.empty()){
        while(!q.empty()){
            node * a =  q.front();
            q.pop();
            if(a->left) q1.push(a->left);
            if(a->right) q1.push(a->right);
            std::cout << *a;
        }
        q.swap(q1);
        std::cout << endl;
    }
}

int main() 
{ 
    spTree tree;

    for (int i = 1; i<8; ++i) {
        tree.insert(i);
    }

    tree.levelTraversal();
    tree.remove(4);
    tree.levelTraversal();
    tree.search(6);  
    tree.levelTraversal();
    tree.search(100);  
    tree.levelTraversal();
    tree.search(-1);  
    tree.levelTraversal();
    return 0; 
} 

