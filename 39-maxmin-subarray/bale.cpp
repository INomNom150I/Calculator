#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int ar[20];
int N;
bool visited[20];
int ans, sum,ss[2];

int find(int i){
    while(i < N){
        if(!visited[i]) return i;
        i++;
    }
    return i;
}

void sub(int i,int sm, int sn){
    int j = find(i);
    //cout << sn << " j is " << j << endl;
    if(j == N){
        ss[sn] = sm;
        if(sn == 1){
            int s3 = sum-ss[0]-ss[1];
            s3 = max(s3,max(ss[0],ss[1]));
            ans = min(s3,ans);
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
    ans = sum;
    sub(0,0,0);
    cout << ans << endl;
}
