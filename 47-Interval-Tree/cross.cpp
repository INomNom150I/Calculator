#include <iostream>
#include <fstream>
using namespace std;

struct node{
    int s, e, mine,maxe;
    node *l, *r;
    node(int s, int e):s(s),e(e) {
        l = r = nullptr;
        mine = e;
        maxe = e;
    }
};

node * insert(node *root,int s, int e){
    if(root == nullptr) return new node(s,e);
    if(s < root->s)
        root->l = insert(root->l,s,e);
    else
        root->r = insert(root->r,s,e);
    if(root->l){
        root->maxe = max(root->maxe,root->l->maxe);
        root->mine = min(root->mine,root->l->mine);
    }
    if(root->r){
        root->maxe = max(root->maxe,root->r->maxe);
        root->mine = min(root->mine,root->r->mine);
    }
    return root; 
}

bool safe(node * root, int s, int e){
    if(root == nullptr) return true;
    if((s > root->s && e < root->e ) || (s < root->s && e > root->e ))
        return false;

    if(s < root->s){
        if(root->r && e > root->r->mine) return false;
        return safe(root->l,s,e);
    }
    else{
        if(root->l && e < root->l->maxe) return false;
        return safe(root->r,s,e);
    }
}

void print(node * root){
    if(root == nullptr) return;
    print(root->l);
    std::cout << root->s << '\t' << root->e << endl;
    print(root->r);
}

int main(){
    std::ifstream in("crossings.in");
    std::ofstream out("crossings.out");

    int N; 
    in >> N;
    int ar[N][2];
    node * root = nullptr;
    int count = 0;
    for(int i = 0; i < N; i++){
        in >> ar[i][0] >> ar[i][1];
        root = insert(root,ar[i][0],ar[i][1]);
    }
    
    print(root);
    for(int i = 0; i < N; i++){
        if(safe(root,ar[i][0],ar[i][1])){
           std::cout << ar[i][0] << '\t' << ar[i][1] << endl;
           count++; 
        }
    }
    out << count << endl;
}

