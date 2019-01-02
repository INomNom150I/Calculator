#include <iostream>
using namespace std;

int bst(int n){
    int dp[100];
    for(int i = 0; i < 100; i++){
        dp[i] = 0;
    }
    dp[0] = 1;
    dp[1] = 1;

    for(int i = 2; i <= n; i++){
        for(int j = 0; j < i; j++){
            dp[i] += dp[j] * dp[i-j-1];
        }
    }
    return dp[n];
}

int main(){
    for(int i = 0; i < 30; i++){
        cout << i << ": " << bst(i) << endl;
    }
    return 0;
}
