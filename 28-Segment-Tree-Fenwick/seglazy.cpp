#include <iostream>
using namespace std;

int N;
int seg[100],lazy[100],ms;
int ar[] = {1, 3, 5, 7, 9, 11};

int build(int s, int e, int i){
    if(s == e){
        seg[i] = ar[s];
        return seg[i];
    }
    int mid = (s+e)/2;
    seg[i] = build(s,mid,2*i+1) + build(mid+1,e,2*i+2);
    return seg[i];
}

void build(){
    build(0,N-1,0);
}

int query(int s, int e,int i,int l, int r){
    if(e < l || s > r) return 0;
    if(lazy[i] > 0){
        seg[i] += (e-s+1) * lazy[i];
        if(s != e){
            lazy[2*i+1] += lazy[i];
            lazy[2*i+2] += lazy[i];
        }
        lazy[i] = 0;
    }
    if(s >= l && e <= r){
        return seg[i];
    }
    int mid = (s+e)/2;
    return query(s,mid,2*i+1,l,r) + query(mid+1,e,2*i+2,l,r);
}

int query(int l, int r){
    return query(0,N-1,0,l,r);
}

void update(int s, int e, int i, int l, int r, int d){
//    cout << s << ' ' <<e << endl;
    cout << s << ' ' << e << ' ' << i << endl;
    if(e < l || s > r || e < s) return;
    if(lazy[i] > 0){
        seg[i] += (e-s+1) * lazy[i];
        if(s != e){
            lazy[2*i + 1] += lazy[i]; 
            lazy[2*i + 2] += lazy[i]; 
        }
        lazy[i] = 0;
    }
    if(s >= l && e <= r){
        seg[i] += (e-s+1) * d;
        if(s != e){
            lazy[2*i+1] += d;
            lazy[2*i+2] += d;
        }
        return;
    }
    int mid = (s+e)/2;
    update(s,mid,2*i+1,l,r,d);
    update(mid+1,e,2*i+2,l,r,d);
    seg[i] = seg[2*i+1] + seg[2*i + 2];
}

void update(int l, int r, int d){
    update(0,N-1,0,l,r,d);
}

void print(){
    for(int i = 0; i < ms; i++){
        cout << seg[i] << ' ';
    }
    cout << endl;
}

void init(){
    ms = N;
    bool p = true;
    while(ms & (ms-1)){
        ms = ms & (ms-1);
        p = false;
    }
    ms<<=1;
    if(!p) ms <<= 1;
    ms--;
}

int main(){
    N = sizeof(ar)/sizeof(ar[0]);   
    init();
    build();
    print();
    std::cout << query(1,3) << std::endl;
    update(0,3,10);
    print();
    std::cout << query(1,3) << std::endl;     
    return 0;
}
