#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[100][100];
int lcs(const string& a, const string& b){
    int n = a.size(),m = b.size(),val = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i > 0 && j > 0 && a[i-1] == b[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
                val = max(val,dp[i][j]);
            } else{
                dp[i][j] = 0; 
            } 
        }
    }
    return val;
}

int main(){
    cout << lcs("ABCDGH","SABCDFHR") << endl;
    cout << lcs("AGGTAB","GXTXAB") << endl;
    return 0;
}
