#include <iostream>
using namespace std;

int val[] = {10, 30, 20}; 
int wt[] = {5, 10, 15}; 
int dp[101][101];

int unbound(int w, int size){
    for(int i = 1; i <= w; i++){
        for(int j = 0; j < size; j++){
            if(wt[j] > i){
                dp[i][j] = dp[i-1][size];
            } else{
                dp[i][j] = max(dp[i-1][size],val[j] + dp[i-wt[j]][size]);
            }
        }
        for(int j = 0; j < size; j++){
            dp[i][size] = max(dp[i][size],dp[i][j]);
        }
    } 
    return dp[w][size];
}

int main() 
{ 
    int W = 100; 
    int n = sizeof(val)/sizeof(val[0]); 
    cout << unbound(W, n) << endl; 
  
    return 0; 
} 
