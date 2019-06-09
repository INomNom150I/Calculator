#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<int> v[100];
int N;
bool used[101];


void print(){
    for(int i = 0; i < N; i++){
        for(auto j: v[i]){
            cout << j << ' ';
        }
        cout << endl;
    }
}

int dfs(int p){
    if(p == N){
        return 1;
    }
    int ways = 0;
    for(auto i: v[p]){
        if(!used[i]){
            used[i] = true;
            ways += dfs(p+1);
            used[i] = false;
        }
    }
    return ways;
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
    cout << dfs(0) << endl;;
    return 0;
}
