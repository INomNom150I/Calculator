#include <iostream>
using namespace std;
int const K = 2;
struct node{
    int p[K];
    node * l, *r;
    node(int p[]){
        for(int i = 0; i < K; i++){
            this->p[i] = p[i];
        }   
        l = r = nullptr;
    }
};

node * insert(node * root, int p[], int dep = 0){
    if(root == nullptr){
        return new node(p);
    }
    int cd = dep%K;
    if(p[cd] < root->p[cd]){
        root->l = insert(root->l,p,dep+1);
    } else{
        root->r = insert(root->r,p,dep+1);
    }
    return root;
}

bool isequal(int p1[], int p2[]){
    for(int i = 0; i < K; i++){
        if(p1[i] != p2[i]) return false;
    }
    return true;
}

bool search(node * root, int p[], int dep = 0){
    if(root == nullptr) return false;
    if(isequal(p,root->p)) return true;
    int cd = dep%K;
    if(p[cd] < root->p[cd])
        return search(root->l,p,dep+1);
    else
        return search(root->r,p,dep+1);
}

int main(){
    int p[][K] = {{3, 6}, {17, 15}, {13, 15}, {6, 12}, 
                       {9, 1}, {2, 7}, {10, 19}}; 
    node * root = nullptr;
    for(int i = 0; i < sizeof(p)/sizeof(p[0]); i++){
        root = insert(root,p[i]);
    }
    int ar[K] = {6,9};
    std::cout << search(root,ar) << endl;  
}
