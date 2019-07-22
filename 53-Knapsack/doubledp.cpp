#include <iostream>
using namespace std;
const int N=3, W1=10, W2=3;
int arr[] = { 8, 2, 3 }; 
int n;
int dp[N+1][W1+1][W2+1];

int maxWeight(int w1, int w2){
    memset(dp,0,sizeof(dp));

    for(int i = 1; i <= n; i++){
       for(int j = 0; j <= w1; j++){
            for(int k = 0; k <= w2; k++){
                dp[i][j][k] = dp[i-1][j][k];
                if(arr[i-1] <= j){
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j-arr[i-1]][k]+arr[i-1]);
                }
                if(arr[i-1] <= k){
                    dp[i][j][k] = max(dp[i][j][k],dp[i-1][j][k-arr[i-1]]+arr[i-1]);
                }
                cout << i << " " << j << ' ' << k << ' ' <<  arr[i-1] << ' ' << dp[i][j][k] <<  endl;
            } 
        } 
    }   
    return dp[n][w1][w2];
}

int main() 
{ 
  
    n = sizeof(arr) / sizeof(arr[0]); 
    int w1 = W1, w2 = W2; 

  
    cout << maxWeight(w1,w2) << endl; 
    return 0; 
} 
