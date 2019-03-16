#include <iostream>
using namespace std;

const int K = 2;
struct point{
    int a[K];
};

int N = 4;
int seg[16][16];
int ar[4][4] = { 
    { 1, 2, 3, 4 }, 
    { 5, 6, 7, 8 }, 
    { 1, 7, 5, 9 }, 
    { 3, 0, 6, 2 }, 
}; 

void print(){
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << seg[i][j] << ' ';
        }
        cout << endl;
    }
}

void buildx(int sx, int ex, int ix,int sy, int ey, int iy){
    if(sx == ex){
        if(sy == ey){
            seg[ix][iy] = ar[sx][sy];
        } else{
            seg[ix][iy] = seg[ix][iy*2+1]+seg[ix][iy*2+2];
        }
    //cout << sx << ' ' << ex << ' ' << ix << ' ' <<sy << ' ' << ey << ' '<< iy<<' ' << seg[ix][iy] << endl;
        return;
    }
    int mid = (sx+ex)/2;
    buildx(sx,mid,ix*2+1,sy,ey,iy);
    buildx(mid+1,ex,ix*2+2,sy,ey,iy);
    seg[ix][iy] = seg[ix*2+1][iy] + seg[ix*2+2][iy];
    //cout << sx << ' ' << ex << ' ' << ix << ' ' <<sy << ' ' << ey << ' '<< iy<<' ' << seg[ix][iy] << endl;
}

void buildy(int sy,int ey,int iy){
    //cout << '\t' << sy << ' ' << ey << ' ' << iy << endl;
    if(sy != ey){
        int mid = (sy+ey)/2;
        buildy(sy,mid,iy*2+1);
        buildy(mid+1,ey,iy*2+2);
    }
    buildx(0,N-1,0,sy,ey,iy);
}

void build(){
    buildy(0,N-1,0);
}
int queryx(int sx, int ex,int ix,int iy,int lx, int rx){
    if(sx > ex || sx > rx || ex < lx) return 0;
    if(sx >= lx && ex <= rx){
        return seg[ix][iy];
    }
    int mid = (sx+ex)/2;
    return queryx(sx,mid,2*ix+1,iy,lx,rx) + queryx(mid+1,ex,2*ix+2,iy,lx,rx);
}

int query(int sy, int ey, int iy, int lx, int ly, int rx, int ry){
    if(sy > ey || sy > ry || ey < ly) return 0;
    if(sy >= ly && ey <= ry) return queryx(0,N-1,0,iy,lx,rx);
    int mid = (sy+ey)/2;
    return query(sy,mid,iy*2+1,lx,ly,rx,ry) + query(mid+1,ey,iy*2+2,lx,ly,rx,ry);
}

int query(int lx, int ly, int rx, int ry){
    return query(0,N-1,0,lx,ly,rx,ry);
}

#if 0
void update(int s, int e, int i, int k, int d){
    if(s <= k && e >= k){
        seg[i] += d;
        if(s == e) return;
        int mid = (s+e)/2;
        update(s,mid,2*i+1,k,d);
        update(mid+1,e,2*i+2,k,d);
    }
    seg[i] += d;
    if(s == e) return;
    int mid = (s+e)/2;
    if(k > mid){
        update(mid+1,e,2*i+2,k,d);
    } else{
        update(s,mid,2*i+1,k,d);
    }
}

void update(int k, int d){
    update(0,N-1,0,k,d);
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
#endif

int main(){
    build();
    print();
    cout << "1,1 - 2,2 \t" << query(1,1,2,2) << endl;
    return 0;
}
