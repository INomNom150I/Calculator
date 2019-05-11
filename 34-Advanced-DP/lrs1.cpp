#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[100][100];

void print(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= n; j++){
            cout << dp[i][j] << ' ';
        }
        cout << endl;
    }
}

int lrs(const string& a){
    int n = a.size();

    for(int i = 0; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else{
                if(a[i-1] == a[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                } else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
    }
    print(n);
    return dp[n-1][n];
}

int main(){
    cout << lrs("AABEBCDD") << endl;
    return 0;
}
