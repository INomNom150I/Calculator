#include <iostream>
#define SIZE 50
int dp[SIZE][SIZE];

int f(int ar[], int l, int r){
    return std::max(ar[l] + std::min(dp[l+2][r],dp[l+1][r-1]),
                    ar[r] + std::min(dp[l+1][r-1],dp[l][r-2]));
}

int maxsum(int ar[],int n){
    for(int i = 0; i < n; i++){
        dp[i][i] = ar[i]; 
    }

    for(int i = 0; i < n-1; i++){
        dp[i][i+1] = std::max(ar[i],ar[i+1]);
    }

    for(int l = 2; l < n; l++){ 
        for(int i = 0, j = i + l; j < n; i++,j++){
            dp[i][j] = f(ar,i,j);
        }
    }
    return dp[0][n-1];
}

int main(){
    int ar[] = {8,15,3,7};
    std::cout << "max:\t" << maxsum(ar,4) << std::endl;
    int ar1[] = {1,3,19,6,8,2};
    std::cout << "max:\t" << maxsum(ar1,6) << std::endl;
    return 0;
}
