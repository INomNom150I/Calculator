#include <iostream>
using namespace std;
int dp[10][10];

void print(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

int matrix(int ar[], int n){
    memset(dp,0x7F,sizeof(dp));

    for(int i = 1; i < n; i++){
        dp[i][i] = 0;
    }

    for(int l = 1; l < n-1; l++){
        for(int i = 1, j = i+l; j < n; i++,j++){
            for(int k = i; k < j; k++){
                dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+ar[i-1]*ar[k]*ar[j]);    
            }
        }
    }
    return dp[1][n-1];
} 

int main() 
{ 
    int arr[] = {1, 2, 3, 4, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
  
    cout << "Minimum number of multiplications is "
         << matrix(arr, n) << endl; 
    print(n);
} 
