#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int ar[20];
int N;
bool visited[20];
int ans,small,sum,ss[2];
int pre = 0;

void psum(){
    int i = N-1;
    for(; i >= 5; i-=3){
        if(i < 2) break;
        if(ar[i] != ar[i-1] || ar[i] != ar[i-2]) break;
        pre+= ar[i];
    }
    N = i+1;
}

inline int find(int i){
    while(i < N){
        if(!visited[i]) return i;
        i++;
    }
    return i;
}

void sub(int i,int sm, int sn){
    int j = find(i);
//    cout << sn << " j is " << j << endl;
    if(j == N || sm+ar[j] > ans){
        if(sm < small) return;
        ss[sn] = sm;
        if(sn == 1){
            int s3 = sum-ss[0]-ss[1];
            int tmp = s3;
            s3 = max(s3,max(ss[0],ss[1]));
            if(s3 < ans){
                ans = s3;
                tmp = min(tmp,min(ss[0],ss[1])); 
                if(small < tmp) small = tmp;
            } 
        } else{
            sub(0,0,sn+1);         
        }
        return;
    } 
    visited[j] = true;
    sub(j+1,sm+ar[j],sn);
    visited[j] = false;

    sub(j+1,sm,sn);
}

int main(){
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> ar[i];
        sum += ar[i];
    }    
    sort(ar,ar+N);
    psum();
    sum -= pre*3;
    ans = sum-ar[N-1]-ar[N-2];
    small = min(ans,min(ar[N-1],ar[N-2]));
    ans = max(ans,max(ar[N-1],ar[N-2]));
    //ans = 489;
    //small = 480;
    sub(0,0,0);
    cout << (ans+pre) << endl;
}
