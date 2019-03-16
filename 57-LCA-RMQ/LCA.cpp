#include <iostream>
#include <vector>
using namespace std;
int ar[100];

struct node{
    node * left, *right;
    int key;
    node(int key): key(key)
    { left = right = nullptr; }
};
node * root;
int N = 15;

void print(node * cur, int level){
    if(cur == nullptr) return;
    print(cur->left,level+1);
    for(int i = 0; i < level; i++){
        cout << "   ";
    }
    cout << cur->key << endl;
    print(cur->right,level+1);
}

node * build(int s, int e){
    if(s == e){
        return new node(ar[s]);
    }
    int mid = (s+e)/2;
    node * n = new node(ar[mid]);
    n->left = build(s,mid);
    n->right = build(mid+1,e);
    return n;
}

node * LCA(int a, int b){
    node * n = root;
    while(n){
        if(a < n->key && b < n->key){
            n = n->left;
        } else if(a > n->key && b > n->key){
            n = n->right;
        } else{
            return n;
        }
    }
    return n;
}
bool findpath(vector<node *> &p, int v,node * cur){
    if(!cur) return false;
    p.push_back(cur);
    if(cur->key == v) return true;
    if(findpath(p,v,cur->left)) return true;
    if(findpath(p,v,cur->right)) return true;
    p.pop_back();
    return false;
}

node * LCA1(int a, int b){
    vector<node *> pa,pb;
    findpath(pa,a,root);   
    findpath(pb,b,root);   
    
    int r = min(pa.size(),pb.size());
    int i = 0;
    for(; i < r; i++){
        if(pa[i] != pb[i]) return pb[i-1];
    }
    return nullptr;
}

node * LCA2(node * cur,int a, int b){
    if(!cur) return cur;
    if(cur->key == a || cur->key == b) return cur;
    node * l = LCA2(cur->left,a,b);
    node * r = LCA2(cur->right,a,b);
    if(l && r) return cur;
    return (l)?l:r;   
}

int main(){
    for(int i = 0; i < N; i++){
        ar[i] = i+1;
    }
    root = build(0,N-1);
    
    print(root,0);
    cout << "LCA is " << LCA(3,7)->key << endl;
    cout << "LCA is " << LCA1(3,7)->key << endl;
    cout << "LCA is " << LCA2(root,3,7)->key << endl;
    //cout << LCA(2,6)->key << endl;
}

