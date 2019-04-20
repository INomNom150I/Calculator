#include <iostream>
using namespace std;

int val[] = {10, 30, 20}; 
int wt[] = {5, 10, 15}; 
int dp[1000];

int unbound(int w, int size){
    dp[0] = 0;

    for(int i = 1; i <= w; i++){
        for(int j = 0; j < size; j++){
            if(wt[j] <= i) {
                dp[i] = max(dp[i],dp[i-wt[j]]+val[j]);
            }
        }
    } 
    return dp[w];
}

int main() 
{ 
    int W = 100; 
    int n = sizeof(val)/sizeof(val[0]); 
  
    cout << unbound(W, n) << endl; 
  
    return 0; 
} 
