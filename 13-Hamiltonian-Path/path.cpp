#include <iostream>
using namespace std;

const int N = 5;
int dp[N+1][N+1];

int way(){
    dp[1][0] = 1;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }
    return dp[N][N];
}

void print(){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            cout.width(3);
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    cout << way() << endl;
    print();
}
