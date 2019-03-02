#include <iostream>
using namespace std;

struct node{
    node *l,*r;
    int sum;
    node(int sum = 0): sum(sum){
        l = r = nullptr;
    }
};

node * root[100];
node all[1000];
int ver = 0;
int ar[5] = {1,2,3,4,5};
int N;

node * get(){
    static int i = 0;
    //return &all[i++];
    return all+i++;
}

void upgrade(node * prev, node * cur, int s, int e, int i, int val){
    if(s==e){
        cur->sum = val;
        return;
    }
    int mid = (s+e)/2;
    if(i <= mid){
        cur->l = get();
        cur->r = prev->r;
        upgrade(prev->l,cur->l,s,mid,i,val);
    } else{
        cur->l = prev->l;
        cur->r = get();
        upgrade(prev->r,cur->r,mid+1,e,i,val);
    }
    cur->sum = cur->l->sum + cur->r->sum;
}

void upgrade(int i, int val){
    node * cur = get();
    root[ver] = cur;
    upgrade(root[ver-1],cur,0,N-1,i,val);
    ver++;
}

int query(node * cur, int s, int e, int qs, int qe){
    if(s > e || s > qe || e < qs) return 0;
    if(s >= qs && e <= qe){
        return cur->sum;
    } 
    int mid = (s+e)/2;
    return query(cur->l,s,mid,qs,qe) + query(cur->r,mid+1,e,qs,qe);
}

int query(int v, int qs, int qe){
    return query(root[v],0,N-1,qs,qe);
}

void build(node * cur,int s, int e){
    if(s == e){
        cur->sum = ar[s];
        return;
    }
    int mid = (s+e)/2;
    cur->l = get();
    cur->r = get();
    build(cur->l,s,mid);
    build(cur->r,mid+1,e);
    cur->sum = cur->l->sum + cur->r->sum;
}

void build(){
    node * cur = get();
    root[ver] = cur;
    build(cur,0,N-1);
    ver++;
}

int main(){
    N = sizeof(ar)/sizeof(int);
    build();
    upgrade(4,1); 
    upgrade(2,10);   
    cout << query(1,0,4) << endl;
    cout << query(2,3,4) << endl;
    cout << query(0,0,3) << endl;
}
