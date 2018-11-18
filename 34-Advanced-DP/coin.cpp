#include <iostream>
#include <string>
using namespace std;

int rcoin(int a){
    if(a == 0) return 0;
    if(a < 0) return INT_MAX;
    return 1+min(rcoin(a-5),min(rcoin(a-2),rcoin(a-1)));
}

int tcoin[3] = {5,2,1};
int dcoin(int a){
    int dp[100];
    dp[0] = 0; 
    for(int i = 1; i <= a; i++){
        dp[i] = INT_MAX;
    }
    for(int i = 0; i < 3; i++){
        for(int j = tcoin[i]; j <= a; j++){
            dp[j] = min(dp[j-tcoin[i]]+1,dp[j]);
        } 
    }
    return dp[a];
}

int greed(int a){
    int count = 0;
    for(int i = 2; i >= 0; i--){
        count += a/tcoin[i];
        a = a%tcoin[i];
    }
    return count;
}

int coin(int a){
    int dp[100];
    dp[0] = 0;
    for(int i = 1; i <= a; i++){
        dp[i] = 10000;
    }
    for(int i = 1; i <= a; i++){
        for(int j = 0; j < 3; j++){
            if(i >= tcoin[j]){
                dp[i] = min(dp[i],dp[i-tcoin[j]]+1);
                //cout << dp[i] << " " << dp[i-tcoin[j]] << endl;
            }
        }
    }  
    return dp[a];
}

int ways(int c[], int m, int n){
    if(n == 0) return 1;
    if(n < 0) return 0; 
    if(m == 0) return 0;
    return ways(c,m,(n-c[m-1])) + ways(c,m-1,n);
}

int ways(int a){
    int dp[100][100];
    for(int i = 0; i <= 3; i++){
        dp[i][0] = 1;
    }
    for(int i = 1; i <= a; i++){
        dp[0][i] = 0;
    }
    int coin[3] = {1,2,5};
    for(int i = 1; i <= 3; i++){
        for(int j = 1; j <= a; j++){
            if(j-coin[i-1] < 0) dp[i][j] = dp[i-1][j]; 
            else dp[i][j] = dp[i][j-coin[i-1]] + dp[i-1][j];
        }  
    }
    for(int i = 0; i < a; i++){
        std::cout << i << " - " << dp[3][i] << endl;
    }
    return dp[3][a];
}

int ways1(int c[], int m, int n){
    if(n < 0) return 0;
    if(n == 0) return 1;
    int cnt = 0;
    for(int i = 0; i < m; i++){
        cnt += ways1(c,i,n-c[i]);
    }   
    return cnt;
}

int dway(int c[], int m, int n){
    int dp1[m][n+1];
    for(int i = 0; i < m; i++){
        dp1[i][0] = 1;
        for(int j = 1; j <= n; j++){
            dp1[i][j] = 0;
        }
    }

    for(int j = 1; j <= n; j++){
        for(int i = 0; i < m; i++){
            for(int k = 0; k <= i; k++){
                if(j >= c[k]) dp1[i][j] += dp1[k][j-c[k]];
            }
        }
    }
    for(int i = 0; i < m; i++){
        for(int j = 0; j <= n; j++){
            std::cout << dp1[i][j] << ' ';
        }
        std::cout << endl;
    }
    return dp1[m-1][n];
}

int main(){
    std::cout << coin(28) << endl;
    std::cout << rcoin(28) << endl;
    std::cout << dcoin(28) << endl;
    std::cout << greed(28) << endl;

    std::cout << ways(12) << endl;
    std::cout << ways(tcoin,3,12) << endl;
    std::cout << dway(tcoin,3,12) << endl;
}
