#include <iostream>
#define INF 0x3F3F3F3F
using namespace std;

int tbl[4][9];

void build(int ar[],int len){
    for(int j = 0; j < len; j++){
        tbl[0][j] = ar[j];
    }

    for(int i = 1; (1<<i) < len; i++){
        for(int j = 0; j+(1<<i) <= len;j++){
            tbl[i][j] = min(tbl[i-1][j],tbl[i-1][j+(1<<(i-1))]);
        }
    }
}

int row(int l){
    if(l&(l-1) == 0) l >>= 1;
    while(l&(l-1)){
        l = l&(l-1);
    }
    l >>= 1;
    int i = 0;
    while(l){
        l >>= 1;
        i++;
    }
    return i;
}

int query(int l, int r){
    int i = row(r-l+1);
    return min(tbl[i][l],tbl[i][r-(1<<i)+1]);
}

void query1(int l, int r){
    cout << query(l,r) << endl;
}

int main(){
    int a[] = {7, 2, 3, 0, 5, 10, 3, 12, 18}; 
    int n = sizeof(a)/sizeof(a[0]); 
    build(a,n);
    query1(0,4);
    query1(4,7);
    query1(7,8);
    return 0;
}
