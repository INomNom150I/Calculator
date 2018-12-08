#include <iostream>
#include <string>
using namespace std;
int dp[100][100];

int dice(int n, int s){
    if(s <= 0) return 0;
    if(n == 1){
        if(s <= 6) return 1;
        else return 0;
    } 
    int total = 0;
    for(int i = 1; i <= 6; i++){
        total += dice(n-1, s-i);
    }
    return total;
}

void dice1(int n){
    int end = n*6;
    for(int i = n; i <= end; i++){
        std::cout << i <<" " << dice(n,i) << std::endl;
    }   
}

void dice(int n){
    long long dp[n+1][6*n+1];
    memset(dp,0,sizeof(dp));
    for(int i = 1; i <= 6; i++){
        dp[1][i] = 1;
    }
    for(int i = 2; i <= n; i++){
        for(int j = i; j <= 6*n; j++){
            for(int k = 1; k <= 6; k++){
                if(j > k) dp[i][j] += dp[i-1][j-k];
            }
        }
    } 
    for(int i = n; i <= 6*n; i++)
        std::cout << i <<" " << dp[n][i] << std::endl;
}

int main(){
    dice(30);
    std::cout << std::endl;
    //dice1(2);
}
