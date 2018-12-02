#include <iostream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define RED true
#define BLACK false
//enum Color {RED, BLACK};

struct node
{
    bool color;
    int key;
    node *left, *right, *parent;
    node (const int key=0) : key(key) {
        color = RED;
        left = right = parent = nullptr;
    }

    node * uncle() {
        if(parent == nullptr || parent->parent == nullptr) return nullptr;
        return parent->sibling();
    }

    node *sibling() {
        if(parent == nullptr) return nullptr;
        if(isleft()) return parent->right;
        return parent->left;
    }

    bool isleft(){
        if(parent->left == this) return true;
        return false;
    }
};

static inline bool isBlack(node * n){
    return !n || (n->color == BLACK);
}

ostream& operator << (ostream &os, const node &n)
{
    char color = (n.color==BLACK)?'b':'r';
    os << n.key << '(' << color << ") ";
    return os;
}


class rbTree {
public:
    rbTree(){
        root = nullptr;
    }
    void insert(int key){
        if(!root){
            root = new node(key);
            root->color = BLACK;
            return;
        }
        node* n = find(root,key);
        if(n->key == key) return;
        node * t = new node(key);
        t->parent = n;
        if(n->key < key) n->right = t;
        else n->left = t;
        fix2red(t);
    }

    void remove(int key){
        if(!root) return;
        remove(root,key);
    }
    void remove(node * a,int key){
        node * n =  find(a,key);
        if(n->key != key) return;
        if(n->right && n->left){
            node * t = find(n->left,key);
            n->key = t->key;
            remove(n->left,n->key);
        } else{
            node * t =  (n->left)?n->left:n->right;
            node * s = n->sibling();
            if(n == root){
                root = t;
                if(root) root->color = BLACK;
            }
            else{
                if(n->isleft()) n->parent->left = t;
                else n->parent->right = t;
            }         
            if(t) t->parent = n->parent;
            if(isBlack(n)){
                if(!isBlack(t)) t->color = BLACK;
                else fix2black(t,s);
            }
            delete n;
        }
    }
    node * find(node * n, int key){
        node * p = n;
        while(n){
            if(n->key == key) return n;
            p = n;
            if(n->key > key){
                n = n->left;
            } else{
                n = n->right;
            }
        }
        return p;
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

    void fix2red(node *);
    void fix2black(node *, node * n = nullptr);

    node *findMin(node *);
    void levelTraversal(node * n);
    void inOrder(node * n);
};

node * rbTree::leftRotate(node *x)
{
    node *y = x->right;
    x->right = y->left;       
    y->left = x;
    y->parent = x->parent;
    if(x->right) x->right->parent = x;
    if(!x->parent) root = y;
    else if(x->isleft())  y->parent->left = y;
    else y->parent->right = y;
    x->parent = y;
    return y;
}

node * rbTree::rightRotate(node *x)
{
    node *y = x->left;
    x->left =  y->right;
    y->right = x;
    y->parent = x->parent;
    if(x->left) x->left->parent = x;
    if(!x->parent) root = y;
    else if(x->isleft()) y->parent->left = y;
    else y->parent->right = y;
    x->parent = y;
    return y;
}

void rbTree::fix2red(node * n)
{
    if (n == root) {
        n->color = BLACK;
        return;
    }
    if(isBlack(n->parent)) return;
    node * p = n->parent;
    node * u = n->uncle();
    node * g = n->parent->parent;
    if(!isBlack(u)){
        p->color = BLACK;
        u->color = BLACK;    
        g->color = RED;
        fix2red(g);
    } else{
        if(p->isleft()){
            if(!n->isleft()){
                p = leftRotate(p);
            }
            rightRotate(g);
        } else{
            if(n->isleft()){
                p = rightRotate(p);
            }
            leftRotate(g);
        }
        p->color = BLACK;
        g->color = RED;
    }
}

void rbTree::fix2black(node *n, node * d){
    bool c = BLACK;   
    while(n != root && c == BLACK){
        node * s = (n)?n->sibling():d;
        node * p = (n)?n->parent:s->parent;
        bool left = (n)?n->isleft():!s->isleft();;
        std::cout << s << p <<"time 2\n";
        if(left){
            if(!isBlack(s)){
                s->color = BLACK;
                p->color = RED;
                leftRotate(p);
                s = p->right;
            }  
            std::cout << "time\n";
            if(isBlack(s->left) && isBlack(s->right)){
                s->color = RED;
                n = p;
            }
            else{
                if(!isBlack(s->right)){
                    s->left->color = BLACK;
                    s->color = RED;
                    rightRotate(s);
                    s = p->right;
                }
                s->color = p->color;
                p->color = BLACK;
                if(s->right) s->right->color = BLACK;
                leftRotate(p);
                n = root;
            }
        } else{
            if(!isBlack(s)){
                s->color = BLACK;
                p->color = RED;
                rightRotate(p);
                s = p->left;
            }  
            std::cout << "right\n";
            if(isBlack(s->left) && isBlack(s->right)){
                s->color = RED;
                n = p;
            }
            else{
                if(!isBlack(s->left)){
                    s->right->color = BLACK;
                    s->color = RED;
                    leftRotate(s);
                    s = p->left;
                }
                s->color = p->color;
                p->color = BLACK;
                if (s->left) s->left->color = BLACK;
                rightRotate(p);
                n = root;
            }
            
        }    
        std::cout << n << "done \n";
        c = n->color;
    }
}

node *rbTree::findMin(node *n) {
    while(n->left) n = n->left;
    return n;
}

void rbTree::inOrder(node * n)
{
    if(!n) return;
    inOrder(n->left);
    std::cout << *n;
    inOrder(n->right);    
}

void rbTree::levelTraversal(node * n)
{
    queue<node *> q,q1;
    q.push(n);
    while(!q.empty()){
        while(!q.empty()){
            node * a = q.front();
            q.pop();
            std::cout<< *a;
            if(a->left) q1.push(a->left);
            if(a->right) q1.push(a->right);
        }
        std::cout<< std::endl;
        q.swap(q1);
    }
}


int main()
{
    rbTree tree;
    /*
    while(1){
        int t;
        cin >> t;
        if(t == 0) break;
        tree.insert(t);
    }
    */
   for (int i = 1; i<=16; ++i) {
        tree.insert(i);
    }
    tree.inOrder();
        tree.levelTraversal();
    tree.remove(6);
        tree.levelTraversal();
    tree.remove(10);
        tree.levelTraversal();
    return 0;
}

