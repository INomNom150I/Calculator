#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[100];
int N;
vector<int> cap[101];
int dp[1<<10][101];


void print(){
    for(int i = 0; i < N; i++){
        for(auto j: v[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
    for(int i = 0; i < 101; i++){
        if(cap[i].size() > 0){
            cout << i << ' ';
            for(auto j: cap[i]){
                cout << j << ' ';
            }
            cout << endl;
        }
    }
}

int dfs(int mask,int c){
    if(dp[mask][c] >= 0) return dp[mask][c];

    if(mask == ((1<<N) - 1)){
        return 1;
    }
    if(c > 100){
        return 0;
    }
    dp[mask][c] = dfs(mask,c+1);
    for(auto i: cap[c]){
        if(!(mask & (1<<i))){
            dp[mask][c] += dfs(mask|(1<<i),c+1);
        }
    }
    return dp[mask][c];
}

int main(){
    cin >> N;
    
    
    for(int i = 0; i < N; i++){
        int c;
        cin >> c;
        for(int j = 0; j < c; j++){
            int a;
            cin >> a;
            v[i].push_back(a);
        }
    }

    for(int i = 0; i < N; i++){
        for(auto j: v[i]){
            cap[j].push_back(i);
        }
    }
    print();
    memset(dp,-1,sizeof(dp));
    cout << dfs(0,0) << endl;;
    return 0;
}
