#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int dp[2][100];
int lcs(const string& a, const string& b){
    int n = a.size(),m = b.size();
    int c = 0, p = 1;
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            if(i == 0 || j == 0){
                dp[c][j] = 0;
            } else{
                if(a[i-1] == b[j-1]){
                    dp[c][j] = dp[p][j-1]+1;
                } else{
                    dp[c][j] = max(dp[p][j],dp[c][j-1]);
                }
            }
        }
        c ^= 1;
        p ^= 1;
    }
    return dp[(n&1)][m];
}

int main(){
    cout << lcs("ABCDGH","AEDFHR") << endl;
    cout << lcs("AGGTAB","GXTXAYB") << endl;
    return 0;
}
