#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

struct node{
    int s, e, mine,maxe;
    node *l, *r;
    bool operator<(const node &o) const{
        return s < o.s;
    }
};

node * build(node ar[],int i, int j){
    if(i > j) return nullptr;
    int mid = (i+j)/2;

    node * root = &ar[mid];
    root->l = build(ar,i,mid-1);
    root->r = build(ar,mid+1,j);    

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
    node ar[N];
    node * root = nullptr;
    int count = 0;
    for(int i = 0; i < N; i++){
        in >> ar[i].s >> ar[i].e;
        ar[i].mine = ar[i].e;
        ar[i].maxe = ar[i].e;
    }
    sort(ar,ar+N);
    root = build(ar,0,N-1);
//    print(root);
    for(int i = 0; i < N; i++){
        if(safe(root,ar[i].s,ar[i].e)){
           count++; 
        }
    }
    out << count << endl;
}

