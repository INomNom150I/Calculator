#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[100];
int N;
int dp[1<<10][101];


void print(){
    for(int i = 0; i < N; i++){
        for(auto j: v[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
}

void print1(){
    for(int i = 0; i < 101; i++){
        for(int j = 0; j < (1<<N); j++){
            cout << dp[j][i] << ' ';
        }
        cout << endl;
    }
}

int ways(){
    for(int i = 0; i < N; i++){
        for(auto j: v[i]){
            dp[1<<i][j] = 1;
        }
    } 

    for(int i = 0; i < 1<<N; i++){
        for(int p = 0; p < N; p++){
            if(i & 1<<p){
                int y = i ^ 1<<p;
                for(auto k: v[p]){
                    for(int j = 0; j < 101; j++){
                        if(j != k){
                            dp[i][k] += dp[y][j];
                        }
                    }
                }
            }
        }
    }
    print1();
    int res = 0;
    for(int i = 0; i < 101; i++){
        res += dp[(1<<N)-1][i];
    }
    return res;
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

    print();
    cout << ways() << endl;;
    return 0;
}
