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
    int n = a.size(),l = 0;
    
    for(int i = 0; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            if(i > 0 && j > 0 && a[i-1] == a[j-1] && j-i > dp[i-1][j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                l = max(l,dp[i][j]);
            } else{
                dp[i][j] = 0;
            }
        }
    }
    print(n);
    return l;
}

int main(){
    cout << lrs("aaaaaaa") << endl;
    cout << lrs("aaabaaaba") << endl;
    cout << lrs("banana") << endl;
    return 0;
}
