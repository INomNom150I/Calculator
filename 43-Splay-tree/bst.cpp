#include <iostream>
#include <vector>
#include <queue>
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

class BST{
public:
    BST() {root = nullptr; count = 0;}
    ~BST() {destroy(root);}
    BST &insert(int key);
    BST &remove(int key);
    node *find(int key);
    node *findMin(node * n);
    node *findMax(node * n);
    void inOrder();
    void preOrder();
    void postOrder();
    void levelTraversal();
    node *successor(int key);
    node *predecessor(int key);
    void pathSum();
    void printPath();
    bool isSameTree(const BST &);
    bool operator == (const BST &);
    void fc(int key);
    void mirror(BST &);
    void build(vector<int> &);
    void destroy();

    bool isBalanced();
    bool isBST();

    int size();
    int empty();

    struct iterator {
        bool operator == (const iterator &);
        int & operator *();
        int & operator ->();
    };

    iterator begin();
    iterator end();

private:
    node *root;
    int count;
    void fc(node * n, int key, node *&f, node *&c);
    node * build(vector<int> &v, int l, int r);
    void inOrder(node *);
    void preOrder(node *);
    void postOrder(node *);
    void destroy(node *);
    void pathSum(node * n, int sum);
    void printPath(node * n, vector<node *>);

    int maxDepth(node *);
    int minDepth(node *);
    bool isBST(node *, int l, int r);
};


// insert key into the tree
BST & BST::insert(int key)
{
    if(root == nullptr) root = new node(key);
    else{
        node * n = root;
        node * p = root;
        while(n != nullptr){
            p = n;
            if(n->key < key) n = n->right;
            else if(n->key > key)n = n->left;
            else break;
        }   
        if(n == nullptr){ 
            n = new node(key);
            ((p->key > key)? p->left:p->right) = n;
        }
    }
    return *this;
}

// remove the key into the tree if existed
BST & BST::remove(int key)
{
    node * n = root;
    node * p = n; 
    while(n != nullptr){
        if(key == n->key){
            if(n->right && n->left){
                node * a = findMin(n->right);
                int tmp = a->key;
                if(n->right == a){
                    n->right = a->right;
                    delete a;
                } 
                else remove(a->key);
                n->key = tmp;
            }
            else{
                node * a = ((n->left)? n->left:n->right);
                if(n == root)root = a;
                else{
                    ((p->left == n)? p->left:p->right) = a;
                }
                delete n;
            }
            break;
        }
        p = n; 
        if(key < n->key) n = n->left;
        else n = n->right;
    }
    return *this;
}

// find the node with key, or nullptr if not existed
node * BST::find(int key)
{
    node *n = root;

    return n;
}

node * BST::findMin(node * n)
{
    while(n != nullptr && n->left != nullptr){
        n = n->left;
    }
    return n;
}

node * BST::findMax(node * n)
{
    while(n != nullptr && n->right != nullptr){
        n = n->right;
    }
    return n;
}

void BST::inOrder()
{
    inOrder(root);
    std::cout << endl;
}

void BST::preOrder()
{
    preOrder(root);
}

void BST::postOrder()
{
    postOrder(root);
}

// print the tree level by level
void BST::levelTraversal()
{
    queue<node *> q;
    queue<node *> q2;
    if(root) q.push(root);
    while(!q.empty()){
        while(!q.empty()){
            node * tmp = q.front();
            q.pop();
            if(tmp == nullptr) continue;
            std::cout << *tmp;
            q2.push(tmp->left);
            q2.push(tmp->right);
        }
        std::cout << endl;
        q.swap(q2);
    }
}

node * BST::successor(int key)
{
    node * n = root;
    node * p = nullptr;
    while(n != nullptr && n->key != key){
        if(n->key > key){
            p = n;
            n = n->left;
        }
        else n = n->right;
    }
    if(n){
        if(n->right) return findMin(n->right);
        else return p;
    }
    return nullptr;
}

node *BST::predecessor(int key)
{
    node * n = root;
    node * p = nullptr;
    while(n != nullptr && n->key != key){
        if(n->key < key){
            p = n;
            n = n->right;
        }
        else n = n->left;
    }
    if(n){
        if(n->right) return findMax(n->left);
        else return p;
    }
    return nullptr;
}

bool BST::isBalanced()
{
    return maxDepth(root)-minDepth(root) <= 1;
}

bool BST::isBST()
{
    return isBST(root,INT_MIN,INT_MAX);
}

void BST::pathSum()
{
    pathSum(root,0);   
}

