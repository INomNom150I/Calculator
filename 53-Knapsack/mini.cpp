#include <iostream>
using namespace std;
int arr[] = {3, 1, 4, 2, 2, 1}; 
bool dp[100][100];

int findMin(int n){
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
    int s = sum/2;

    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        dp[i][0] = true;
        for(int j = 1; j <= s; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= arr[i]){
                dp[i][j] |= dp[i-1][j-arr[i-1]];
            }
        }
    }

    for(int i = s; i >= 0; i--){
        if(dp[n][i]){
            return sum-2*i;
        }
    }
    return 0;
}

int main(){
    int n = sizeof(arr)/sizeof(arr[0]); 
    cout << findMin(n) << endl;  
    return 0; 
}