void BST::pathSum(node * n, int sum){
    if(n == nullptr) return;
    sum += n->key;
    if(!n->left && !n->right){
        std::cout << sum << endl;
        return;
    }
    pathSum(n->left,sum);
    pathSum(n->right,sum);
}

void BST::printPath()
{
    vector<node *> v;
    printPath(root,v);   
}

void BST::printPath(node * n, vector<node *> v){
    if(n == nullptr) return;
    v.push_back(n);
    if(!n->left && !n->right){
        for(int i = 0; i < v.size(); i++){
            std::cout << v[i]->key << ' '; 
        } std::cout  << endl;
    }
    else{
        printPath(n->left,v);
        printPath(n->right,v);
    }
    v.pop_back();
}

int BST::size()
{
    return count;
}

int BST::empty()
{
    return root == nullptr;
}

bool BST::isSameTree(const BST &o)
{
    node * n = root;
    node * m = o.root;
    if((!m && n) ||(m && !n)) return false;   
    queue<node *> q1,q2;
    if(n) q1.push(n); 
    if(m) q2.push(m);

    while(!q1.empty() && !q2.empty()){
        node * t1 = q1.front(); 
        q1.pop();
        node * t2 = q2.front(); 
        q2.pop();
        if(t1->key != t2->key) return false;
        if(t1->right) q1.push(t1->right);
        if(t1->left)  q1.push(t1->left); 
        if(t2->right) q2.push(t2->right);
        if(t2->left)  q2.push(t2->left); 
    }
    return q1.empty() && q2.empty();
}

bool BST::operator == (const BST &o)
{
    return isSameTree(o); 
}

void BST::mirror(BST &o)
{
}

void BST::build(vector<int> &v)
{
    sort(v.begin(),v.end());
    root = build(v,0,v.size()-1);
}

node * BST::build(vector<int> &v, int l, int r){
    if(l > r) return nullptr;
    int mid = (l+r)/2;
    node * n = new node(v[mid]);
    n->left = build(v,l,mid-1);
    n->right = build(v,mid+1,r);
    return n;
}

void BST::destroy()
{
    destroy(root);
    root = nullptr;  
}


void BST::inOrder(node *n)
{
    if(n == nullptr) return;
    inOrder(n->left);
    std::cout << *n;
    inOrder(n->right);
}

void BST::preOrder(node *n)
{
    if(n == nullptr) return;
    std::cout << *n;
    inOrder(n->left);
    inOrder(n->right);
}

void BST::postOrder(node *n)
{
    if(n == nullptr) return;
    inOrder(n->left);
    inOrder(n->right);
    std::cout << *n;
}

void BST::destroy(node *n)
{
    if(!n) return;
    destroy(n->left);
    destroy(n->right);
    delete n;   
}

int BST::maxDepth(node *n)
{
    if(n == nullptr) return 0;
    return 1+max(maxDepth(n->right),maxDepth(n->left));    
}

int BST::minDepth(node * n)
{
    if(n == nullptr) return 0;
    return 1+min(minDepth(n->right),minDepth(n->left));    
}

bool BST::isBST(node *n, int l, int r)
{
    if(n == nullptr) return true;
    if(n->key < l || n->key > r) return false;
    return isBST(n->left,l,n->key) && isBST(n->right,n->key,r);
}

void BST::fc(int key){
    node * f = nullptr;
    node * c = nullptr;
    fc(root,key,f,c);
    if(f) std::cout << "Floor:" << *f << endl;
    if(c) std::cout <<"Ceiling:" << *c << endl;
}

void BST::fc(node * n, int key, node *&f, node *&c){
    if(n == nullptr) return;
    if(n->key == key){
        f = c = n;
    }
    else if(key < n->key){
        c = n;
        fc(n->left,key,f,c);
    }
    else{
        f = n;
        fc(n->right,key,f,c);
    }
}
    

/* https://www.geeksforgeeks.org/binary-search-tree-set-1-search-and-insertion/ */
int main() 
{ 
    BST tree;
    vector<int> v = {20,30,50,60,70,80};
    //tree.insert(50).insert(30).insert(20).insert(40).insert(70).insert(60).insert(80); 
    tree.build(v);
    tree.fc(65);
    tree.fc(19);
    tree.pathSum();
    tree.printPath();
    tree.levelTraversal();
    tree.inOrder(); 
    cout << *tree.successor(70) << endl;
    cout << *tree.successor(40) << endl;
    cout << *tree.predecessor(70) << endl;
    tree.remove(50).remove(30); 
    tree.inOrder(); 
   
    return 0; 
} 

